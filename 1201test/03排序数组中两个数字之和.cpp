//双指针解法
vector<int> twoSum(vector<int>& numbers, int target) {
	int left = 0;
	int right = numbers.size() - 1;
	vector<int> res;
	while(left < right)
	{
		if(numbers[left] + numbers[right] > target)
		{
			right--;
		}
		else if(numbers[left] + numbers[right] < target)
		{
			left++;
		}
		else
		{
			res.push_back(left);
			res.push_back(right); 
			break;
		}
	}
	return res;
}
