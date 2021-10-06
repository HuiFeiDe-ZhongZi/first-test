#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>

int main()
{

	char buffer[10];
	bzero(buffer,sizeof(buffer));

	mkfifo("fifo",0664);

	int fd = open("fifo",O_RDONLY);

	read(fd,buffer,sizeof(buffer));

	int servant_pid = atoi(buffer);

	close(fd);

	unlink("fifo");

	kill(servant_pid,2);
	sleep(1);
	kill(servant_pid,3);
	sleep(1);
	kill(servant_pid,4);
	sleep(1);
	kill(servant_pid,5);
	sleep(1);


	return 0;

}
