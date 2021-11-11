#include<SOCKET.h>




//http://img.pconline.com.cn/images/upload/upc/tx/photoblog/1811/23/c5/120664311_1542959809703_mthumb.jpg

typedef struct
{
	char origin_url[4096]; //存储原始url链接
	char domain[1024]; // 域名
	char path[1024]; // 存储路劲
	char fileName[1024]; // 文件名
	char IP[16]; 
	int PORT;
	int HTYPE; // 0:HTTP 1:HTTPS
}url_t;


int spider_net_init(); // 网络初始化,返回socked

int spider_analytical_url(url_t *); // 传入只附带原始地址的url_t,传出解析后的

int spider_connect_webserver(int,url_t); // 完成tcp链接

int spider_create_request(char *,url_t);

int spider_request_response(int webfd,char * request_heat,url_t node);

int spider_get_statuscode(const char*);
