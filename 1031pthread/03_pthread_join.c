#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *t_job(void *arg)
{
	// 普通线程
	pthread_t tid;
	pthread_detach(pthread_self());  // 设置为分离线程
	tid = pthread_self();
	printf("thread tid <0x%x>\n",(unsigned int)tid);
	
	pthread_exit((void*)-2);


}

int main()
{
	// 主控线程任务区
	pthread_t tid;
	pthread_create(&tid,NULL,t_job,NULL);

	sleep(0);
	void *reval;
	int err;
	if((err = pthread_join(tid,&reval))>0)
	{
		printf("pthread_join failed <%s>\n",strerror(err));
		exit(0);
	}
	printf("master thread join success,thread exitcode [%ld]\n",(long int)reval);

	
	return 0;
}
