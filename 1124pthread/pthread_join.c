#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *tjob(void * arg)
{
	// 普通线程
	pthread_t tid;
	
	pthread_exit((void*)-2);
}

int main()
{
	int code = 4096;
	pthread_t tid;
	pthread_create(&tid,NULL,tjob,(void*)&code);

	void *reval;
	pthread_join(tid,&reval);
	printf("master thread join success,thread exitcode [%ld]\n",(long int)reval);


	return 0;
}
