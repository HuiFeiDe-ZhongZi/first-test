#include<pthread_pool.h>



thread_poll_t * thread_pool_create(int Max , int Min , int QueMax)  // 线程池创建初始化，成功返回线程池地址
{
	thread_pool_t *pool = NULL;
	
	// 申请空间
	if((pool = (thread_poll_t*)malloc(sizeof(thread_poll_t))) == NULL)
	{
		thread_poll_error("thread_pool_create > malloc pool",-1,0);
	}
	pool->thread_shutdown = TRUE; 
	pool->thread_max = Max;
	pool->thread_min = Min;
	pool->thread_busy = 0;
	pool->thread_alive = 0 ;
	pool->thread_exitcode = 0;
	
	// 申请空间(tids)
	if((pool->customer_tids = (pthread_t*)malloc(Max * sizeof(pthread_t))) == NULL)
	{
		thread_poll_error("thread_pool_create customer tids",-1,0);
	}
	bzero(pool->customer_tids,Max * sizeof(pthread_t));

	// 申请空间(busines_queue)
	if((pool->busines_queue = (busines_t*)malloc(QueMax * sizeof(busines_t))) == NULL)
	{
		thread_poll_error("thread_pool_create > malloc busines_queue",-1,0);
	}
	pool->b_front = 0; 
	pool->b_rear = 0; 
	pool->b_max = 0; 
	pool->b_cur = QueMax;

	// 初始化互斥锁与条件变量
	if(pthread_mutex_init(&pool->thread_lock,NULL)!=0 || pthread_cont_init(&pool->not_full,NULL)!=0 || pthread_cont_init(&pool->not_empty)!=0)
	{
		printf("thread_pool_create > init lock or cond error\n");
		exit(0);
	}
	
	// 创建管理者线程
	int err;
	if((err = pthread_create(&pool->manager_tid,NULL,?,(void*)pool))>0)
	{
		threas_pool_error("thread_pool_creat > create manager error",-1,err);
	}

	for(int i = 0;i < pool->thread_min;i++)
	{
		if((err = pthread_create(&pool->customer_tids,NULL,?,(void*)pool))>0)
		{
			threas_pool_error("thread_pool_creat > create customer error",-1,err);
		}
		++pool->thread_alive;
	}

	return pool;
}
		

	


