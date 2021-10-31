#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *t_job(void *arg)
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

	// 查看默认属性中的线程栈地址的大小
	pthread_attr_getstack(&attr,&stackaddr,&stacksize);

	stacksize = 0x100000;
	
	int flags = 0;
	pthread_t tid;
	int err;
	while(1)
	{
		if((stackaddr = (void *)malloc(0x100000)) == NULL)
		{
			perror("malloc call failed");
			exit(0);
		}
		// 向属性 中设置自定义线程栈
		pthread_attr_setstack(&attr,stackaddr,stacksize);
		if((err = pthread_create(&tid,&attr,t_job,NULL))> 0)
		{
			printf("pthread create error:%s\n",strerror(err));
			exit(0);
		}
		printf("flags number:%d\n",++flags);
	}


	pthread_attr_destroy(&attr);
	return 0;
}
