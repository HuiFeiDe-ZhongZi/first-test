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

	ftruncate(fd,sizeof(g_info_t));

	ptr = mmap(NULL,sizeof(g_info_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	close(fd);

	ptr->G_ID=0;
	bzero(ptr->G_NAME,20);
	while(1)
	{
		++(ptr->G_ID);
		sprintf(ptr->G_NAME,"PUBG %d",ptr->G_ID);
		ptr->G_PRICE=200;
		sleep(1);
	}

	munmap(ptr,sizeof(g_info_t));
	return 0;
}
