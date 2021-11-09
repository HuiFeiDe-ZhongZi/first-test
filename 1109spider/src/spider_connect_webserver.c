#include<SPIDER.h>

int spider_connect_webserver(int webfd,url_t node)
{
	struct sockaddr_in webaddr;
	bzero(webaddr,sizeof(webaddr));
	webaddr.sin_family = AF_INET;
	webaddr.sin_port = htons(node.PORT);
	inet_pton(AF_INET,node.IP,&webaddr.sin_addr.s_addr);

	if((CONNECT(webfd,(struct sockaddr*)&webaddr,sizeof(webaddr))) == 0)
	{
		printf(" 连接 [%s] web服务器成功...\n",node.domain);
	}
	return 0;
}
