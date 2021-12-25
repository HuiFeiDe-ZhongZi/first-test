class Solution {
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals) {

			vector<vector<int>> res;
			vector<int> tmp;

			sort(intervals.begin(),intervals.end());
			tmp = intervals[0];

			for(int i = 1; i < intervals.size(); i++)
			{
				if(tmp[1] < intervals[i][0])
				{
					res.push_back(tmp);
					tmp = intervals[i];
				}
				else
				{
					tmp[1] = max(tmp[1],intervals[i][1]);
				}
			}

			res.push_back(tmp);
			return res;
		}
};
