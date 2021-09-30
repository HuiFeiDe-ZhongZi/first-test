#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;

	char buf[20] = {0};
	int i=0;

	while(1)
	{
		//名字
		sprintf(buf,"file%d",i++);

		fd = open(buf,O_WRONLY|O_CREAT,0664);
	}
	if(fd < 0)
	{
		printf("open failed.\n");
		exit(1);
	}
	close(fd);
	return 0;
}
