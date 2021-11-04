#include<pthread_pool.h>

void * thread_pool_customer_job(void * arg) //消费者默认工作，创建时传递线程池参数
{
	pthread_detach(pthread_self()); // 设置分离线程自动回收
	/*提高消费者线程的重用性，它可以获取多次业务并执行，消费者的任务参数为线程池地址，
	 * 从线程池中获取任务执行，注意唤醒队列的偏移处理以及阈值处理，获取任务成功唤醒一个生产者，
	 * 不要将任务执行放到锁内
	 * 以线程池开关为条件，消费者循环尝试获取任务*/
	busines_t bs;
	thread_pool_t *pool = (thread_pool_t*)arg;
	while(pool->thread_shutdown)
	{
		pthread_mutex_lock(&pool->thread_lock);
		// 判断工作条件
		while(pool->b_cur == 0)
		{
			printf("服务器:[消费者]不满足工作条件,挂起线程!\n");
			pthread_cond_wait(&pool->not_empty,&pool->thread_lock);
			if(pool->thread_exitcode > 0)
			{
				break;
			}
		}

		if(pool->thread_shutdown == 0)
		{
			--pool->thread_alive;
			pthread_mutex_unlock(&pool->thread_lock);
			pthread_exit(NULL);
		}
		if(pool->thread_exitcode > 0)
		{
			--pool->thread_alive;
			--pool->thread_exitcode;
			pthread_mutex_unlock(&pool->thread_lock);
			pthread_exit(NULL);
		}

		//工作条件满足，获取任务
		bs.BUSINES_ADDR = pool->busines_queue[pool->b_rear].BUSINES_ADDR;
		bs.BUSINES_ARG = pool->busines_queue[pool->b_rear].BUSINES_ARG;

		--pool->b_cur;
		//唤醒队列偏移
		pool->b_rear = (pool->b_rear + 1)%pool->b_max;

		//设置忙线程阈值
		++(pool->thread_busy);
		pthread_mutex_unlock(&pool->thread_lock);

		// 唤醒生产者线程
		pthread_cond_signal(&pool->not_full);
		printf("服务器:[消费者]获取任务成功，唤醒一个生产者...\n");
		// 执行任务
		printf("服务器:[消费者]执行任务...\n");
		bs.BUSINES_ADDR(bs.BUSINES_ARG);

		pthread_mutex_lock(&pool->thread_lock);
		--(pool->thread_busy);
		pthread_mutex_unlock(&pool->thread_lock);
	}
	pthread_exit(NULL);
}

