#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>


void *tjob(void *arg)
{
	//普通线程
	pthread_t tid;
	pthread_detach(pthread_self());//设置为分离线程
	tid = pthread_self();
	printf("....thread tid [0x%x]\n",(unsigned int)tid);
	
	pthread_exit((void*)-2);//返回线程退码
}

int main()
{
	//主控线程任务区
	pthread_t tid,mtid;
	int code = 4096;
	mtid = pthread_self();//查看线程Id
	printf(".....id[0x%x]\n",(unsigned int)mtid);//强转为16进制
	pthread_create(&tid,NULL,tjob,(void*)&code);//传出线程编号 线程属性 线程工作 线程工作传参

	sleep(0); //产生一次系统调用 切换到普通线程

	void *reval;
	int err;
	if((err = pthread_join(tid,&reval))>0)//线程回收
	{
		printf("pthread join error:[%s]..\n",strerror(err));
		exit(0);
	}
	printf("master thread join success,thread exitcode [%ld]\n",(long int)reval);//64位系统强转成8字节 32位强转位4字节

	
	return 0;
}


