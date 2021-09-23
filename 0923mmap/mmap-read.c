#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


typedef struct 
{
	int G_ID;
	char G_NAME[20];
	int G_PRICE;
}g_info_t;

int main()
{
	g_info_t *ptr = NULL;
	int fd = open("mmap_file_02",O_RDWR);

	ptr = mmap(NULL,sizeof(g_info_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	close(fd);

	while(1)
	{
		printf("GID (%d)  GNAME(%s) GPRICE(%d)\n",ptr->G_ID,ptr->G_NAME,ptr->G_PRICE);
		sleep(1);
	}

	munmap(ptr,sizeof(g_info_t));
	return 0;
}
