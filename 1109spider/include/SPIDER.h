#include<SOCKET.h>





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

int spider_connect_webserver(int); // 完成tcp链接
