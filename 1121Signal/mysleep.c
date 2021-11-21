#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

void SIG_ALARM(int n)
{
	// 空调用
}

unsigned int MySleep(unsigned int seconds)
{
	unsigned int reval;
	// 信号捕捉设定
	struct sigaction nset,oset;
	nset.sa_handler = SIG_ALARM;
	nset.sa_flags = 0;
	sigemptyset(&nset.sa_mask);
	sigaction(SIGALRM,&nset,&oset);

	reval = alarm(seconds); // 定时开始，定时结束发送SIGALARM
	pause(); // 挂起，等待信号(唤醒)

	sigaction(SIGALRM,&oset,NULL);
	return reval;
}

int main()
{

	while(1)
	{
		printf("two seconds...\n");
		MySleep(2);
	}

	return 0;
}
