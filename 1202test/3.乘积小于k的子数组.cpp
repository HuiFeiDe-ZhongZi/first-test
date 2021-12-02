#include<iostream>
#include<vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
	long product = 1;
	int left = 0;
	int res = 0;
	for (int right = 0; right < nums.size(); right++)
	{
		product *= nums[right];
		while (left <= right && product >= k)
		{
			product /= nums[left++];
		}
		if (left <= right)
		{
			res += right - left + 1;
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { 10,5,2,6 };
	int k = 100;
	cout << numSubarrayProductLessThanK(nums, k) << endl;

	return 0;
}
