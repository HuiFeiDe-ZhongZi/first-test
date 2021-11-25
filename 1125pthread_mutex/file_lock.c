#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


// pthread_process.c
int main()
{
	struct flock lock;

	int fd = open("pthread_process.c",O_RDWR);
	
	// 获取文件的锁属性,查看是否已被锁?
	fcntl(fd,F_GETLK,&lock);

	//if(lock.l_type == F_UNLCK)
	//{
		printf("pro 1 pid %d maxthread lock type is unlock..\n",getpid());
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 0;
		lock.l_len = 0;
		fcntl(fd,F_SETLK,&lock); // 非阻塞版上锁
		printf("pro 1 pid %d set wrlock success..\n",getpid());
		sleep(10);
		lock.l_type = F_UNLCK; // 解锁
		fcntl(fd,F_SETLK,&lock);
	//}
	//else
	//{
	//	printf("set lock error!!!\n");
	//}

	return 0;
}

