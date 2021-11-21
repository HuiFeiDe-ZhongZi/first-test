#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

/*按信号行为结构中函数指针类型，定义实现捕捉函数，而后进行设置，将捕捉函数的地址存储到行为结构体中*/

// 捕捉函数


// 经典信号不支持排队(因为信号传递以及临时屏蔽，相同信号最多支持一次等待处理)

// 下面这段代码 不论输入多少次ctrl+C  都只会输出两轮3 2 1 
/* 信号失效的区别
 信号屏蔽(信号未抵达)
 信号忽略(已抵达，没有处理动作)
 信号捕捉(已抵达，自定义处理动作)*/
void Eat(int n)
{
	int flags = 3;
	while(flags--)
	{
		printf("--flags = %d\n",flags);
		sleep(1);
	}
}

int main()
{
	// 信号行为结构体创建与定义
	struct sigaction nset,oset;
	nset.sa_handler = Eat;
	nset.sa_flags = 0;
	sigemptyset(&nset.sa_mask);
	// 替换使用自定义信号行为
	sigaction(SIGINT,&nset,&oset);

	while(1)
		sleep(1);
	return 0;

}
