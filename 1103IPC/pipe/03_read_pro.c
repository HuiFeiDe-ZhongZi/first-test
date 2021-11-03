#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
	char buffer[100];
	bzero(buffer,sizeof(buffer));
	int rfd = open("my_fifo",O_RDONLY);

	printf("read Process recv test MESSAGE..\n");
	read(rfd,buffer,sizeof(buffer));
	printf("read message :%s\n",buffer);
	close(rfd);

	return 0;
}
