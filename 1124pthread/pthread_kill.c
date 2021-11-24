#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<pthread.h>

/*线程tid获取:pthread_self
 线程回收:pthrea_join(tid,&reval)
 线程退出:pthread_exit((void*)4)
 线程分离:pthread_detach(tid);
 线程取消:pthread_cancel(tid);  配合pthread_testcancel使用
 线程间信号传递:pthread_kill(tid,signal)*/

void sig_job(int n)
{
	printf("thread <0x%x> Signal success...\n",(unsigned int)pthread_self());
}
void *tjob(void * arg)
{
	struct sigaction nact,oact;
	nact.sa_handler = sig_job;
	nact.sa_flags = 0;
	sigemptyset(&nact.sa_mask);
	sigaction(SIGQUIT,&nact,&oact);

	while(1)
		sleep(1);
}

int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,tjob,NULL);

	while(1)
	{
		sleep(2);
		pthread_kill(tid,SIGQUIT);
	}

	return 0;
}
