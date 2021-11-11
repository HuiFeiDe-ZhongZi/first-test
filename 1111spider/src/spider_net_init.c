#include<SPIDER.h>

int spider_net_init()
{
	int webfd;
	struct sockaddr_in myaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8000);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	webfd = SOCKET(AF_INET,SOCK_STREAM,0);
	BIND(webfd,(struct sockaddr *)&myaddr,sizeof(myaddr));

	printf("[1] 网络初始化成功，socketfd [%d]\n",webfd);
	return webfd;
}
