#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>


typedef struct 
{
	int g_id;
	char g_name[20];
	int g_price;
}g_info_t;

int main()
{
	g_info_t *ptr = NULL;
	int fd = open("mmap_file",O_RDWR);
	
	//扩展空文件，扩展为结构体大小
	ftruncate(fd,sizeof(g_info_t));

	ptr = mmap(NULL,sizeof(g_info_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	close(fd);

	//定时刷新映射内存数据，这个更改会同步给其他端
	ptr->g_id = 0;
	bzero(ptr->g_name,20);
	while(1)
	{
		++(ptr->g_id);
		sprintf(ptr->g_name,"PUBG %d",ptr->g_id);
		ptr->g_price = 200;
		sleep(1);
	}

	munmap(ptr,sizeof(g_info_t));
	return 0;
}
