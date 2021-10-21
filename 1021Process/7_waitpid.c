#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


//非阻塞轮询回收

void sys_jobs()
{
	printf("exes system task...\n");
}

int main()
{
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		pid_t wpid;
		printf("parent process pid %d\n",getpid());
	
		while((wpid = waitpid(-1,NULL,WNOHANG)) != -1)
		{
			printf("parent check zombie...\n");
			if(wpid > 0)
				printf("parent wait zombie successly zpid [%d]\n",wpid);
			else
			{
				sys_jobs();
				sleep(1);
			}
		}
	}
	else if(pid == 0)
	{
		printf("child process pid %d\n",getpid());
		sleep(10);
		printf("child process exit...\n");
		exit(0);
	}
	else
	{
		perror("fork call failed...");
		exit(0);
	}
	while(1);
	return 0;
}
