class Solution {
	public:
		vector<double> pre;
		Solution(vector<int>& w) {
			int tot_sum = accumulate(w.begin(),w.end(),0);
			int cur_presum = 0;
			for(int x : w)
			{
				cur_presum += x;
				pre.push_back((double)cur_presum/tot_sum);
			}
		}

		int pickIndex() {
			return lower_bound(pre.begin(), pre.end(), (double)rand()/RAND_MAX) - pre.begin();
		}
};
