class Solution {
	public:
		vector<vector<int>> res;
		vector<int> path;

		void backtracking(vector<int>& c,int target,int sum,int startIndex)
		{
			if(sum == target)
			{
				res.push_back(path);
				return;
			}
			for(int i = startIndex;i < c.size() && sum + c[i] <= target; i++)
			{
				if(i > startIndex && c[i] == c[i - 1])
				{
					continue;
				}
				sum += c[i];
				path.push_back(c[i]);
				backtracking(c,target,sum,i+1);
				sum -= c[i];
				path.pop_back();
			}
		}
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(),candidates.end());
			backtracking(candidates,target,0,0);
			return res;
		}
};
