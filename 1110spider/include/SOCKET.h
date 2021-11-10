#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

#include<pthread.h>
#include<signal.h>
#include<sys/epoll.h>
#include<errno.h>
#include<netdb.h>

int SOCKET(int , int ,int);
int BIND(int ,const struct sockaddr *,socklen_t);
int LISTEN(int,int);
int ACCEPT(int,struct sockaddr *,socklen_t *);
int CONNECT(int,const struct sockaddr *,socklen_t);
