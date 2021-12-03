#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
	int totalSum = 0;
	for(int num : nums)
	{
		totalSum += num;
	}

	int leftSum = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		leftSum += nums[i];
		// 左半部分的和 = 左边部分的和 + 中间节点的和（也就是当前节点的值）
		if(leftSum - nums[i] == totalSum - leftSum )
			return i;
	}
	return -1;
}

int main()
{
	vector<int> nums = {1,7,3,6,5,6};
	cout<<pivotIndex(nums)<<endl;

	return 0;
}
