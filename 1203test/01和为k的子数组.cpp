#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
	unordered_map<int,int> mp;
	mp[0] = 1;
	int sum = 0; // 和
	int res = 0; // 个数
	for(int i = 0; i < nums.size(); i++)
	{
		sum+=nums[i];
		if(mp.count(sum - k))
		{
			res += mp[sum - k];
		}
		mp[sum]++;
	}
	return res;
}

int main()
{
	vector<int> nums = {1,2,3};
	int k = 3;
	cout<<subarraySum(nums,k)<<endl;

	return 0;
}
