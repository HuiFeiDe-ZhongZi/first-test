//子进程功能重载 mycp

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main()
{
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		printf("parent sleeping...\n");
		while(1)
			sleep(1);
	}
	else if(pid == 0)
	{
		//重载mycp
		//execl("/home/wushuai/1123晚班/Process/mycp","mycp","01.jpg","wu.jpg",NULL);
		//重载火狐浏览器
		execl("/usr/bin/firefox","firefox","www.baidu.com",NULL);

		/*重载之后任何程序都不会起作用*/

		exit(0);
	}
	else
	{
		perror("fork call failed");
		exit(0);
	}

	

	return 0;
}
