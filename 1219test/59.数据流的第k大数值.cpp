class KthLargest {
	private:
		priority_queue<int,vector<int>,greater<int>> q;  // 建立小根堆
		int k;
	public:
		KthLargest(int k, vector<int>& nums) {
			this->k = k;
			for(int &num:nums) add(num);
		}

		int add(int val) {
			q.push(val);
			if(q.size() > k) q.pop();  // 堆元素大于k,就弹出

			return q.top(); // 返回堆顶最小元素，即第K大元素
		}
};
