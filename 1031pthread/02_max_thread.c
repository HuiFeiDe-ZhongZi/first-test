#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

void *t_job(void *arg)
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
		err = pthread_create(&tid,NULL,t_job,NULL);
		if(err > 0)
		{
			printf("pthread_create error:%s\n",strerror(err));
			exit(0);
		}
		printf("thread number <%d>\n",++flags);
	}

	return 0;
}
