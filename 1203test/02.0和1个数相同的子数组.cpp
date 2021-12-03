#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
	unordered_map<int,int> mp;
	int sum = 0; //和
	int res = 0; //个数
	mp[0] = -1;
	for(int i = 0; i < nums.size(); i++)
	{
		sum += (nums[i] == 0)?-1:1;
		if(mp.count(sum))
		{
			res = max(res,i - mp[sum]);  //计算长度
		}
		else
		{
			mp[sum] = i;
		}
	}
	return res;
}

int main()
{
	vector<int> nums = {0,1,0};
	
	cout<<findMaxLength(nums)<<endl;

	return 0;
}
