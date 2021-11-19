#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int create_daemon()
{
	pid_t pid;
	pid = fork();

	if(pid>0)
	{
		exit(0);
	}
	else if(pid == 0)
	{
		setsid();
		chdir("./");
		umask(0);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		// 向日志写入系统时间
		char tbuffer[1500];
		time_t t;
		int fd = open("syslog.log",O_RDWR|O_CREAT,0664);
		while(1)
		{
			t = time(NULL);
			bzero(tbuffer,sizeof(tbuffer));
			ctime_r(&t,tbuffer);
			write(fd,tbuffer,strlen(tbuffer));
			sleep(3);
		}
		// 守护进程退出处理
		close(fd);
	}
	else
	{
		perror("fork call failed");
		exit(0);
	}
	return 0;
}



int main()
{
	create_daemon();
	return 0;
}
