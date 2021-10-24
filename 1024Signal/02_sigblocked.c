#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>


int main()
{
	sigset_t newset,oldset,weijue;
	// 初始化自定义屏蔽字
	sigemptyset(&newset);
	// 设置屏蔽
	sigaddset(&newset,SIGINT);
	sigaddset(&newset,SIGQUIT);
	// 替换掉进程默认屏蔽字
	sigprocmask(SIG_SETMASK,&newset,&oldset);

	while(1)
	{
		sigpending(&weijue);
		{	
			for(int i = 1;i < 32; i++)
			{
				if(sigismember(&weijue,i))
					putchar('1');
				else
					putchar('0');
				
			}
			putchar('\n');
		}
		sleep(1);
	}


	return 0;
}

