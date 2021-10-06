#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

void print_pest(sigset_t pset)
{
	for(int i =1;i<32;i++)
	{
		if(sigismember(&pset,i))
			putchar('1');
		else
			putchar('0');
	}
	putchar('\n');
}

int main()
{

	sigset_t  new_set,old_set,p_set;
	
	//初始化自定义屏蔽字
	sigemptyset(&new_set);
	//设置屏蔽
	sigaddset(&new_set,SIGINT);
	sigaddset(&new_set,SIGQUIT);
	
	//替换掉进程默认屏蔽字
	sigprocmask(SIG_SETMASK,&new_set,&old_set);
	

	while(1)
	{
		sigpending(&p_set);//获取未决信号集
		print_pest(p_set);//输出信号表
		sleep(1);
	}

	return 0;
}

