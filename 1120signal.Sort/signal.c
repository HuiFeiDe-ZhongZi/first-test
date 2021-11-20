#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


/*重定向实现dup用于备份描述符的指向关系 dup2用于修改描述符的指向关系(使用完毕dup复位)*/
// 信号失效的三种方式 1信号屏蔽 2信号忽略 3信号捕捉
/*信号的几种触发方式:
  1.终端组合按键触发 ctrl+c ctrl+\ ctrl+z
  2.命令触发信号kill
  3.函数触发信号kill raise abort sigqueue
  4.硬件异常触发信号(系统触发):非法操作内存 浮点数例外 总线错误
  5.软条件触发:读端终止,写端向读端写数据,内核向写端发送信号(SIGPIPE)
    			定时器开始定时,定时器到时,内核向指定进程发送信号(SIGALARM)*/
/* 信号的传递过程:信号规程识别终端组合按键,向内核发送通知,内核向唯一的前台进程发送相应的信号,到达当前进程的PCB中,
当前进程通过未决信号集与屏蔽字信号集到达最终的信号处理(信号的三大行为,五大动作) 
三大行为:默认行为,忽略行为,捕捉行为
五大动作:TERM(终止进程) CORE(核心转储) IGN(忽略) STOP(挂起) CONT(继续)*/
// 0号信号可用来查看进程是否存活
int main()
{
	sigset_t newset,oldset,pset;
	// 1.初始化自定义屏蔽字
	sigemptyset(&newset);
	// 2.设置屏蔽
	sigaddset(&newset,SIGINT);
	// 3.替换掉进程默认屏蔽字
	sigprocmask(SIG_SETMASK,&newset,&oldset);

	while(1)
	{
		sigpending(&pset); // 传出当前进程的未决信号集
		for(int i = 1;i < 32;i++)
		{
			if(sigismember(&pset,i)) // 查看返回信号几种信号位状态
				putchar('1');
			else
				putchar('0');
		}
		putchar('\n');
		sleep(2);
	}


	return 0;
}
