#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>

// max_thread.c 对特定文件进行文件锁设置



int main()
{
	struct flock lock; // 文件锁属性

	int fd = open("02_max_thread.c",O_RDWR);

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0; // 锁整个文件
	printf("pro 2 pid %d try set wrlock..\n",getpid());
	fcntl(fd,F_SETLKW,&lock); // 阻塞版上锁
	printf("pro 2 pid %d set wrlock success...\n",getpid());
	lock.l_type = F_UNLCK; // 解锁
	fcntl(fd,F_SETLK,&lock);
	printf("pro 2 pid %d set unlock\n",getpid());

	return 0;
}
