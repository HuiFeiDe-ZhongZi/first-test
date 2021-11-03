#include<pthread_pool.h>


int main(int argc ,char **argv)
{


	if(argc < 4)
	{
		printf("Please presss thread_max and thread_min and queue_max!\n");
		return 0;
	}

	thread_pool_t *pool = NULL;
	int max = atoi(argv[1]);
	int min = atoi(argv[2]);
	int qmax = atoi(argv[3]);

	int serverfd;

	serverfd = thread_pool_net_init();
	printf("服务器网路初始化成功...\n");
	thread_pool_epoll_init(serverfd);
	printf("服务器EPOLL初始化成功...\n");

	pool = thread_pool_create(max,min,qmax);
	printf("服务器线程池创建初始化成功...\n");

	printf("服务器开始业务监听...\n");
	thread_pool_epoll_listen(epfd,pool,serverfd);

	return 0;
}
