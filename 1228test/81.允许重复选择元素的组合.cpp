class Solution {
	public:
		vector<vector<int>> res;
		vector<int> path;

		void backtracking(vector<int>&c,int target,int startIndex)
		{
			if(target < 0) return;
			if(target == 0)
			{
				res.push_back(path);
				return;
			}

			for(int i = startIndex;i < c.size(); i++)
			{
				if(c[i] <= target)
				{
					path.push_back(c[i]);
					backtracking(c,target - c[i],i);
					path.pop_back();
				}
			}
		}
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			backtracking(candidates,target,0);
			return res;
		}
};
