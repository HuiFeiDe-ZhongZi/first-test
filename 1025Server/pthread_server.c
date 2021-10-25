#include<SOCKET.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>

void *thread_wait(void *arg)
{
	pthread_detach(pthread_self());
	int clientfd = *(int *)arg;
	char buffer[1500];
	int rsize;
	socklen_t size;
	int len;
	pid_t pid;
	while((rsize = recv(clientfd,buffer,sizeof(buffer),0))>0)
	{
		len = 0;

		while(rsize > len)
		{
			buffer[len] = toupper(buffer[len]);
			len++;
		}
		send(clientfd,buffer,rsize,0);
		printf("Respons OK\n");
	}
	if(rsize == 0)
	{
		pthread_exit(NULL);
	}

}
int main()
{
	pthread_t tid;
	// 网络初始化
	struct sockaddr_in myaddr,clientaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(8000);


	int serverfd,clientfd;

	serverfd = SOCKET(AF_INET,SOCK_STREAM,0);
	BIND(serverfd,(struct sockaddr *)&myaddr,sizeof(myaddr));
	LISTEN(serverfd,128);
	printf("server version 1.0 Accepting...\n");
	char buffer[1500];
	int rsize;
	socklen_t size;
	int len;
	pid_t pid;
	while(1)
	{

		if((clientfd = ACCEPT(serverfd,(struct sockaddr*)&clientaddr,&size)) >0)
		{
			pthread_create(&tid,NULL,thread_wait,(void*)&clientfd);
		}
	}

	close(serverfd);
	close(clientfd);
	return 0;
}
