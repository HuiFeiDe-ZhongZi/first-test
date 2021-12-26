iclass Solution {
	public:
		int Sort(vector<int>& nums,int nLow,int nHigh)
		{
			int tmp = nums[nLow];

			while(nLow < nHigh)
			{
				/* 从后向前找比标准值小的 */
				while(nLow < nHigh)
				{
					if(nums[nHigh] < tmp)
					{
						nums[nLow] = nums[nHigh];
						nLow++;
						break;
					}
					nHigh--;
				}
				/* 从前向后找比标准值大的 */
				while(nLow < nHigh)
				{
					if(nums[nLow] > tmp)
					{
						nums[nHigh] = nums[nLow];
						nHigh--;
						break;
					}
					nLow++;
				}  
			}

			nums[nLow] = tmp;
			return nLow;
		}
		void quickSort(vector<int>& nums,int nLow,int nHigh)
		{
			if(nums.empty() || nLow >= nHigh) return;

			/* 1.标准值 */
			int nStandard; 
			nStandard = Sort(nums,nLow,nHigh);

			/* 2.分割，分别执行以上操作*/
			quickSort(nums,nLow,nStandard - 1); 
			quickSort(nums,nStandard + 1,nHigh);

		}
		int findKthLargest(vector<int>& nums, int k) {
			int size = nums.size();
			quickSort(nums,0,size - 1);
			return nums[size - k];

		}
};
