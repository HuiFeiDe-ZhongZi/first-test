#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char ** argv)
{

	int blocksize = atoi(argv[3]);
	int pos = atoi(argv[4]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	int recv_size;
	int sfd,dfd;
	sfd = open(argv[1],O_RDONLY);
	dfd = open(argv[2],O_WRONLY|O_CREAT,0775);
	//文件读写指针位置偏移
	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	recv_size = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,recv_size);
	printf("Copy Child Process [%d] Start [%d] End [%d] Block [%d]\n",getpid(),atoi(argv[4]),atoi(argv[4])+atoi(argv[3]),atoi(argv[3]));
	close(sfd);
	close(dfd);

	return 0;
}
