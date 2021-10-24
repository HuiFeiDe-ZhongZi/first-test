#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>


void SIG_ALARM(int n)
{
	// 空调用
	
}

unsigned int MYSLEEP(unsigned int seconds)
{
	unsigned int reval;
	// 信号屏蔽SIGALRM
	sigset_t nset,oset;
	sigemptyset(&nset);
	sigaddset(&nset,SIGALRM);
	sigprocmask(SIG_SETMASK,&nset,&oset);

	// 信号捕捉设定
	struct sigaction act,oact;
	act.sa_handler = SIG_ALARM;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM,&act,&oact);


	reval = alarm(seconds); // 定时开始，定时结束发送SIGALRM
	sleep(3);
	// pause(); // 挂起，等待信号(唤醒)
	sigsuspend(&oset);

	sigprocmask(SIG_SETMASK,&oset,NULL); // 还原进程原有屏蔽字
	sigaction(SIGALRM,&oact,NULL); // 还原进程原有信号行为
	return reval;
}
int main()
{
	while(1)
	{
		printf("two seconds...\n");
		MYSLEEP(2);
	}


	return 0;
}
