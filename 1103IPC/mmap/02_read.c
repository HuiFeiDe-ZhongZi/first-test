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
	int fd = open("mmap_file",O_RDONLY);
	
	ptr = mmap(NULL,sizeof(g_info_t),PROT_READ,MAP_SHARED,fd,0);

	close(fd);

	while(1)
	{
		printf("GID [%d] GMAME [%s] GPRICE [%d]\n",ptr->g_id,ptr->g_name,ptr->g_price);
		sleep(1);
	}

	munmap(ptr,sizeof(g_info_t)); 
	return 0;
}
