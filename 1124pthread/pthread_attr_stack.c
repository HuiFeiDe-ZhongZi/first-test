#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

// 0x1000 = 4096 0x10000 = 65536 0x100000 = 1M

void *jobs(void *arg)
{
	while(1)
		sleep(1);
}

int main()
{
	void *stackaddr;
	size_t stacksize;

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	// 查看默认属性中的线程栈地址及大小
	pthread_attr_getstack(&attr,&stackaddr,&stacksize);
	//printf("ATTR DFL stackaddr [%p] stacksize [%ld]\n",stackaddr,stacksize);

	//stackaddr = malloc(0x100000);
	stacksize = 0x100000;

	// 向属性中设置自定义线程栈
	//pthread_attr_setstack(&attr,stackaddr,stacksize);

	pthread_t tid;
	int err;
	int flags = 0;
	while(1)
	{
		if((stackaddr = malloc(0x100000))==NULL)
		{
			perror("malloc call failed");
			exit(0);
		}
		pthread_attr_setstack(&attr,stackaddr,stacksize);
		if((err = pthread_create(&tid,&attr,jobs,NULL))>0)
		{
			printf("pthread create error:%s\n",strerror(err));
			exit(0);
		}
		printf("thread number %d\n",++flags);
	}
	pthread_attr_destroy(&attr);

	return 0;
} 
