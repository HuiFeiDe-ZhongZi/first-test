#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	pid_t pid;
	pid = fork();

	if(pid>0)
	{
		printf("parent create success...\n");
	}
	else if(pid == 0)
	{
		printf("child create success...\n");
	}
	else
	{
		perror("fork call fail...");
		exit(0);
	}

	while(1)
		sleep(1);



	return 0;
}

