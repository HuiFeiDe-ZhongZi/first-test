class Solution {
	public:
		int minFlipsMonoIncr(string s) {
			int numOfOne = 0;
			vector<int> dp(s.size());
			if (s[0] == '1') {
				numOfOne = 1;
			}
			for (int i = 1, size = s.size(); i < size; i++) {
				if (s[i] == '1') {
					dp[i] = min(dp[i-1], numOfOne+1);
					numOfOne++;
				} else {
					dp[i] = min(dp[i-1]+1, numOfOne);
				}
			}
			return dp[s.size()-1];
		}
};
