#include<SOCKET.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/select.h>

int main()
{
	// 网络初始化 网络信息结构体
	struct sockaddr_in myaddr,clientaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(8000);


	int serverfd,clientfd;

	serverfd = SOCKET(AF_INET,SOCK_STREAM,0);
	BIND(serverfd,(struct sockaddr *)&myaddr,sizeof(myaddr));
	LISTEN(serverfd,128);
	printf("server version 1.0 Accepting...\n");
	char buffer[1500];
	int rsize;
	socklen_t addrsize;
	int len;
	pid_t pid;

	int maxfd; // 最大socket
	int readycode; // 就绪数量
	int clientfd_array[1023];
	fd_set set,oset;
	maxfd = serverfd;
	// 初始化数组
	for(int i = 0;i < 1023; i++)
	{
		clientfd_array[i] = -1;
	}
	FD_ZERO(&set);
	FD_SET(serverfd,&set);

	printf("select server version 1.0 Accepting...\n");

	while(1)
	{
		oset = set; // 传入传出分离
		readycode = select(maxfd + 1,&oset,NULL,NULL,NULL);

		while(readycode)
		{
			if(FD_ISSET(serverfd,&oset))
			{
				addrsize = sizeof(clientaddr);
				// 完成tcp连接
				if((clientfd = accept(serverfd,(struct sockaddr*)&clientaddr,&addrsize)) > 0)
				{
					printf("accept sucess\n");
					if(maxfd < clientfd)
						maxfd = clientfd;
					// 将新的sock存入数组
					for(int i = 0;i < 1023; i++)
					{
						if(clientfd_array[i] == -1)
						{
							clientfd_array[i] = clientfd;
							break;
						}
					}
					// 设置对clientfd的监听
					FD_SET(clientfd,&set);
					FD_CLR(serverfd,&oset);
				}
			}
			else
			{
				// 循环查找就绪的clientfd
				for(int i = 0;i < 1023; i++)
				{
					if(clientfd_array[i]!=-1)
					{
						if(FD_ISSET(clientfd_array[i],&oset))
						{
							// 因为单进程限制，只能帮其处理一次业务，不能占用处理
							rsize = recv(clientfd_array[i],buffer,sizeof(buffer),0);
							len = 0;

							while(rsize > len)
							{
								buffer[len] = toupper(buffer[len]);
								len++;
							}

							send(clientfd_array[i],buffer,rsize,0);
							bzero(buffer,1500);
							printf("Respons OK...\n");
							if(rsize == 0)
							{
								FD_CLR(clientfd_array[i],&set);
								close(clientfd_array[i]);
								clientfd_array[i] = -1;
								break;
							}
						}
					}
				}
			}
			--readycode;
		}
	}
	

	close(serverfd);
	close(clientfd);
	return 0;
}
