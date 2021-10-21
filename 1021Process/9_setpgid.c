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
		printf("parent pid [%d] gid [%d]  running...\n",getpid(),getpgrp());
		setpgid(getpid(),getpid());
		printf("parent pid [%d] gid [%d]  running...\n",getpid(),getpgrp());
	}
	else if(pid == 0)
	{
		//子进程工作区
		printf("child pid [%d] gid [%d] running...\n",getpid(),getpgrp());
		setpgid(getpid(),getpid());
		printf("child pid [%d] gid [%d] running...\n",getpid(),getpgrp());

		while(1);
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

