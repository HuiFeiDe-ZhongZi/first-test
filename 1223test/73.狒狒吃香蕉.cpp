class Solution {
	public:
		int minEatingSpeed(vector<int>& piles, int h) {
			int maxVal = *max_element(piles.begin(),piles.end());

			int left = 1;
			int right = maxVal;
			while(left <= right)
			{
				int mid = left + (right - left)/2;
				int hours = getHours(piles,mid);
				if(hours <= h)
				{
					if(mid == 1 || getHours(piles,mid - 1) > h)
					{
						return mid;
					}
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}

			return -1;
		}

		int getHours(vector<int>& piles,int speed)
		{
			int hours = 0;
			for(int &pile : piles)
			{
				hours += (pile + speed - 1) /speed;  // 向上取整算法
			}

			return hours;
		}
};
