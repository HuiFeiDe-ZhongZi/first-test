#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int code;
pthread_rwlock_t rwlock;

void *write_job(void *arg)
{
	while(1)
	{
		pthread_rwlock_wrlock(&rwlock);
		printf("write thread <0x%x>  ++code <%d>\n",(unsigned int)pthread_self(),++code);
		pthread_rwlock_unlock(&rwlock);
		usleep(100000);
	}
	
}

void *read_job(void *arg)
{
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		printf("read thread <0x%x>  code <%d>\n",(unsigned int)pthread_self(),code);
		pthread_rwlock_unlock(&rwlock);
		usleep(100000);
	}
}
int main()
{

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	pthread_t tid[8];
	int i = 0;
	pthread_rwlock_init(&rwlock,NULL);
	for(i;i<3;i++)
	{
		pthread_create(&tid[i],&attr,write_job,NULL);
	}
	for(i;i<8;i++)
	{
		
		pthread_create(&tid[i],&attr,read_job,NULL);
	}

	//while(i--)
	//{
	//	pthread_join(tid[i],NULL);
	//}

	while(1)
		sleep(1);
	pthread_rwlock_destroy(&rwlock);
	pthread_attr_destroy(&attr);

	return 0;
}
