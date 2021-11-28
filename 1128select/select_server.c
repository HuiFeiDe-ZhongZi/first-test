#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/select.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<ctype.h>
#include<sys/socket.h>

int main()
{
	int sockfd,clientfd;
	sockfd =socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in serveraddr,clientaddr;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	inet_pton(AF_INET,"192.168.209.131",&serveraddr.sin_addr.s_addr);
	serveraddr.sin_port = htons(8000);

	bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

	listen(sockfd,128);

	socklen_t addrsize;
	int rsize;
	char buffer[1500];
	int maxfd; //最大socket
	int readycode; //最大就绪数量
	int client_array[1023]; // 就绪数组
	fd_set set,oset;
	maxfd = sockfd;
	// 初始化数组
	for(int i = 0; i < 1023;i++)
	{
		client_array[i] = -1;
	}
	FD_ZERO(&set);
	FD_SET(sockfd,&set);

	while(1)
	{
		oset = set;
		readycode = select(maxfd+1,&oset,NULL,NULL,NULL);
		
		while(readycode)
		{
			if(FD_ISSET(sockfd,&oset))
			{
				addrsize = sizeof(clientaddr);
				if((clientfd = accept(sockfd,(struct sockaddr*)&clientaddr,&addrsize))>0)
				{
					printf("accept success\n");
					if(maxfd < clientfd)
						maxfd = clientfd;
					//将新的sock存入数组
					for(int i = 0;i<1023;i++)
					{
						if(client_array[i] == -1)
						{
							client_array[i] = clientfd;
							break;
						}
					}
					// 设置对sock的监听
					FD_SET(clientfd,&set);
					FD_CLR(sockfd,&oset);
				}
			}
			else
			{
				for(int i = 0;i<1023;i++)
				{
					if(client_array[i] != -1)
					{
						if(FD_ISSET(client_array[i],&oset))
						{
							rsize = recv(client_array[i],buffer,sizeof(buffer),0);
							int len = 0;

							while(rsize > len)
							{
								buffer[len] = toupper(buffer[len]);
								len++;
							}

							send(client_array[i],buffer,sizeof(buffer),0);
							bzero(buffer,sizeof(buffer));
							printf("Respons OK\n");

							if(rsize == 0)
							{
								FD_CLR(client_array[i],&set);
								close(client_array[i]);
								client_array[i] = -1;
								break;
							}

						}

					}
				}
			}
			--readycode;
		}

	}

	close(sockfd);
	close(clientfd);
	return 0;
}


