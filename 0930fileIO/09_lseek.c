#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main()
{
	int fd;

	fd=open("hello",O_RDWR);
	if(fd <0)
	{
		perror("open failed\n");
		exit(1);
	}

	int n = lseek(fd,10,SEEK_END);
	
	if(n <0)
	{
		perror("lseek failed\n");
		exit(1);
	}
	
	write(fd,"fksjf",5);

	printf("%d\n",n);


	return 0;
}

