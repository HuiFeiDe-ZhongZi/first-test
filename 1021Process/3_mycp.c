#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main(int argc,char **argv)
{
	if(argc < 3)
	{
		printf("mycp error:Pleade press srcFile and Desfile...\n");
		exit(0);
	}

	//检测源文件是否存在
	if((access(argv[1],F_OK))!=0)
	{
		printf("mycp error:srcfile does not exits..\n");
		exit(0);
	}

	char buffer[8192];
	bzero(buffer,sizeof(buffer));
	int sfd,dfd;
	int recv_size;
	sfd = open(argv[1],O_RDONLY);
	dfd = open(argv[2],O_WRONLY|O_CREAT,0775);
	while((recv_size = read(sfd,buffer,sizeof(buffer)))>0)
	{
		write(dfd,buffer,recv_size);
		bzero(buffer,sizeof(buffer));
	}

	close(sfd);
	close(dfd);


	return 0;
}

