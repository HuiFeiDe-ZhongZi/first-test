nclude<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0)
			return res;

		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		int a = i + 1;
		int b = nums.size() - 1;
		while (a < b)
		{
			if (nums[i] + nums[a] + nums[b] > 0)
			{
				b--;
			}
			else if (nums[i] + nums[a] + nums[b] < 0)
			{
				a++;
			}
			else
			{
				res.push_back(vector<int>{nums[i], nums[a], nums[b]});

				while (a < b && nums[a] == nums[a + 1]) a++;
				while (a < b && nums[b] == nums[b - 1]) b--;


				a++;
				b--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = threeSum(nums);
	for (auto a : res)
	{
		for (auto b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}
