#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

void temp(int a)
{
	// 如果根据信号数量决定wait调用次数，如果信号被丢弃，则漏回收
	// 将sigchld 作为触发机制，每当信号产生，尽可能回收多次
	while(waitpid(-1,NULL,WNOHANG)>0)
	{
		printf("回收成功！！！\n");
	}
}
int main()
{
	// 父进程进行捕捉设定
	struct sigaction newact,oldact;
	newact.sa_handler = temp;
	newact.sa_flags = 0;
	sigemptyset(&newact.sa_mask);
	sigaction(SIGCHLD,&newact,&oldact);

	// 多进程模型
	pid_t pid;
	int i = 0;
	for(i;i<10;i++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}

	if(pid > 0)
	{
		while(1){
			printf("i love you\n");
			sleep(1);
		}
	}
	else if(pid == 0)
	{
		// printf("hellow haizi %d.... :\n",getpid());
		// sleep(i);
		exit(i);
	}
	else
	{
		perror("fork call failed");
		exit(1);
	}


	return 0;
}

