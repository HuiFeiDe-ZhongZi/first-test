#include "./SOCKET.h"

int SOCKET(int domain, int type,int protocal)
{
	int reval;
	if((reval = socket(domain,type,protocal)) == -1)
	{
		perror("SOCKET CREATE ERROR");
		exit(-1);
	}
	return reval;
}

int BIND(int sockfd,const struct sockaddr * addr,socklen_t addrlen)
{
	int reval;
	if((reval = bind(sockfd,addr,addrlen)) == -1)
	{
		perror("BIND CREATE ERROR");
		exit(-1);
	}
	return reval;
}

int LISTEN(int sockfd,int backlog)
{
	int reval;
	if((reval = listen(sockfd,backlog)) == -1)
	{
		perror("LISTEN CALL FAILED");
		exit(-1);
	}
	return reval;
}



int ACCEPT(int sockfd,struct sockaddr * addr,socklen_t * addrlen)
{
	int reval;
	if((reval = accept(sockfd,addr,addrlen)) == -1)
	{
		perror("ACCEPT CREATE ERROR");
		exit(-1);
	}
}

int CONNECT(int sockfd,const struct sockaddr * addr,socklen_t addrlen)
{
	int reval;
	if((reval = connect(sockfd,addr,addrlen)) == -1)
	{
		perror("CONNECT CALL FAILED");
		exit(-1);
	}
	return reval;
}



