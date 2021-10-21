#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();
	int status;

	if(pid > 0)
	{
		pid_t wpid;
		printf("parent process pid %d\n",getpid());
		wpid = wait(&status);//阻塞等待回收 
		if(wpid > 0)
		{
			printf("parent wait zombie successly zpid [%d]\n",wpid);
			if(WIFEXITED(status))//效验子进程是否正常退出
			{
				printf("Wait success chilt pro exitcode %d\n",WEXITSTATUS(status));//正常退出 获取退出码
			}
			if(WIFSIGNALED(status))//效验子进程是否被信号杀死
			{
				printf("wait success kill child signo %d\n",WTERMSIG(status));//获取被信号杀死的退出码
			}
		}
		
	}
	else if(pid == 0)
	{
		printf("child process pid %d\n",getpid());
		sleep(20);
		printf("child process exit...\n");
		exit(20);
	}
	else
	{
		perror("fork call failed...");
		exit(0);
	}
	while(1);
	return 0;
}
