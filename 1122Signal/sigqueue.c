#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

// 完成父子进程间通信
/* 确认信号 SIGUSR1 SIGUSR2
 父进程发送SIGUSR1,子进程捕捉SIGUSR1
 子进程发送SIGUSR2,父进程捕捉SIGUSR2

 第一次发送信号 父进程
 信号捕捉问题？
  保证捕捉完成，才能触发信号
  利用继承特性和屏蔽字
 否则，父进程杀死子进程，子进程终止父进程*/

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
	pid_t pid;

	// 为了子进程第一次不被杀死 必须让子进程一开始屏蔽SIGUSR1
	sigset_t nset,oset;
	sigemptyset(&nset);
	sigaddset(&nset,SIGUSR1);
	sigprocmask(SIG_SETMASK,&nset,&oset);

	pid = fork();
	if(pid > 0)
	{
		// 父进程捕捉设定，发送第一次信号之前做即可
		struct sigaction nact,oact;
		nact.sa_sigaction = parent_sig;
		nact.sa_flags = SA_SIGINFO;
		sigemptyset(&nact.sa_mask);
		sigaction(SIGUSR2,&nact,&oact);
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
		struct sigaction nact,oact;
		nact.sa_sigaction = child_sig;
		nact.sa_flags = SA_SIGINFO;
		sigemptyset(&nact.sa_mask);
		sigaction(SIGUSR1,&nact,&oact);
		// 解除对SIGUSR1的屏蔽
		sigprocmask(SIG_SETMASK,&nact.sa_mask,NULL);
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
