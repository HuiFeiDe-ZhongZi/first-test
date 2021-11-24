#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

// 多线程实现资源访问互斥
// 排他锁使用时需要注意上锁位置，对共享资源进行读写访问时需要上锁保护

int code;
#define NUM 5000

pthread_mutex_t lock;  // 全局互斥锁

void *thread_job(void *arg)
{
	for(int i = 0; i < NUM;i++)
	{
		pthread_mutex_lock(&lock);
		printf("pthread [0x%x] ++code=%d\n",(unsigned int)pthread_self(),++code);
		pthread_mutex_unlock(&lock);
	}

	return (void*)0;
}

int main()
{
	pthread_t tid[2];
	
	pthread_mutex_init(&lock,NULL);

	for(int i =0; i<2;i++)
	{
		pthread_create(&tid[i],NULL,thread_job,NULL);
	}
	while(1)
		sleep(1);
	pthread_mutex_destroy(&lock);


	return 0;
}
