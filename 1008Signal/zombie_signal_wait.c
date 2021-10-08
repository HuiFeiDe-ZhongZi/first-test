#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void sig_wait(int n)
{
	//如果根据信号数量决定wait调用次数,如果信号被丢弃，则漏回收
	//将SIGCHLD作为触发机制，每当信号产生，尽可能回收更多的僵尸进程

	//方法一 会产生漏回收
	//pid_t wpid;
	//wpid = wait(NULL);
	//printf("Parent SigWait Zombie Pro [%d]\n",wpid);

	//方法二 不会产生漏回收
	pid_t wpid;
	while((wpid = waitpid(-1,NULL,WNOHANG))>0)//-1回收任意子系统 NULL 死后不验尸 
	{
		printf("Parent Sigwait Success zpid %d\n",wpid);
	}

}

int main()
{
	struct sigaction act,oact;
	act.sa_handler = sig_wait;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);//初始化
	sigaction(SIGCHLD,&act,&oact);//便于回滚进程原有信号处理行为

	//多进程模型
	pid_t pid;
	int i=0;
	for(i;i<10;i++)
	{
		pid  = fork();
		if(pid==0)
			break;
	}
	if(pid >0)
	{
		//父进程任务
		int size;
		char buffer[1024];
		bzero(buffer,sizeof(buffer));
		printf("Parent READ STDIN...[%d] \n",getpid());
		if(-1== read(STDIN_FILENO,buffer,sizeof(buffer)))
		{
			perror("read call failed");
			exit(0);
		}
	}
	else if(pid == 0)
	{	
		sleep(5);
			exit(1);
	}
	else
	{
		perror("FORK CALL FAILED");
		exit(0);
	} 
	return 0;
}


