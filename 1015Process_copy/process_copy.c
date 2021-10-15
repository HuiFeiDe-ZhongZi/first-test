#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>


int block_cur(const char *srcfile,int prono)
{
	int filesize;
	int fd;
	fd = open(srcfile,O_RDONLY);
	filesize = lseek(fd,0,SEEK_END);//计算文件大小
	if(filesize % prono == 0)
		return filesize / prono;
	else
		return filesize / prono +1;
}

int process_create(const char *srcfile,const char *desfile,int prono,int blocksize)
{
	pid_t pid;
	int flags;
	for(flags = 0;flags<prono;flags++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid > 0)
	{
		//僵尸回收问题
		pid_t wpid;
		printf("parent start..\n");
		while((wpid = wait(NULL))>0)
		{
			printf("parent wait child zpid [%d]\n",wpid);
		}

	}
	else if(pid == 0)
	{
		int pos;
		pos = flags * blocksize;
		char bsize[1024];
		char bpos[1024];
		bzero(bsize,sizeof(bsize));
		bzero(bpos,sizeof(bpos));
		sprintf(bsize,"%d",blocksize);
		sprintf(bpos,"%d",pos);
		execl("/home/wushuai/1123晚班/Process/copy/copy","copy",srcfile,desfile,bsize,bpos,NULL);
	}
	else
	{
		perror("fork call failed");
		exit(0);
	}
	return 0;
}



int main(int argc,char **argv)
{
	int prono;
	//参数校验
	if(argc < 3)
	{
		printf("pleade press src des and proNo.. \n");
		exit(0);
	}

	if(argv[3] == 0)
		prono = 5;
	else
		prono = atoi(argv[3]);

	if(prono <= 0 || prono >= 100)
	{
		printf("Enter Process num error!\n");
		exit(0);
	}

	if((access(argv[1],F_OK)) != 0)
	{
		printf("srcfile not exits!\n");
		exit(0);
	}

	int blocksize = block_cur(argv[1],prono);
	process_create(argv[1],argv[2],prono,blocksize);
	
	
	return 0;
}
