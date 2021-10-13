#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<pthread.h>

//线程的几种退出方式

void *THREAD_A(void *arg)
{
	printf("THREAD_A [0x%x] RETURE...\n",(unsigned int)pthread_self());
	return (void*)0;
}

void *THREAD_B(void *arg)
{
	printf("THREAD_B [0x%x] EXIT...\n",(unsigned int)pthread_self());
	pthread_exit((void*)1);
}

void *THREAD_C(void *arg)
{
	printf("THREAD_C [0x%x] RUNNING...\n",(unsigned int)pthread_self());
	while(1)
		pthread_testcancel();
}
	

int main()
{
	void *reval = NULL;
	pthread_t tid;
	//线程1
	pthread_create(&tid,NULL,THREAD_A,NULL);
	pthread_join(tid,&reval);
	printf("Master Thread Join:Thread A Return Value [%ld]\n",(long int)reval);
	//线程2
	pthread_create(&tid,NULL,THREAD_B,NULL);
	pthread_join(tid,&reval);
	printf("Master Thread Join:Thread B  Exit Code [%ld]\n",(long int)reval);
	//线程3
	pthread_create(&tid,NULL,THREAD_C,NULL);
	sleep(5);
	
	pthread_cancel(tid);
	pthread_join(tid,&reval);
	printf("Master Thread Join:Thread C Cancel Code [%ld]\n",(long int)reval);

	exit(0);  //进程退出

	return 0;
}
