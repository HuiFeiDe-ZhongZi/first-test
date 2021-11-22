#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

/*利用信号技术，优化僵尸回收(信号触发回收)
  使主进程专心干自己的事，不用担心儿子死后 回收问题 交给捕捉函数去处理 减小了一部分询问、轮询查看的开销
  且为了解决 同一时间多次触发回收捕捉函数 信号产生之后要用while 进行多次回收*/

/*本程序进行回收子进程 还有一点问题 
 就是进程进行阻塞任务，信号抵达处理，会将正在执行阻塞任务的函数强制中断
 */


void task(int n)
{
	// 如果根据信号数量决定wait调用次数，如果信号被丢弃，则漏回收
	// 将SIGCHLD作为触发机制，信号产生，回收多次
	pid_t wpid;
	//wpid = wait(NULL);
	//printf("Parent sigwait Zombie Pro [%d]\n",wpid);
	
	while((wpid = waitpid(-1,NULL,WNOHANG))>0)
	{
		printf("Parent Sigwait success zpid %d \n",wpid);
	}
}

int main()
{
	// 多进程模型
	
	// 捕捉设定
	struct sigaction nact,oact;
	nact.sa_handler = task;
	nact.sa_flags = 0;
	sigemptyset(&nact.sa_mask);
	sigaction(SIGCHLD,&nact,&oact);

	pid_t pid;
	int i=0;
	for(i; i < 10; i++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}

	if(pid > 0)
	{
		// 父进程任务
		while(1)
		{
			printf("parent %d Running>>>>>>\n",getpid());
			sleep(1);
		}
	}
	else if(pid == 0)
	{
		//printf("child %d exit>>>>>>\n",getpid());
		//sleep(i);
		exit(i);

	}
	else
	{
		perror("fork call failed");
		exit(0);
	}

	return 0;
}
