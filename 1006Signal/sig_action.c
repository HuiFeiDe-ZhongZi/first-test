#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

//信号忽略与信号捕捉 只是差一个捕捉函数的问题
//捕捉函数
void Eat(int n)
{
	int flag = 3;
	while(flag)
	{
		flag--;
		printf("flag = %d...\n",flag);
		sleep(1);
	}
}

int main()
{
	//信号行为结构体 创建与定义
	struct sigaction nact,oact;
	//自定捕捉函数函数地a
	nact.sa_handler = Eat;//默认SIG_DFL
	nact.sa_flags = 0;
	//初始化信号集 初始化0
	sigemptyset(&nact.sa_mask);
	//替换使用自定义信号行为
	sigaction(SIGINT,&nact,&oact);

	while(1);
		sleep(1);

	return 0;
}
