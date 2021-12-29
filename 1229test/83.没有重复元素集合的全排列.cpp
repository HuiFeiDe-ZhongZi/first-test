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
				if(used[i] == true) continue; // path里已经记录的元素，直接跳过
				used[i] = true;  
				path.push_back(nums[i]);
				backtracking(nums,used);
				path.pop_back();
				used[i] = false;          
			}


		}
		vector<vector<int>> permute(vector<int>& nums) {
			vector<bool> used(nums.size(),false);
			backtracking(nums,used);
			return res;
		}
};
