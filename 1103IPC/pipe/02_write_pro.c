#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


#define MESSAGE "here you are\n"
int main()
{
	int wfd = open("my_fifo",O_RDWR);//只认权限 读写权限凑齐 不会阻塞

	printf("write Process send test MESSAGE..\n");
	write(wfd,MESSAGE,strlen(MESSAGE));
	printf("write Done..\n");
	close(wfd);

	return 0;
}
