ass Solution {
	public:

		class mycomparison {
			public:
				bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
					return lhs.second > rhs.second;
				}
		};
		vector<int> topKFrequent(vector<int>& nums, int k) {

			unordered_map<int,int> map;
			for(int i = 0; i < nums.size(); i++)
			{
				map[nums[i]]++;
			}


			priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;
			for(unordered_map<int,int>::iterator ite = map.begin(); ite != map.end(); ite++)
			{
				pri_que.push(*ite);
				if(pri_que.size() > k)
				{
					pri_que.pop();
				}
			}

			vector<int> res(k);
			for(int i = k - 1; i>=0;i--)
			{
				res[i] = pri_que.top().first;
				pri_que.pop();
			}

			return res;
		}

};
