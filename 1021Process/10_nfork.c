#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

// 孤儿进程

int main()
{
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		printf("parent exit ...\n");
		exit(0);
	}
	else if(pid == 0)
	{
		while(1)
		{
			printf("child runing....\n");
			sleep(1);
		}
	}
	else
	{
		perror("fork call failed.");
		exit(0);
	}

	return 0;
}
