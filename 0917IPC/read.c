#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
	char buffer[1024];
	bzero(buffer,sizeof(buffer));
	int rsize;
	int rfd=open("my_fifo",O_RDONLY);

	rsize=read(rfd,buffer,sizeof(buffer));
	printf("Read Process Recv Message success ..\n");
	printf("Read Done..[%s]\n",buffer);
	close(rfd);


	return 0;
}
