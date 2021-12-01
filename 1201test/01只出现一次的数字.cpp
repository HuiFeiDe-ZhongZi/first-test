
int singleNumber(vector<int>& nums) {
	unordered_map<int,int> freq;
	for(int num:nums)
	{
		++freq[num];
	}

	int res = 0;
	for(auto [num,occ]:freq)
	{
		if(occ == 1)
		{
			res = num;
			break;
		}
	}
	return res;
}
