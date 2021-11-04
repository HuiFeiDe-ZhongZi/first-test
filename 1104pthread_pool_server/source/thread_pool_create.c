#include<pthread_pool.h>



thread_pool_t * thread_pool_create(int max , int min , int quemax)  // 线程池创建初始化，成功返回线程池地址
{
	thread_pool_t *pool = NULL;
	
	// 申请空间
	if((pool = (thread_pool_t*)malloc(sizeof(thread_pool_t))) == NULL)
	{
		thread_pool_error("thread_pool_create > malloc pool",-1,0);
	}
	pool->thread_shutdown = TRUE; 
	pool->thread_max = max;
	pool->thread_min = min;
	pool->thread_busy = 0;
	pool->thread_alive = 0 ;
	pool->thread_exitcode = 0;
	
	// 申请空间(tids)
	if((pool->customer_tids = (pthread_t*)malloc(max * sizeof(pthread_t))) == NULL)
	{
		thread_pool_error("thread_pool_create customer tids",-1,0);
	}
	bzero(pool->customer_tids,max * sizeof(pthread_t));

	// 申请空间(busines_queue)
	if((pool->busines_queue = (busines_t*)malloc(quemax * sizeof(busines_t))) == NULL)
	{
		thread_pool_error("thread_pool_create > malloc busines_queue",-1,0);
	}
	pool->b_front = 0; 
	pool->b_rear = 0; 
	pool->b_max = 0; 
	pool->b_cur = quemax;

	// 初始化互斥锁与条件变量
	if(pthread_mutex_init(&pool->thread_lock,NULL)!=0 || pthread_cond_init(&pool->not_full,NULL)!=0 || pthread_cond_init(&pool->not_empty,NULL)!=0)
	{
		printf("thread_pool_create > init lock or cond error\n");
		exit(0);
	}
	
	// 创建管理者线程
	int err;
	if((err = pthread_create(&pool->manager_tid,NULL,thread_pool_manager_job,(void*)pool))>0)
	{
		thread_pool_error("thread_pool_creat > create manager error",-1,err);
	}

	// 创建消费者线程
	printf("%d\n",pool->thread_min);
	for(int i = 0;i < pool->thread_min;i++)
	{
		printf("%d\n",pool->thread_min);
		if((err = pthread_create(&pool->customer_tids[i],NULL,thread_pool_customer_job,(void*)pool))>0)
		{
			thread_pool_error("thread_pool_creat > create customer error",-1,err);
		}	
		++pool->thread_alive;
	}

	return pool;
}
		

	


