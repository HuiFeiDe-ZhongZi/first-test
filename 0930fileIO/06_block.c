#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<error.h>

int main()
{
	char buf[10]={0};
	
	int n;

	n=read(STDIN_FILENO,buf,5);

	if(n<0)
	{
		perror("read tty.\n");
	}

	printf("%s\n",buf);



	return 0;
}
