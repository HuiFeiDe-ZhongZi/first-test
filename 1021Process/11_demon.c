#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int create_daemon()
{
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		exit(0);
	}
	else if(pid == 0)
	{
		setsid();
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		chdir("./");
		umask(0);
		// 创建日文件 把输出错误 抛到此文件中
		int fd = open("error.log",O_RDWR|O_CREAT|O_APPEND,0664);
		dup2(fd,STDERR_FILENO);
		//向日志内写入系统时间
		time_t t;
		char timebuf[1500];
		bzero(timebuf,sizeof(timebuf));
		while(1)
		{
			t = time(NULL);
			bzero(timebuf,1500);
			ctime_r(&t,timebuf);
			write(fd,timebuf,strlen(timebuf));
			bzero(timebuf,sizeof(timebuf));
			sleep(3);
		}
		// 守护进程退出处理
		close(fd);
	}
	else
	{
		perror("fork call failed..");
		exit(0);
	}
}


int main()
{
	create_daemon();


	return 0;
}
