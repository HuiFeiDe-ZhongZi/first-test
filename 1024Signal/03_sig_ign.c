#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>


int main()
{
	// 定义信号行为结构体
	struct sigaction newact,oldact;
	// 结构体赋值
	newact.sa_handler = SIG_IGN; // 函数指针类型 存放函数指定格式接口地址
	newact.sa_flags = 0;
	// 初始化临时屏蔽字
	sigemptyset(&newact.sa_mask);

	// 利用sigaction函数修改信号行为，将原有行为替换
	sigaction(SIGINT,&newact,&oldact);

	while(1);

	return 0;
}
