class Solution {
	public:
		int peakIndexInMountainArray(vector<int>& arr) {
			int left = 0;
			int right = arr.size() - 1;
			while(left <= right)
			{
				int mid = left + (right - left)/2;
				if(arr[mid] < arr[mid + 1])  // 上坡
				{
					left = mid + 1;
				}
				else if(arr[mid] < arr[mid - 1])     // 下坡
				{
					right = right - 1;
				}
				else                        // 山峰右侧
				{
					return mid;
				}
			}
			return -1;
		}
};
