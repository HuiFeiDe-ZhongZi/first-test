#include<pthread_pool.h>

void * BUSINES_RESPONSE(void * arg) // 业务处理与相应
{
	int clientfd = *(int*) arg;
	int rsize;
	char buffer[BUFSIZE];
	bzero(buffer,BUFSIZE);
	int flag;
	// 读取请求，采用非阻塞模式 (recv函数可以通过参数设置为非阻塞读)
	
	//while((rsize = recv(clientfd,buffer,BUFSIZE,0))>0)  // 阻塞去接收 测试扩容缩减
	while((rsize = recv(clientfd,buffer,BUFSIZE,MSG_DONTWAIT))>0)
	{
		flag = 0;
		while(rsize > flag)
		{
			buffer[flag] = toupper(buffer[flag]);
			flag++;
		}
		// 读端关闭，写端向管道写数据，内核会通过SIGPIPE信号杀死写端进程
		// 普遍意义(socket适用)
		// 客户端关闭，服务端写数据会被系统杀死问题，处理方案
		// 1.服务端屏蔽或忽略SIGPIPE信号 2.send使用MSG_NOSIGNAL关键字，忽略信号，避免杀死
		send(clientfd,buffer,rsize,MSG_NOSIGNAL);
	}
	if(rsize == 0)
	{
		if((epoll_ctl(epfd,EPOLL_CTL_DEL,clientfd,NULL))==-1)
		{
			thread_pool_error("BUSINES_RESPONSE >> epoll_ctl error",-1,0);
		}
		close(clientfd);
	}
	else if(rsize == -1)
	{
		// 判断是否因非阻塞返回-1
		if(errno == EAGAIN)
			printf("BUSINESS_RESPONSE >> RECV NONBLOCK RETURN -1\n");
		else
			thread_pool_error("BUSINES_RESPONSE >> recv error",-1,0);
	}

	return NULL;
}
	

