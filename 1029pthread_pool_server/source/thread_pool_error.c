#include<pthread_pool.h>



void thread_pool_error(const char* strerr,int exitcode,int error)
{
	if(error == 0)
	{
		perror(strerr);
		exit(0); // 进程退出
	}
	else
	{
		printf("%s:%s",strerr,strerror(errno));
		pthread_exit(NULL); // 线程退出 
	}
}

