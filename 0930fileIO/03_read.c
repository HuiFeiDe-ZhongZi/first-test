#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("hello",O_RDWR|O_CREAT,0664);

	if(fd < 0)
	{
		printf("open failed.\n");
		exit(1);
	}
	
	char buf[20] = {0};
	
	int n;
	n = read(fd,buf,5);

	if(n<0)
	{
		printf("read failed.\n");
		exit(1);
	}

	printf("%s\n",buf);
	close(fd);
	return 0;
}
