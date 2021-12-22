class Solution {
	public:
		int singleNonDuplicate(vector<int>& nums) {
			int n=nums.size();
			int l=0,r=n-1;
			while(l<r){
				int mid=l+(r-l)/2;
				if(mid%2==1){//mid处为奇数,奇数的话就和前面一位去比较
					if(nums[mid]!=nums[mid-1])
						r=mid;
					else
						l=mid+1;
				}
				else{//mid处为偶数，偶数的话就和后面一位去比较
					if(nums[mid]!=nums[mid+1])
						r=mid;
					else
						l=mid+1;
				}
			}
			return nums[l];
		}
};
