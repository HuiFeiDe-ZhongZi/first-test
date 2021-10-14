#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int ticket=100;

pthread_mutex_t lock; //全局互斥锁

void *tjob(void *arg)
{
	int tmp;
	while(ticket)
	{
		if(ticket<=0)
		{
			break;
		}
		pthread_mutex_lock(&lock);
		//tmp = code;
		sleep(0.5);
		printf("thread [0x%x] ++code=%d\n",(unsigned int)pthread_self(),ticket);
		ticket--;
		//code = tmp;
		pthread_mutex_unlock(&lock);
	}
	return (void*)0;
}

int main()
{
	pthread_t tid[2];
	//互斥锁初始化
	pthread_mutex_init(&lock,NULL);
	for(int i=0;i<2;i++)
	{
		pthread_create(&tid[i],NULL,&tjob,NULL);
		sleep(0.1);
	}
	while(1)
		sleep(1);
	pthread_mutex_destroy(&lock);

	return 0;
}


