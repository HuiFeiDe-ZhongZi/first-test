#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>


// 线程的几种退出方式
void *thread_a(void *arg)
{
	printf("thread_a [0x%x] return ...\n",(unsigned int)pthread_self());
	return (void*)0;
}

void *thread_b(void *arg)
{
	printf("thread_b [0x%x] exit ...\n",(unsigned int)pthread_self());
	pthread_exit((void*)1);
}

void *thread_c(void *arg)
{
	printf("thread_c [0x%x] return ...\n",(unsigned int)pthread_self());
	while(1)
		pthread_testcancel();
}

int main()
{
	// 获取主线程id
	pthread_t wid;
	wid = pthread_self();
	printf("thread_c [0x%x] return ...\n",(unsigned int)pthread_self());

	void *reval = NULL;
	pthread_t tid;
	pthread_create(&tid,NULL,thread_a,NULL);
	pthread_join(tid,&reval);
	printf("master thread join; thread_a return value [%ld]\n",(long int)reval);
	
	pthread_create(&tid,NULL,thread_b,NULL);
	pthread_join(tid,&reval);
	printf("master thread join; thread_b exit code [%ld]\n",(long int)reval);

	pthread_create(&tid,NULL,thread_c,NULL);
	sleep(5);

	pthread_cancel(tid);
	pthread_join(tid,&reval);
	printf("master thread join; thread_c cancel code [%ld]\n",(long int)reval);
	
	exit(0);

	return 0;
}

