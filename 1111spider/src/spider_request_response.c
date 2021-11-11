#include<SPIDER.h>


int spider_request_response(int webfd,char *request_heat,url_t node)
{
	printf("---------\n");
	char recv_buffer[8192];
	char response_buffer[4096];
	char *pos; // 找空行
	int rsize;
	int statuscode;
	int fd;
	bzero(recv_buffer,sizeof(recv_buffer));
	bzero(response_buffer,sizeof(response_buffer));
	// 向web服务器发送http请求
	send(webfd,request_heat,strlen(request_heat),0);
	printf("[5] 发送请求头成功...\n");
	// 第一次接收响应(获取响应头和部分响应体)
	rsize = recv(webfd,recv_buffer,sizeof(response_buffer),0);
	// 提取响应头
	if((pos = strstr(recv_buffer,"\r\n\r\n")) == NULL)
	{
		printf("spider_request_response recv response_head error,strstr call failed\n");
		close(webfd);
		return -1;
	}
	snprintf(response_buffer,pos - recv_buffer + 4,"%s",recv_buffer);
	printf("[6] 获取响应头成功 r e s p o n s e_h e a d:\n%s",response_buffer);
	// 获取判断响应码 如果为200 OK则接收，否则此次下载失败

	if((statuscode = spider_get_statuscode(response_buffer)) == 200)
	{
		printf("[] 服务器的响应码 %d\n",statuscode);
		// 200
		// 创建资源文件
		fd = open(node.fileName,O_RDWR|O_CREAT,0775); // 图像需要执行权限
		// 将第一次读取的响应内容部分响应体保存
		write(fd,pos+4,rsize - (pos - recv_buffer + 4)); // 写入部分响应体
		// 循环接收内容并保存 (下载完毕)
		while((rsize = recv(webfd,recv_buffer,sizeof(recv_buffer),0)) > 0)
		{
			write(fd,recv_buffer,rsize);
		}
		printf("[7] 下载成功，本次交互完毕...\n");
		close(fd);
	}
	else
	{
		printf("[] 服务器的响应码 %d\n",statuscode);
		close(webfd);
		return -1;
	}
	close(webfd);

	return 0;
}
