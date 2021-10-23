#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums,int val)
{
	int count = 0;
	int slow = 0;
	for(int fast = 0; fast < nums.size(); fast++)
	{
		if(nums[fast] != val)
		{
			nums[slow++]= nums[fast];
		}
	}
	return slow;
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);


	cout<<removeElement(nums,3)<<endl;

	return 0;
}
