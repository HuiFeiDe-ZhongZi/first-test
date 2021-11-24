#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *jos(void *arg)
{
	
}

int main()
{

	int detachstate;
	pthread_attr_t attr;
	// 初始化线程属性
	pthread_attr_init(&attr);

	// 查看默认属性中的线程退出状态
	pthread_attr_getdetachstate(&attr,&detachstate);
	if(detachstate == PTHREAD_CREATE_JOINABLE)
	{
		printf("默认线程退出状态:joinable\n");
	}
	else
	{
		printf("默认线程退出状态:detached\n");
	}

	// 设置线程属性
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	//再次获取线程属性
	pthread_attr_getdetachstate(&attr,&detachstate);
	if(detachstate == PTHREAD_CREATE_JOINABLE)
	{
		printf("默认线程退出状态:joinable\n");
	}
	else
	{
		printf("默认线程退出状态:detached\n");
	}
	
	pthread_t tid;
	pthread_create(&tid,&attr,jos,NULL);
	int err;
	if((err = pthread_join(tid,NULL))>0)
	{
		printf("pthread_join error:%s\n",strerror(err));
	}
	// 销毁线程属性
	pthread_attr_destroy(&attr);
	return 0;
}

