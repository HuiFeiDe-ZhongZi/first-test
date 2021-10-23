#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 四数之和

vector<vector<int>> fourSum(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(),nums.end());

	for(int j = 0; j < nums.size(); j++)
	{	
		if(j > 0 && nums[j] == nums[j-1])
		{
			continue;
		}
		for(int i = j+1; i < nums.size(); i++)
		{
			if(i > j+1 && nums[i] == nums[i-1])
			{
				continue;
			}

			int left = i + 1;
			int right = nums.size() - 1;
			while(right > left)
			{
				if(nums[i] + nums[j] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				else if(nums[i] + nums[j] + nums[left] + nums[right] < 0)
				{
					left++;
				}
				else
				{
					res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});

					while(right > left && nums[right] == nums[right-1]) right--;
					while(right > left && nums[left] == nums[left+1]) left++;

					right--;
					left++;
				}
			}
		}
	}
	return res;
}



int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(2);

	vector<vector<int>> res = fourSum(nums);

	for(vector<int> a:res)
	{

		for(int b:a)
		{
			cout<< b<<"  ";
			if(b == a.back())
			{
				cout<<endl;
			}
		}
	}


	return 0;
}
