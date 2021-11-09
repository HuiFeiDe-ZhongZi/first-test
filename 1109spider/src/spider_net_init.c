#include<SPIDER.h>

int spider_net_init()
{
	int webfd;
	struct sockaddr_in myaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8000);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	BIND(webfd,(struct sockaddr *)&myaddr,sizeof(myaddr));
	webfd = SOCKET(AF_INET,SOCK_STREAM,0);

	printf("网络初始化成功，socketfd [%d]",webfd);
	return webfd;
}
