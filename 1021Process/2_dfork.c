#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>



int main()
{
	int pflags = 0;
	pid_t pid;

	for(pflags;pflags<10;pflags++)
	{
		pid = fork();
		if(pid == 0)//fork只有父进程可以执行，子进程不允许
			break;
	}
	if(pid>0)
	{
		printf("parent pid %d running...\n",getpid());
		while(1)
			sleep(1);
	}
	else if(pid == 0)    // 不同进程执行不同的任务
	{
		if(pflags == 3)
		{
			printf("child pid %d pflags %d 正吃饭...\n",getpid(),pflags);
			while(1)
				sleep(1);
		}
		if(pflags == 6)
		{
			printf("child pid %d pflags %d 正在打游戏...\n",getpid(),pflags);
			while(1)
				sleep(1);
		}

		printf("child pid %d pflags %d 正在睡觉...\n",getpid(),pflags);
		while(1)
			sleep(1);	
	}
	else
	{
		//错误处理
		perror("fork call failed...");
		exit(0);
	}

	return 0;
}

