#include<pthread_pool.h>


// 管理者任务
void * thread_pool_manager_job(void * arg) // 消费者默认工作，创建时传递线程池参数
{
	pthread_detach(pthread_self());
	// 管理者线程需要频繁使用阈值，进行扩容缩减判断(alive,busy,cur)
	// 管理者频繁占用锁？
	// 降低管理者对互斥锁的占用
	// 加锁获取数据使用，数据的准确性？ 获取频率块，准确性高，频率慢，准确性低
	thread_pool_t *pool = (thread_pool_t*)arg;

	int alive,busy,cur;
	int flag,add;
	int err;
	while(pool->thread_shutdown)
	{
		pthread_mutex_lock(&pool->thread_lock);
		alive = pool->thread_alive;
		busy = pool->thread_busy;
		cur = pool->b_cur;
		pthread_mutex_unlock(&pool->thread_lock);
		
		printf("                                                服务器:[管理者]alive %d busy %d idel %d b/a %.2f a/m %.2f\n",alive,busy,alive-busy,(double)busy/alive * 100,(double)alive/pool->thread_max *100);
		// 扩容条件判断
		if((cur >= alive - busy || (double)busy/alive*(double)100 >= 70) && (alive + THREAD_CODE <= pool->thread_max))
		{
				printf("服务器:[管理者]满足线程池扩展条件，开始扩展...\n");		
				for(flag = 0,add = 0; flag < pool->thread_max && add < THREAD_CODE; flag++)
				{
					if(pool->customer_tids[flag] == 0 || !if_thread_alive(pool->customer_tids[flag]))
					{
						if((err = pthread_create(&pool->customer_tids[flag],NULL,thread_pool_customer_job,(void*)pool))>0)
						{
							thread_pool_error("thread_pool_manager_job >> pthread_create error",-1,err);
						}
						add++;
						// 存活线程阈值设置
						pthread_mutex_lock(&pool->thread_lock);
						++(pool->thread_alive);
						pthread_mutex_unlock(&pool->thread_lock);
						
					}
				}
		}
		// 缩减条件判断
		if(busy * 2 <= alive - busy && alive - THREAD_CODE >= pool->thread_min)
		{
			printf("服务器:[管理者]满足线程池缩减条件，开始缩减...\n");		

			pthread_mutex_lock(&pool->thread_lock);
			pool->thread_exitcode = THREAD_CODE;
			pthread_mutex_unlock(&pool->thread_lock);

			for(int i = 0; i < THREAD_CODE; i++)
			{
				pthread_cond_signal(&pool->not_empty);
			}
		}
		sleep(TIMEOUT); // 检查延时
	}

		pthread_exit(NULL);
}
