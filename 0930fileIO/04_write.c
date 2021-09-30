#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("hello",O_RDWR|O_CREAT|O_APPEND,0664);

	if(fd < 0)
	{
		printf("open failed.\n");
		exit(1);
	}

	char buf[40] = "hahahahah";
	
	int n = write(fd,buf,5);

	if(n < 0)
	{
		printf("write failed.\n");
		exit(1);
	}


	close(fd);
	return 0;
}
