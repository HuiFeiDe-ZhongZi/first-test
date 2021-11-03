#include<pthread_pool.h>


int thread_pool_add_busines(thread_pool_t * pool , busines_t bs) // 生产者向线程池中添加业务
{
	// 生产者消费者模型 ：生产者
	// 该函数调用一次添加一个业务，如果任务容器已满，生产者挂起，生产者将新任务添加到任务容器头索引，
	// 添加完任务后对索引进行环形偏移，修改线程池阈值 添加完毕唤醒消费者线程
	if(pool->thread_shutdown)
	{
		pthread_mutex_lock(&pool->thread_lock);
		// 判断工作条件
		while(pool->b_cur == pool->b_max) // 挂起前挂起一次 唤醒后在判断一次 使用while挂起
		{
			printf("服务器:[生产者]不满足工作条件,挂起线程...\n");
			pthread_cond_wait(&pool->not_full,&pool->thread_lock);
		}
		
		// 添加业务
		pool->busines_queue[pool->b_front].BUSINES_ADDR = bs.BUSINES_ADDR;

		pool->busines_queue[pool->b_front].BUSINES_ARG = bs.BUSINES_ARG;

		++pool->b_cur;

		pool->b_front = (pool->b_front + 1) % pool->b_max; // 环形偏移

		pthread_mutex_unlock(&pool->thread_lock);
		printf("服务器:生产者添加任务完成...\n");
		pthread_cond_signal(&pool->not_empty); // 唤醒一个消费者线程
	}
	else
	{
		return -1;
	}

	return 0;
}

