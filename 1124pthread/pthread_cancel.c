#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

/*线程退出的四种方式:
  1、return
  2、exit
  3、pthread_exit
  4、pthread_cancel*/

void *THREAD_A(void *arg)
{
	printf("THREAD A [0x%x] RETURN...\n",(unsigned int)pthread_self());
	return 0;
}

void *THREAD_B(void *arg)
{
	printf("THREAD B [0x%x] pthread_exit...\n",(unsigned int)pthread_self());
	pthread_exit((void*)1);
}

void *THREAD_C(void *arg)
{
	printf("THREAD C [0x%x] RUNNING...\n",(unsigned int)pthread_self());
	while(1)
		pthread_testcancel();
}


int main()
{
	void* reval = NULL;
	pthread_t tid;
	pthread_create(&tid,NULL,THREAD_A,NULL);
	pthread_join(tid,&reval);
	printf("Master Thread join:Thread A Retrun Value [%ld]\n",(long int)reval);

	pthread_create(&tid,NULL,THREAD_B,NULL);
	pthread_join(tid,&reval);
	printf("Master Thread join:Thread B  pthread_exit code [%ld]\n",(long int)reval);

	pthread_create(&tid,NULL,THREAD_C,NULL);
	sleep(5);

	pthread_cancel(tid);
	pthread_join(tid,&reval);
	printf("Master Thread join:Thread C  cancel code [%ld]\n",(long int)reval);

	exit(0); // 进程退出
	
	return 0;
}
