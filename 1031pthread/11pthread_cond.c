#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

// 工作条件
int work_cond;  // 0白班 1夜班
// 条件变量
pthread_cond_t day_shift;
pthread_cond_t night_shift;

pthread_mutex_t lock; // 互斥锁

void *day(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(work_cond)
		{
			// 夜班挂起 
			pthread_cond_wait(&day_shift,&lock);
		}
		printf("thread <0x%x> is on the day shift...\n",(unsigned int)pthread_self());
		work_cond = 1;
		usleep(100000);
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&night_shift);
	}
}

void *night(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(!work_cond)
		{
			// 白班挂起
			pthread_cond_wait(&night_shift,&lock);
		}

		printf("thread <0x%x> is on the night shift...\n",(unsigned int)pthread_self());
		work_cond = 0;
		usleep(100000);
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&day_shift);
	}
}
int main()
{
	pthread_t tid[2];

	// 准备
	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&day_shift,NULL);
	pthread_cond_init(&night_shift,NULL);

	pthread_create(&tid[0],NULL,day,NULL);
	pthread_create(&tid[1],NULL,night,NULL);

	int i = 2;
	while(i--)
	{
		pthread_join(tid[i],NULL);
	}

	return 0;
}
