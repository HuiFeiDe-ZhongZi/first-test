#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		printf("parent process pid %d\n",getpid());
		while(1)
			sleep(1);
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
