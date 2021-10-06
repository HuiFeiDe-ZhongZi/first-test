#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

int main()
{

	sigset_t  new_set,old_set;
	
	sigemptyset(&new_set);
	
	sigaddset(&new_set,SIGINT);
	sigprocmask(SIG_SETMASK,&new_set,&old_set);

	while(1);
	return 0;
}

