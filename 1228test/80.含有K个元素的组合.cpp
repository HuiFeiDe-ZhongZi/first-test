class Solution {
	public:
		vector<vector<int>> res;
		vector<int> path;

		void backtraking(int n, int k, int startIndex)
		{
			if(path.size() == k)
			{
				res.push_back(path);
				return;
			}

			for(int i = startIndex; i <= n; i++)
			{
				path.push_back(i);
				backtraking(n,k,i+1);
				path.pop_back();
			}
		}

		vector<vector<int>> combine(int n, int k) {
			backtraking(n,k,1);
			return res;
		}
};
