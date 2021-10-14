#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *tjob(void *arg)
{
	while(1)
		sleep(1);
}

int main()
{
	int detachstate;
	pthread_attr_t attr;
	//初始化线程属性
	pthread_attr_init(&attr);

	//查看默认属性中的线程退出状态
	pthread_attr_getdetachstate(&attr,&detachstate);
	if(detachstate == PTHREAD_CREATE_JOINABLE)
		printf("DFL:JOINABLE\n");  //回收态
	else
		printf("DFL:DETACHED\n"); //分离态

	//将线程属性中的退出状态更改
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	//再次获取显示结果
	pthread_attr_getdetachstate(&attr,&detachstate);
	if(detachstate == PTHREAD_CREATE_JOINABLE)
		printf("SET:JOINABLE\n");
	else
		printf("SET:DETACHED\n");

	pthread_t tid;
	pthread_create(&tid,&attr,tjob,NULL);
	int err;
	if((err = pthread_join(tid,NULL))>0)
	{
		printf("join failes...\n");
	}
	
	//销毁线程
	pthread_attr_destroy(&attr);

	return 0;
}
