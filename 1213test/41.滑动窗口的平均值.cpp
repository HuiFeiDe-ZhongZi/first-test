int n;
int sum = 0;
queue<int> q;

double next(int val) {
	if(q.size() == n)   // 队列已满 队首出队，val从队尾入队
	{
		int tmp = q.front();
		q.pop();
		q.push(val);
		sum = sum - tmp + val;
	}
	else
	{                      // 队列未满 窗口中添加元素
		q.push(val);
		sum+=val;
	}

	return (sum * 1.0) / min(n,(int)q.size());  // 当队列未满时，长度是不足n的，取平均值时要除以队列的长度
}

