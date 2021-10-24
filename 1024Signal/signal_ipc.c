#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

void parent_sig(int n,siginfo_t *info,void *arg)
{
	printf("parent code [%d]\n",info->si_int);
	union sigval val;
	val.sival_int = ++(info->si_int);
	sigqueue(getpid()+1,SIGUSR1,val);
	usleep(50000);
}

void child_sig(int n,siginfo_t *info,void *arg)
{
	printf("child code [%d]\n",info->si_int);
	union sigval val;
	val.sival_int = ++(info->si_int);
	sigqueue(getppid(),SIGUSR2,val);
	usleep(50000);
}
int main()
{
	// 父进程对SIGUSR1进行信号屏蔽(将屏蔽字继承给子进程)
	sigset_t nset,oset;
	sigemptyset(&nset);
	sigaddset(&nset,SIGUSR1);
	sigprocmask(SIG_SETMASK,&nset,&oset);
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		// 父进程捕捉设定，发送第一次信号之前做即可
		struct sigaction act,oact;
		act.sa_sigaction = parent_sig;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR2,&act,&oact);
		// 发送第一次信号并携带数据
		union sigval val;
		val.sival_int = 1;
		sigqueue(getpid()+1,SIGUSR1,val);
		while(1)
			sleep(1);

	}
	else if(pid == 0)
	{
		// 继承了屏蔽，默认对SIGUSR1信号屏蔽
		// 完成SIGUSR1信号的捕捉设定
		struct sigaction act,oact;
		act.sa_sigaction = child_sig;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1,&act,&oact);
		// 解除对SIGUSR1的屏蔽
		sigprocmask(SIG_SETMASK,&act.sa_mask,NULL);
		while(1)
			sleep(1);

	}
	else
	{
		perror("fork call failed");
		exit(0);
	}


	return 0;
}
