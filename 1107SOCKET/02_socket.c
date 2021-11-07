#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define IP_ADDR "192.168.209.131"

int main()
{
	// sock创建
	int sockfd;

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)  // 注意前面的等于号
	{
		perror("socket create error");
		exit(-1);
	}

	struct sockaddr_in sockaddr;
	bzero(&sockaddr,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET,IP_ADDR,&sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(8000);

	//if((bind(sockfd,(struct sockaddr *)&sockaddr,sizeof(sockaddr))) == -1) // 用自定义网络信息替换socket中默认网路信息
	if(bind(sockfd,(struct sockaddr *)&sockaddr,sizeof(sockaddr))== -1)
	{
		perror("bind call failed");
		exit(-1);
	}

	listen(sockfd,128);
	// 阻塞等待连接
	struct sockaddr_in clientaddr;
	int clientfd;
	socklen_t addrsize = sizeof(clientaddr);
	char ip[16];
	bzero(ip,sizeof(ip));
	if((clientfd = accept(sockfd,(struct sockaddr *)&clientaddr,&addrsize))>0)
	{
		printf("accept success client <%s> client port <%d>\n",
				inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ip,sizeof(ip)),ntohs(clientaddr.sin_port));
	}


	return 0;

}
