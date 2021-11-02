#include<pthread_pool.h>



void * BUSINES_ACCEPT(void * arg) // TCP连接业务
{
	int clientfd;
	struct epoll_event tmp_env;
	struct sockaddr_in clientaddr;
	socklen_t addrsize = sizeof(clientaddr);
	// 业务参数为serverfd
	int serverfd = *(int *)arg;
	char ip[16];
	bzero(ip,sizeof(ip));

	pthread_mutex_lock(&accept_lock); // 上锁
	if((clientfd = ACCEPT(serverfd,(struct sockaddr*)&clientaddr,&addrsize))>0)
	{
		printf("accept success client <%s> client port <%d>\n",
			               inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ip,sizeof(ip)),ntohs(clientaddr.sin_port));
	}	
	pthread_mutex_unlock(&accept_lock);// 解锁

	// 添加监听
	tmp_env.data.fd = clientfd;
	tmp_env.events = EPOLLIN;
	// epoll内部自定义实现了锁保护机制
	if((epoll_ctl(epfd,EPOLL_CTL_ADD,clientfd,&tmp_env)) == -1)
	{
		thread_poll_error("BUSINESS_ACCEPT >> epoll_ctl error",-1,0);
	}

	return NULL;
}

