#include<SOCKET.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/epoll.h>

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
	struct epoll_event ready_array[5000]; //就绪集合 传出

	// 创建epoll监听集合
	int epfd = epoll_create(5000);

	struct epoll_event tmp_env;
	tmp_env.data.fd = serverfd;
	tmp_env.events = EPOLLIN;

	epoll_ctl(epfd,EPOLL_CTL_ADD,serverfd,&tmp_env);

	printf("epoll server version 1.0 Accepting...\n");
	int i;
	while(1)
	{
		readycode = epoll_wait(epfd,ready_array,5000,-1);
		i = 0;
		while(readycode)
		{
			if(ready_array[i].data.fd == serverfd)
			{
				addrsize = sizeof(clientaddr);
				// 完成tcp连接
				if((clientfd = accept(serverfd,(struct sockaddr*)&clientaddr,&addrsize)) > 0)
				{
					printf("accept sucess\n");
					// 将新节点添加到树中
					tmp_env.data.fd = clientfd;
					tmp_env.events = EPOLLIN;
					epoll_ctl(epfd,EPOLL_CTL_ADD,clientfd,&tmp_env);
				}
			}
			else
			{
				rsize = recv(ready_array[i].data.fd,buffer,sizeof(buffer),0);
				len = 0;

				while(rsize > len)
				{
					buffer[len] = toupper(buffer[len]);
					len++;
				}

				send(ready_array[i].data.fd,buffer,rsize,0);
				bzero(buffer,1500);
				printf("Respons OK...\n");
				if(rsize == 0)
				{
					close(ready_array[i].data.fd);
					epoll_ctl(epfd,EPOLL_CTL_DEL,ready_array[i].data.fd,NULL);
				}
			}
			++i;
			--readycode;
		}
	}


	close(serverfd);
	close(clientfd);
	return 0;
}
