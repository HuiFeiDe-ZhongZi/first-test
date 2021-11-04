#include<pthread_pool.h>

int thread_pool_epoll_listen(int epfd , thread_pool_t * p,int sockfd) //网络IO事件监听，辨别就绪并添加任务 Produc
{
	// sockfd实则为serverfd,用于判断就绪
	int readycode;
	struct epoll_event ready_array[EPOLLSIZE];
	// 进行监听
	int i;
	busines_t bs;
	
	printf("thread_pool_epoll_listen...\n");
	// 开始监听
	while(p->thread_shutdown)  // 监听随线程池持续，以线程池开关为条件
	{
		printf("-------------\n");
		if((readycode = epoll_wait(epfd,ready_array,EPOLLSIZE,-1)) > 0)
		{
			printf("======================\n");
			i = 0;
			while(readycode)
			{
				printf("qingqiu qingqiu qingqiu\n");
				if(ready_array[i].data.fd == sockfd)
				{
					printf("服务器:辨别连接请求,即将投递连接业务...\n");
					bs.BUSINES_ADDR = BUSINES_ACCEPT;
					bs.BUSINES_ARG = (void*)&(ready_array[i].data.fd);
					// 添加业务A(链接) 注意上锁
					thread_pool_add_busines(p,bs);
				}
				else
				{
					printf("服务器:辨别连接请求,即将投递处理业务...\n");
					bs.BUSINES_ADDR = BUSINES_RESPONSE;
					bs.BUSINES_ARG = (void*)&(ready_array[i].data.fd);
					// 添加业务A(链接) 注意上锁
					thread_pool_add_busines(p,bs);
				}
				++i;
				--readycode;
			} 
		}
		else if(readycode == -1)
		{
			thread_pool_error("thread_pool_epoll_listen >> epoll_wait error",-1,0);
		}
	}
	return 0;
}
