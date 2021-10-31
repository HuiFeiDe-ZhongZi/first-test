#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>

void sig_job(int n)
{
	printf("thread <0x%x> signal..\n",(unsigned int)pthread_self());
}

void * t_job(void * arg)
{
	struct sigaction act,oact;
	act.sa_handler = sig_job;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGQUIT,&act,&oact);

	while(1)
		sleep(1);
	
}

int main()
{
	pthread_t tid;

	pthread_create(&tid,NULL,t_job,NULL);
	
	while(1)
	{
		sleep(2);
		pthread_kill(tid,SIGQUIT);
	}

	return 0;
}
