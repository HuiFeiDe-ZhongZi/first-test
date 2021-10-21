#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		pid_t wpid;
		printf("parent process pid %d\n",getpid());
		wpid = wait(NULL);//阻塞等待回收 
		if(wpid > 0)
			printf("parent wait zombie successly zpid [%d]\n",wpid);
		
	}
	else if(pid == 0)
	{
		printf("child process pid %d\n",getpid());
		printf("child process exit...\n");
		exit(0);
	}
	else
	{
		perror("fork call failed...");
		exit(0);
	}

	return 0;
}
