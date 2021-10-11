#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>


void *tjob(void *arg)
{
	int code;
	code = *(int*)arg;
	printf("thread arg <%d>...\n",code);
	while(1);
		sleep(1);
}

int main()
{
	//主线程任务区
	pthread_t tid;

	int code = 4096;
	pthread_create(&tid,NULL,tjob,(void*)&code);//传出线程编号 线程属性 线程工作 线程工作传参
	while(1)
		sleep(1);

	return 0;
}


