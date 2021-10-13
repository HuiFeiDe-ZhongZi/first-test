#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>


void *tjob(void *arg)
{
	int code;
	code = *(int*)arg;
	printf("thread arg <%d>...\n",code);
	
	pthread_t tid;
	tid = pthread_self();
	printf("....thread tid [0x%x]\n",(unsigned int)tid);
	
	while(1)
		sleep(1);

	pthread_exit(NULL); //return NULL 或 pthread_exit((void*)5);
						//两种做法都可以退出当前线程，并返回线程退出码
}

int main()
{
	//主控线程任务区
	pthread_t tid,mtid;
	int code = 4096;

	mtid = pthread_self();//查看线程Id
	printf(".....id[0x%x]\n",(unsigned int)mtid);//强转为16进制
	pthread_create(&tid,NULL,tjob,(void*)&code);//传出线程编号 线程属性 线程工作 线程工作传参
	printf(".....master create[0x%x]\n",(unsigned int)tid);//强转为16进制

	//create传出tid thread获取tid 值相等，但是不等价（线程状态可能不同）
	while(1)
		sleep(1);

	return 0;
}


