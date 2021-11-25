#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

/* 3个线程写 5个线程读*/
/*读共享 写独占 读写互斥
 读写锁可以提高全局资源的利用率*/



int code;
pthread_rwlock_t rwlock;


void *write_thread(void *arg)
{
	while(1)
	{
		pthread_rwlock_wrlock(&rwlock);
		printf("write_thread <0x%x> ++code <%d>\n",(unsigned int)pthread_self(),++code);
		pthread_rwlock_unlock(&rwlock);
		usleep(100000);
	}
}

void *read_thread(void *arg)
{
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		printf("read_thread <0x%x> code <%d>\n",(unsigned int)pthread_self(),code);
		pthread_rwlock_unlock(&rwlock);
		usleep(100000);
	}
}

int main()
{
	pthread_t tid[8];

	pthread_rwlock_init(&rwlock,NULL);
	int i = 0;
	for(i; i<3;i++)
	{
		pthread_create(&tid[i],NULL,write_thread,NULL);
	}
	for(i;i<8;i++)
	{
		pthread_create(&tid[i],NULL,read_thread,NULL);
	}

	while(i--)
	{
		pthread_join(tid[i],NULL);
	}
	
	pthread_rwlock_destroy(&rwlock);

	return 0;
}
