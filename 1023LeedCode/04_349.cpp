#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> result;
	unordered_set<int> nums(nums1.begin(),nums1.end());
	for(int num:nums2)
	{
		if(nums.find(num)!= nums.end())
		{
			result.insert(num);
		}
	}
	return vector<int>(result.begin(),result.end());
}
int main()
{
	vector<int> nums1;
	nums1.push_back(4);
	nums1.push_back(9);
	nums1.push_back(5);

	vector<int> nums2;

	nums2.push_back(9);
	nums2.push_back(4);
	nums2.push_back(9);
	nums2.push_back(8);
	nums2.push_back(4);

	
	vector<int> arr = intersection(nums1,nums2);
	for(int a:arr)
	{
		cout<<a<<endl;
	}

	return 0;
}
