#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int *array; // 全局整形数组指针 指向动态数组空间 用于进度条
pthread_mutex_t lock; // 全局互斥锁

// 错误处理
void sys_err(const char* str)
{
	perror(str);
	exit(0);
}

struct cp
{
	char *src_add; // 拷贝起始指针位置
	char *des_add; 
	int thread_num; // 当前是第几个线程
	int block_size; // 块大小
};

// 线程工作
void *thread_job(void *arg)
{
	struct cp *ptr = (struct cp*)arg;

	int block = ptr->block_size;
	char *src_add = ptr->src_add;
	char *des_add = ptr->des_add;
	
	while(block--)
	{
		*des_add++ = *src_add++;
		pthread_mutex_lock(&lock); // 上锁
		array[ptr->thread_num]++; 
		pthread_mutex_unlock(&lock); // 解锁

		usleep(1000);
	}
	
	free(ptr);
}

int main(int argc,char *argv[])
{
	int fdsrc,fddes;
	int src_size = 0;  // 源文件大小
	int thread_num; // 线程数量

	if(argc < 3)
		sys_err("src and des no exit");
	// 打开源文件 获取源文件大小
	if((fdsrc = open(argv[1],O_RDONLY)) < 0)
		sys_err("open srcfile failed");
	if((src_size = lseek(fdsrc,0,SEEK_END)) < 0)
		sys_err("lseef failed");


	// 创建目标文件
	if((fddes = open(argv[2],O_RDWR|O_CREAT,0777)) < 0)
		sys_err("open dest failed");
	if((lseek(fddes,src_size-1,SEEK_SET)) < 0)
		sys_err("lseek failed");
	if(write(fddes,"\0",1) < 0)
		sys_err("write create des failed");

	// 线程数量
	if(argc == 3)
		thread_num = 5;
	else
		thread_num = atoi(argv[3]);
	
	// 动态线程数
	array = calloc(thread_num,sizeof(int));

	// mmap 映射文件
	char *src_add,*des_add; // 映射内存指针
	src_add = mmap(NULL,src_size,PROT_READ,MAP_PRIVATE,fdsrc,0);
	des_add = mmap(NULL,src_size,PROT_WRITE,MAP_SHARED,fddes,0);

	// 修改线程属性 系统自动回收
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	// 互斥锁初始化
	pthread_mutex_init(&lock,NULL);

	// 线程创建
	int block_size;
	struct cp *ptr; // 定义结构体变量
	int err; // 错误接收
	pthread_t tid;
	int i;
	for(i = 0; i < thread_num; i++)
	{
		if(i == (thread_num - 1))
			block_size = src_size/thread_num + src_size%thread_num; // 最后一部分冗余交给最后一个线程处理
		else
			block_size = src_size/thread_num; // 正常块大小

		// 分配一块内存
		ptr = calloc(sizeof(struct cp),1);
		ptr->src_add = src_add + i * (src_size/thread_num);
		ptr->des_add = des_add + i * (src_size/thread_num);
		ptr->block_size = block_size;
		ptr->thread_num = i;
		
		if ((err = pthread_create(&tid,&attr,thread_job,(void*)ptr)) > 0) // 多线程创建
		{
			printf("call failed error: %s\n",strerror(err));
		}
	}

	
	// 进度条处理
	int sum; 
	double per;
	do{
		sum = 0;
		for(i = 0; i < thread_num; i++)
		{
			sum+=array[i];
		}
		per = sum*100.0/src_size;

		char buffer[100] = ""; 
		char buffer1[50];
		char buffer2[]="===========================";
		sprintf(buffer1,"%.2lf%%",per);
		sprintf(buffer,"%s%s\n",buffer2,buffer1);

		write(STDOUT_FILENO,buffer,sizeof(buffer)); // 行刷新输出
		usleep(10000);
	}while(sum < src_size);

	// 空间释放
	free(array);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&lock);
	munmap(src_add,src_size);
	munmap(des_add,src_size);
	
	return 0;
}
