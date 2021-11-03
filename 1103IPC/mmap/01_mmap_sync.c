#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>


int main()
{
	// 1.打开映射文件
	int fd = open("mmap_file",O_RDWR);// 映射文件权限 必须和共享映射权限保持一致 否则会报错
	// 2.获取文件大小
	int fsize = lseek(fd,0,SEEK_END);
	// 3.对文件进行共享映射，申请映射内存
	int *ptr = NULL;
	if((ptr = mmap(NULL,fsize,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0)) == MAP_FAILED)
	{
		perror("mmap call failed");
		close(fd);
		exit(0);
	}

	close(fd);// 关闭文件描述符

	ptr[0] = 0x33323130;// 关闭无用描述符 
	// 4.使用完毕，释放映射
	munmap(ptr,fsize);


	return 0;
}
