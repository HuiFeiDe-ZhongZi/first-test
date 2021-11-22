#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

/*sleep函数的实现 alarm(定时)+pause(临时挂起)
 信号引起的时序竞态问题:进程执行中，因为系统资源的竞争产生的程序崩坏(结果异常)
解决方案:原子方法:挂起+临时解除解除信号屏蔽 无论其他进程如何竞争系统资源，相关功能也完全可以获取特殊资源，不会引发后续的逻辑异常
sigsuspend调用时会将当前进程挂起，并使用 mask信号集临时替换进程屏蔽字，函数执行完毕后，对进程屏蔽字复位还原
如果不屏蔽 sleep(3)的调用导致系统一直待在内核层 sleep(3)结束后，直接处理信号  pause函数会产生第一次调用 一直挂起  不会检测到信号有处理动作 不会唤醒*/



void SIG_ALARM(int n)
{
	// 空调用
}

unsigned int MySleep(unsigned int seconds)
{

	unsigned int reval;

	// 信号屏蔽
	sigset_t nset,oset;
	sigemptyset(&nset);
	sigaddset(&nset,SIGALRM);
	sigprocmask(SIG_SETMASK,&nset,&oset);

	// 信号捕捉
	struct sigaction nact,oact;
	nact.sa_handler = SIG_ALARM;
	nact.sa_flags = 0;
	sigemptyset(&nact.sa_mask);
	sigaction(SIGALRM,&nact,&oact);

	reval = alarm(seconds);// 定时开始，定时结束时发送SIGALARM
	sleep(3);
	sigsuspend(&oset); // 挂起+临时解除屏蔽方法
	sleep(1);
	sigprocmask(SIG_SETMASK,&oset,NULL); // 还原进程原有屏蔽字"
	sigaction(SIGALRM,&oact,NULL); // 还原进程原有信号行为

}

int main()
{
	while(1)
	{
		printf("two seconds...\n");
		MySleep(2);
	}


	return 0;
}
