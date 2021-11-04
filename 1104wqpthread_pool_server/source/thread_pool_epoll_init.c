#include<pthread_pool.h>

int thread_pool_epoll_init(int sockfd)
{
	//1.创建节点
	struct epoll_event tmp_env;
	tmp_env.data.fd = sockfd;
	tmp_env.events = EPOLLIN|EPOLLET; // 设置边缘触发

	//2.创建监听树
	if((epfd = epoll_create(EPOLLSIZE)) == -1) // 创建epoll监听集合[红黑树]
	{
		thread_pool_error("thread_pool_epoll_init > epoll create error",-1,0);
	}

	//3.把节点挂到树上
	if((epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&tmp_env)) == -1) // 把节点放到监听树上 
		thread_pool_error("thread_pool_epoll_init >> epoll ctl error",-1,0);

	return 0;
}
