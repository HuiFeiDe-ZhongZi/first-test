#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>


#define IP_ADDR "192.168.209.131"
#define PORT 8000
#define LISTEN_CODE 128

int main()
{
	int sockfd;
	// 1.sock创建
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket create error");
		exit(-1);
	}
	printf("socket create success socfd = %d\n",sockfd);

	// 2.socket设置绑定 ip port
	struct sockaddr_in sockaddr;
	bzero(&sockaddr,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET,IP_ADDR,&sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(PORT);

	if((bind(sockfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))) == -1)
	{
		perror("bind call failed");
		exit(-1);
	}
	printf("bind successly...\n");

	// 3.监听
	listen(sockfd,LISTEN_CODE);
	printf("start listening...\n");

	// 4.阻塞等待连接
	int clientfd;
	struct sockaddr_in clientaddr;
	char ip[16];
	socklen_t addrsize = sizeof(clientaddr);
	if((clientfd = accept(sockfd,(struct sockaddr *)&clientaddr,&addrsize))>0)
	{
		// 连接成功显示客户端网络信息
		printf("Accept success client ip <%s> client port<%d>\n",inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ip,sizeof(ip)),
				ntohs(clientaddr.sin_port));
	}
	

	return 0;
}
