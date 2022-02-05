#include<pthread_pool.h>


int if_thread_alive(pthread_t tid) //测试一个线程是否存活 ? 返回0表示线程以结束，1表示线程存活
{
	// 无论是kill 函数还是sig_kill函数,如果信号编号为0,测试进程或线程是否存活
	pthread_kill(tid,0);
	if(errno == ESRCH)
		return FALSE;
	else
		return TRUE;
}
