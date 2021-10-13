#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *tjob(void *arg)
{
	//信号捕捉
	

}

int main()
{
	pthread_t tid;

	pthread_create(&tid,NULL,tjob,NULL);
	sleep(5);
	pthread_cancel(tid);//线程取消
	while(1)
		sleep(1);
	
	return 0;
}
