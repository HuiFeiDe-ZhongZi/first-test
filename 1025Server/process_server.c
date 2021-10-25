#include<SOCKET.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>

void sig_wait(int n)
{
	pid_t wpid;
	while((wpid == waitpid(-1,NULL,WNOHANG))>0)
	{
		printf("wait thread <0x%x> wait zombie [%d]\n",(unsigned int)pthread_self(),getpid());
	}
}

void *thread_wait(void *arg)
{
	//捕捉SIGCHLD信号
	struct sigaction act,oact;
	act.sa_handler = sig_wait;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGCHLD,&act,&oact);

	//解除屏蔽
	sigprocmask(SIG_SETMASK,&act.sa_mask,NULL);
	while(1)
		sleep(1);
}
int main()
{
	// 屏蔽字(屏蔽SIGCHLD继承给普通线程)
	sigset_t set,oset;
	sigemptyset(&set);
	sigaddset(&set,SIGCHLD);
	sigprocmask(SIG_SETMASK,&set,&oset);
	// 回收线程创建
	pthread_t tid;
	pthread_create(&tid,NULL,thread_wait,NULL);
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
			pid = fork();
		}
		

		// 读取请求，处理请求，响应

		if(pid == 0)
		{
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
				exit(0);
			}
		}
	}

	close(serverfd);
	close(clientfd);
	return 0;
}
