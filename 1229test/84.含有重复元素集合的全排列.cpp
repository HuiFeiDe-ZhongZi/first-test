class Solution {
	public:
		vector<vector<int>> res;
		vector<int> path;

		void backtracking(vector<int>& nums,vector<bool>& used)
		{
			if(nums.size() == path.size())
			{

				res.push_back(path);
				return;
			}
			for(int i = 0; i < nums.size();i++)
			{
				if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				{
					continue;
				}
				if(used[i] == false)
				{
					used[i] = true;  
					path.push_back(nums[i]);
					backtracking(nums,used);
					path.pop_back();
					used[i] = false;                  
				}

			}


		}
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<bool> used(nums.size(),false);
			backtracking(nums,used);
			return res;
		}
};
