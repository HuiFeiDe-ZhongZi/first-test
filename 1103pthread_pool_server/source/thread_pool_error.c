#include<pthread_pool.h>



void thread_pool_error(const char* strerr,int exitcode,int err)
{
	if(errno == 0)
	{
		perror(strerr);
		exit(0); // 进程退出
	}
	else
	{
		printf("%s:%s",strerr,strerror(errno));
		pthread_exit((void*)&exitcode); // 线程退出 
	}
}

