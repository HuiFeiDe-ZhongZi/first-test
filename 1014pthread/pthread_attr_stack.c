#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

//0x1000 = 4096 
//0x10000 = 65536
//0x100000 = 1M

void *tjob(void *arg)
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
	//查看默认属性中的线程栈地址及大小
	pthread_attr_getstack(&attr,&stackaddr,&stacksize);
	//设置栈大小
	stacksize = 0x100000;
	pthread_t tid;
	int flags =0;
	int err;

	while(1)
	{
		if((stackaddr = (void*)malloc(0x100000)) == NULL) //设置线程栈地址
		{
			perror("malloc call failed");
			exit(0);
		}
		pthread_attr_setstack(&attr,stackaddr,stacksize);//设置属性中的线程地址及线程大小
		if((err = pthread_create(&tid,&attr,tjob,NULL))>0)
		{
			printf("pthread create error%s\n",strerror(err));
			exit(0);
		}
		printf("thread number %d\n",++flags);

	}


	//销毁状态
	pthread_attr_destroy(&attr);


	return 0;
}
