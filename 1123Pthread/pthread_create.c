#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

/*用户级线程：1.无法被系统识别分发资源，获取资源有限，不能利用更多资源，加快完成任务进度
              2.用户级线程在用户区间定义和实现，无需借助内核，调度开销小，线程切换速度快，内存开销小，但是调度比较大
  内核级线程：为每一个内核级线程分配内核对象，可以被系统识别并下发资源(时间片)
  			  与多进程模型一样需要话费大量精力完成层级转换或线程调度转换*/

/*线程与进程的关系
  1.进程是最小的分配日资源单位
  2.线程是最小的调度单位
  3.线程寄存于进程中
  4.进程可以蜕化为线程 蜕化为主控线程
  5.线程就是寄存器(分时复用)和栈(保存回复处理器现场) 合格的系统调度单位*/

/*线程的共享资源:全局资源共享、共享堆、文件描述符、进程工作共享目录、PID GID共享、线程间信号行为共享
 线程的非共享资源:用户线程栈非共享、线程屏蔽字非共享、线程信息(tid)非共享、线程调度优先级、线程有自己的处理方式strerror*/

/*线程并发与进程并发利弊
 进程并发模型:
 	优点:可以获取更多系统资源 稳定性更好
	缺点:系统开销比较大，切换上下文，调度缓慢
 线程并发模型:
 	优点:开销小，更轻量
	缺点:稳定性较差，线程崩溃导致进程终止，相较于多进程模型需要注意更多的开发细节 死锁 互斥等*/

/*查看线程所有信息: ps -eLf
 查看指定进程中的线程信息: ps -Lf pid*/


void *jobs(void *arg)
{
	while(1)
		sleep(1);
}

int main()
{
	pthread_t tid;
	int err;
	int flags = 0;
	while(1)
	{
		if((err = pthread_create(&tid,NULL,jobs,(void*)&flags))>0)
		{
			printf("printf call failed:%s\n",strerror(err));
			exit(0);
		}
		printf("thread number <%d>\n",++flags);
	}

	return 0;
}
