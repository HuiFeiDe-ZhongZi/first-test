#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MSG "try again\n"
#define TIMEOUT "time out\n"
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

	int i;
	for(i = 0;i<5;i++)
	{
		n = read(fd,buf,5);

		if(n>=0)break;
		if(errno !=EAGAIN)
		{
			perror("read /dev/tyy");
			exit(1);
		}
		sleep(1);
		write(STDOUT_FILENO,MSG,strlen(MSG));
	}

	if(i ==5)
	{
		write(STDOUT_FILENO,TIMEOUT,strlen(TIMEOUT));
	}
	else
	{
		write(STDOUT_FILENO,buf,n);
	}
	close(fd);


	return 0;
}
