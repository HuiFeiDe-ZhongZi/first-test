#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>


// 定义共享资源

typedef struct
{
	pthread_mutex_t lock;
	int code;
}shared_t;

#define NUM 5000

int main()
{
	// 通过mmap将资源映射共享给多进程
	
	int fd;
	fd = open("process_lock",O_RDWR|O_CREAT,0664);
	ftruncate(fd,sizeof(shared_t)); // 文件扩展

	shared_t * sp = NULL;
	sp = mmap(NULL,sizeof(shared_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); 

	// 1.定义锁属性
	pthread_mutexattr_t attr;
	// 2.初始化锁属性
	pthread_mutexattr_init(&attr);
	// 3.设置锁属性
	pthread_mutexattr_setpshared(&attr,PTHREAD_PROCESS_SHARED);
	// 4.初始化互斥锁
	pthread_mutex_init(&sp->lock,&attr);

	sp->code = 0;
	// 父子进程模型
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		for(int i = 0;i < NUM; i++)
		{
			pthread_mutex_lock(&sp->lock);
			printf("parent pro <%d>  ++code <%d>\n",getpid(),++(sp->code));
			pthread_mutex_unlock(&sp->lock);
		}
	}
	else if(pid == 0)
	{
		for(int i = 0;i < NUM; i++)
		{
			pthread_mutex_lock(&sp->lock);
			printf("child pro <%d>  ++code <%d>\n",getpid(),++(sp->code));
			pthread_mutex_unlock(&sp->lock);
		}
		exit(0);
		
	}
	else
	{
		perror("fork call failed");
		exit(0);
	}
	
	pid_t wpid;
	wpid = wait(NULL);
	
	pthread_mutexattr_destroy(&attr);
	pthread_mutex_destroy(&sp->lock);
	munmap(sp,sizeof(shared_t));

	return 0;
}
