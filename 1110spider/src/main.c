#include<SPIDER.h>

int main()
{
	int webfd;
	url_t node;
	char request_head[4096];
	webfd = spider_net_init();
	const char* str = "http://img.pconline.com.cn/images/upload/upc/tx/photoblog/1811/23/c5/120664311_1542959809703_mthumb.jpg";

	strcpy(node.origin_url,str);

	spider_analytical_url(&node);

	spider_connect_webserver(webfd,node);

	spider_create_request(request_head,node);
	return 0;
}

