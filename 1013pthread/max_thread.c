#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>


void *job(void *arg)
{
	while(1)
		sleep(1);
}


int main()
{
	pthread_t tid;
	int flags = 0;
	int err;
	while(1)
	{
		if((err = pthread_create(&tid,NULL,job,NULL))>0)
		{
			printf("thread_create error:%s\n",strerror(err));
			exit(0);
		}
		printf("thread number<%d>\n",++flags);
	}
	return 0;
}

