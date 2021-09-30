#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MSG "try again\n"

int main()
{
	char buf[10]={0};
	int n;
	int flag;

	flag = fcntl(STDIN_FILENO,F_GETFL);

	if(flag <0)
	{
		perror("fcntl\n");
		exit(1);
	}
	
	flag |= O_NONBLOCK;
	fcntl(STDIN_FILENO,F_SETFL,flag);

	tryagain:
	n = read(STDIN_FILENO,buf,5);

	if(n<0)
	{
		if(errno == EAGAIN)
		{
			sleep(2);
			write(STDOUT_FILENO,MSG,strlen(MSG));
			goto tryagain;
		}
		perror("read /dev/tty");
		exit(1);
	}

	write(STDOUT_FILENO,buf,n);
	

	return 0;
}
