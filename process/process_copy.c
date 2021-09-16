#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>


int block_cur(const char * srcfile,int prono)  //源文件 切块数量(进程数量）
{
	int filesize;
	int fd;
	fd = open(srcfile,O_RDONLY);
	filesize  = lseek(fd,0,SEEK_END); //计算文件大小

	if(filesize  % prono == 0)     
		return filesize / prono;   //块大小
	else
		return filesize / prono + 1;
}

int process_create(const char * srcfile, const char * desfile, int prono,int blocksize)
{
	pid_t pid;
	int flags;
	for(flags = 0;flags < prono;flags++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}

	if(pid > 0)
	{
		//僵尸进程回收问题
		pid_t wpid;
		printf("Parent Start..\n");
		while((wpid = wait(NULL))>0)
		{
			printf("parent wait child zpid [%d]\n",wpid);
		}
	}
	else if(pid == 0)
	{
		int pos;
		pos = flags * blocksize; //子进程的拷贝起始位置
		char ssize[1024];
		char spos[1024];
		bzero(spos,sizeof(spos));
		bzero(ssize,sizeof(ssize));
		sprintf(spos,"%d",pos);
		sprintf(ssize,"%d",blocksize);
		execl("/home/wushuai/1123晚班/0906Process/copy","copy",srcfile,desfile,ssize,spos,NULL);
	}
	else
	{
		perror("FORK CALL FAILED");
		exit(0);
	}
	return 0;
}

int main(int argc,char ** argv)
{
	int prono;

	if(argc < 3)
	{
		printf("Please Press SRC DES and ProNo..\n");
		exit(0);
	}
	if(argv[3]==0)
		prono = 5;
	else
		prono = atoi(argv[3]);
	if(prono <= 0 || prono >= 100)
	{
		printf("Enter ProcessNo Error!\n");
		exit(0);
	}

	if((access(argv[1],F_OK))!=0)
	{
		printf("srcfile not exits!\n");
		exit(0);
	}

	int blocksize= block_cur(argv[1],prono);
	printf("blocksize = %d\n",blocksize);
	process_create(argv[1],argv[2],prono,blocksize);

	return 0;
}
	
	

