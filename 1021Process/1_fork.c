#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	pid_t pid;
	pid = fork();

	if(pid>0)
	{
		//父进程工作区
		printf("parent create success...\n");
		printf("parent ppid [%d]..\n",getppid());
		printf("parent pid [%d] running...\n",getpid());
	}
	else if(pid == 0)
	{
		//子进程工作区
		printf("child create success...\n");
		printf("child ppid [%d]..\n",getppid());
		printf("child pid [%d] running...\n",getpid());
		exit(0);  //子进程任务完成后，结束进程，不允许踏出工作区
	}
	else
	{
		//错误处理
		perror("fork call fail...");
		exit(0);
	}

	while(1)
		sleep(1);



	return 0;
}

