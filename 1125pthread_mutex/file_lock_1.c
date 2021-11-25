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

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	printf("pro 2 pid %d try set wrlock..\n",getpid());
	fcntl(fd,F_SETLKW,&lock); // 阻塞版上锁
	printf("pro 2 pid %d set wrlock success..\n",getpid());
	lock.l_type = F_UNLCK; // 解锁
	fcntl(fd,F_SETLK,&lock);
	printf("pro 2 pid %d unlock..\n",getpid());

	return 0;
}

