#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *t_job(void *arg)
{
	while(1)
		pthread_testcancel();
	
}

int main()
{
	pthread_t tid;

	pthread_create(&tid,NULL,t_job,NULL);
	
	sleep(5);

	pthread_cancel(tid);
	while(1)
		sleep(1);

	return 0;
}
