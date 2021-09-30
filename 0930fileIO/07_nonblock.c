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
	int fd;

	fd = open("/dev/tty",O_RDONLY|O_NONBLOCK);

	if(fd <0)
	{
		perror("read failed.\n");
		exit(1);
	}

	tryagain:
	n = read(fd,buf,5);

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
	close(fd);

	return 0;
}
