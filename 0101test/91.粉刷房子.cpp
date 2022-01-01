class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n,vector<int>(3));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(int i = 1;i < n; i++)
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i][2];
        }
        return min(dp[n - 1][0],min(dp[n - 1][1],dp[n - 1][2]));
    }
};

//确定递推关系：第n个房子涂色为0时，第n-1个房子只能涂为1和2，因此这种情况下的花费为第n-1间房子涂成1和涂成2中花费较小的项加上第n个房子涂成0的花费。
//即：dp[n][0]=min(dp[n-1][1],dp[n-1][2])+costs[n][0]，同理第n个房子还可以涂成1和2：
//dp[n][1]=min(dp[n-1][0],dp[n-1][2])+costs[n][1]和dp[n][2]=min(dp[n-1][1],dp[n-1][0])+costs[n][2]
//最终结果返回上述三种情况中最小值。