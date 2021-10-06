#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>

void start(int n)
{
	printf("Start...\n");
}

void end(int n)
{
	printf("Ending..\n");
}

void self(int n)
{
	printf("Self examination\n");
}

void activ(int n)
{
	printf("activ limbs\n");
}


int main()
{
	//"servent进程信号捕捉"
	struct sigaction sact,eact,lact,aact,oact;
	sact.sa_handler = start;
	sact.sa_flags = 0;
	sigemptyset(&sact.sa_mask);
	sigaction(SIGINT,&sact,NULL);

	lact.sa_handler = self;
	lact.sa_flags = 0;
	sigemptyset(&lact.sa_mask);
	sigaction(SIGQUIT,&lact,NULL);

	aact.sa_handler = activ;
	aact.sa_flags = 0;
	sigemptyset(&aact.sa_mask);
	sigaction(SIGILL,&aact,NULL);

	eact.sa_handler = end;
	eact.sa_flags = 0;
	sigemptyset(&eact.sa_mask);
	sigaction(SIGTRAP,&eact,NULL);

	char buffer[10];
	bzero(buffer,sizeof(buffer));

	int fd = open("fifo",O_WRONLY);

	pid_t pid = getpid();
	
	sprintf(buffer,"%d",pid);

	write(fd,buffer,strlen(buffer));

	close(fd);
	while(1)
		sleep(1);

	return 0;

}
