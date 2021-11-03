#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MESSAGE "hi yanger ,can you hear me..\n"

int main()
{
	pid_t pid;
	// 管道创建要在fork前完成，避免重复创建
	int fds[2]; // 读写端创建
	pipe(fds); //创建管道

	pid = fork();
	// 使用管道时要确定通信方向:父写子读(确定方向后，将不用的fds关闭)
	if(pid > 0)
	{
		close(fds[0]);
		printf("parent pro pid [%d] send message\n",getpid());
		write(fds[1],MESSAGE,strlen(MESSAGE));
		close(fds[1]); // 用完将此描述符关闭
		printf("parent done.\n");
		while(1)
			sleep(1);
	}
	else if(pid == 0)
	{
		char buffer[100];
		close(fds[1]);
		printf("child pro pid [%d] recv message\n",getpid());
		read(fds[0],buffer,sizeof(buffer));
		close(fds[0]); // 用完将此描述符关闭
		printf("child read message [%s].\n",buffer);
		while(1)
			sleep(1);

	}
	else
	{
		perror("fork call failed..");
		exit(0);
	}

	return 0;
}
