#include<pthread_pool.h>

int thread_pool_epoll_listen(int epfd , thread_pool_t * p,int sockfd) //网络IO事件监听，辨别就绪并添加任务 Produc
{
	// sockfd实则为serverfd,用于判断就绪
	struct epoll_event ready_array[EPOLLSIZE];
	// 进行监听
	
	int readycode;
	int i;
	while(p->thread_shutdown)
	{
		if((readycode = epoll_wait(epfd,ready_array,EPOLLSIZE,-1)) > 0)
		{
			i = 0;
			while(readycode)
			{
				if(ready_array[i].data.fd == sockfd)
				{
					// 添加业务A(链接) 注意上锁
				}
				else
				{
					// 添加业务B(处理) 注意上锁
				}
				++i;
				--ready_array;
			}
		}
		else if(readycode == -1)
		{
			thread_pool_error("thread_pool_epoll_listen >> epoll_wait error",-1,0);
		}
	}
	return 0;
}
