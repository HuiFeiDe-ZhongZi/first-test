#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MESSAGE "jdakljdlaksjdklasjdkl"

int main()
{
	int wfd=open("my_fifo",O_WRONLY);

	printf("write Process Send test Message ..\n");
	write(wfd,MESSAGE,strlen(MESSAGE));
	printf("write Done..\n");
	close(wfd);


	return 0;
}
