
queue<int> q;
int ping(int t) {
	q.push(t);
	while(t - q.front() > 3000) q.pop();  // 若时间太早，则循环从队列头出去  

	return q.size(); // 留下的都是满足条件的，最后返回队列长度
}
