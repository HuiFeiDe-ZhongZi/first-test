#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main()
{
	int sockfd;

	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket create error...");
		exit(-1);
	}

	struct sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(INADDR_ANY)
	inet_pton(AF_INET,"192.168.209.131",&sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(8000);

	if((bind(sockfd,(struct sockaddr *)&sockaddr,sizeof(sockaddr))) == -1)
	{
		perror("bind call failed");
		exit(-1);
	}

	listen(sockfd,128);

	int clientfd;
	struct sockaddr_in clientaddr;
	socklen_t addrsize = sizeof(clientaddr);
	char ip[16];
	bzero(ip,sizeof(ip));
	if((clientfd = accept(sockfd,(struct sockaddr*)&clientaddr,&addrsize))>0)
	{
		printf("Accept success client ip <%s> client port <%d>\n",
				inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ip,16),ntohs(clientaddr.sin_port));
	}

	return 0;
}

