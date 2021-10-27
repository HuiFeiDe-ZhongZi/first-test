#include<SOCKET.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>
#include<poll.h>

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

	char buffer[1500];
	int rsize;
	socklen_t addrsize;
	int len;

	int readycode; // 就绪数量
	struct pollfd clientfd_array[1023];

	// 初始化数组
	for(int i = 0;i < 1023; i++)
	{
		clientfd_array[i].fd = -1;
	}
	
	clientfd_array[0].fd =serverfd;
	clientfd_array[0].events = POLLIN;

	printf("select server version 1.0 Accepting...\n");

	while(1)
	{
		readycode = poll(clientfd_array,1023,-1);

		while(readycode)
		{
			if(clientfd_array[0].revents == POLLIN)
			{
				addrsize = sizeof(clientaddr);
				// 完成tcp连接
				if((clientfd = accept(serverfd,(struct sockaddr*)&clientaddr,&addrsize)) > 0)
				{
					printf("accept sucess\n");
					// 将新的sock存入数组
					for(int i = 1;i < 1023; i++)
					{
						if(clientfd_array[i].fd == -1)
						{
							clientfd_array[i].fd = clientfd;
							clientfd_array[i].events = POLLIN;
							break;
						}
					}
				}
			}
			else
			{
				// 循环查找就绪的clientfd
				for(int i = 1;i < 1024; i++)
				{
					if(clientfd_array[i].fd!=-1)
					{
						if(clientfd_array[i].revents == POLLIN)
						{
							// 因为单进程限制，只能帮其处理一次业务，不能占用处理
							rsize = recv(clientfd_array[i].fd,buffer,sizeof(buffer),0);
							len = 0;

							while(rsize > len)
							{
								buffer[len] = toupper(buffer[len]);
								len++;
							}

							send(clientfd_array[i].fd,buffer,rsize,0);
							bzero(buffer,1500);
							printf("Respons OK...\n");
							if(rsize == 0)
							{
								close(clientfd_array[i].fd);
								clientfd_array[i].fd = -1;
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
