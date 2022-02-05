#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<error.h>



int main()
{
	int rsize;
	char buffer[8192];
	int flags;
	fcntl(STDIN_FILENO,F_GETFL,&flags);
	flags|=O_NONBLOCK;
	fcntl(STDIN_FILENO,F_GETFL,flags);


	while((rsize = read(STDIN_FILENO,buffer,sizeof(buffer))) == -1)
	{
		if(error == EAGAIN)
		{
			printf("try again...\n");
			usleep(10000);
		}
		printf("-------------------\n");
	}
	return 0;
}
