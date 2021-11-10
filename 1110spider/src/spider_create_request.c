#include<SPIDER.h>



int spider_create_request(char * request_head, url_t node)
{
	bzero(request_head,4096);

	sprintf(request_head,"GET %s HTTP/1.1\r\n"\
						"Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp;q=0.8\r\n"\
						"User-Agent:Mozilla/5.0 (X11; Linux x86_64)\r\n"\
						"Host:%s\r\n"\
						"Connection:close\r\n\r\n",node.origin_url,node.domain);
	printf("[4]  创建请求头成功  r e q u e s t__h e a d:\n%s",request_head);

	return 0;
}
