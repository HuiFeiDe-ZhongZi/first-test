#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *t_job(void *arg)
{

	pthread_t tid;
	tid = pthread_self();
	printf("common thread tid <0x%x>\n",(unsigned int)tid);
	int code;
	code = *(int *)arg;
	printf("thread arg <%d>\n",code);
	while(1)
		sleep(1);

	// 以下两种做法都可以退出当前线程，并返回线程退出码
	pthread_exit((void*)5);
	// return (void*)5;
}

int main()
{
	// 主线程任务区
	pthread_t tid;
	tid = pthread_self();
	printf("master thread tid <0x%x>\n",(unsigned int)tid);

	int code = 4096;
	int err = pthread_create(&tid,NULL,t_job,(void *)&code);
	while(1)
		sleep(1);

	return 0;
}
