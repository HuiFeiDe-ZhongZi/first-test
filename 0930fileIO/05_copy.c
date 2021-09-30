#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<error.h>

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("filename error.\n");
		exit(1);
	}

	int fd1;
	int fd2;

	fd1 = open(argv[1],O_RDONLY);
	
	if(fd1 < 0)
	{
		perror("open readfile");
		exit(1);
	}
	fd2 = open(argv[2],O_WRONLY|O_CREAT,0664);	

	if(fd2 < 0)
	{
		perror("open writefile");
		exit(1);
	}

	//拷贝
	int n;
	char buf[20] = {0};

	while((n = read(fd1,buf,5)) != 0)
	{
		write(fd2,buf,n);
	}
	return 0;
}
