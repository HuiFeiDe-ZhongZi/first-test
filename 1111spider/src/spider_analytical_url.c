#include<SPIDER.h>



int spider_analytical_url(url_t *node)
{
	// 初始化除origin_url的所有成员
	bzero(node->domain,sizeof(node->domain));
	bzero(node->path,sizeof(node->path));
	bzero(node->fileName,sizeof(node->fileName));
	bzero(node->IP,sizeof(node->IP));

	int i = 0;
	int flag = 0;
	int start; // 偏移起始位置
	int fsize = 0;

	char * array[] = {"http://","https://",NULL};

	// 获取http类型
	
	if(strncmp(node->origin_url,array[0],strlen(array[0])) == 0)
	{
		node->HTYPE = 0;
		node->PORT = 80;
		start = strlen(array[0]);
	}
	else
	{
		node->HTYPE = 1;
		node->PORT = 443;
		start = strlen(array[1]);
	}
	
	//获取网站域名
	for(i = start; node->origin_url[i]!='/' && node->origin_url[i]!='\0'; i++)
	{
		node->domain[flag] = node->origin_url[i];
		flag++;
	}
	flag = 0;
	//获取文件名长度
	for(i = strlen(node->origin_url);node->origin_url[i]!='/';i--,fsize++);
	//获取文件名
	for(i = strlen(node->origin_url)-fsize+1; node->origin_url[i]!='\0';i++)
	{
		node->fileName[flag] = node->origin_url[i];
		flag++;
	}

	flag = 0;
	//获取文件路径
	for(i = start + strlen(node->domain); i < strlen(node->origin_url) - fsize + 1; i++)
	{
		node->path[flag] = node->origin_url[i];
		flag++;
	}

	//获取公网ip
	struct hostent * ent = NULL;
	if((ent = gethostbyname(node->domain)) != NULL)
	{
		inet_ntop(AF_INET,ent->h_addr_list[0],node->IP,16);
	}

	printf("[2] [%s] [%s] [%s] [%s] [%s] [%d]\n",node->origin_url,node->domain,node->path,node->fileName,node->IP,node->PORT);
	return 0;
}
