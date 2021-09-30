#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("hello",O_WRONLY|O_CREAT,0664);

	if(fd < 0)
	{
		printf("open failed.\n");
		exit(1);
	}
	close(fd);
	return 0;
}
