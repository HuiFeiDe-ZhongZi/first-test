#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>



int main()
{
	//信号行为结构体 创建与定义
	struct sigaction nact,oact;
	//自定捕捉函数函数地a
	nact.sa_handler = SIG_IGN;//默认SIG_DFL
	nact.sa_flags = 0;
	//初始化信号集 初始化0
	sigemptyset(&nact.sa_mask);
	//替换使用自定义信号行为
	sigaction(SIGINT,&nact,&oact);

	while(1);
		sleep(1);

	return 0;
}
