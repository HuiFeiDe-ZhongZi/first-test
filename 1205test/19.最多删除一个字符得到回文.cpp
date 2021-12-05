#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalinedrome(string& s, int left, int right)
{
	while(left < right)
	{
		if(s[left++] != s[right--])
			return false;
	}
	return true;
}
bool validPalindrome(string s) {
	int left = 0;
	int right = s.length() - 1;
	while(left < right)
	{
		if(s[left] != s[right])
		{
			// 如果不相等，则分两种情况 删除左边的元素，或者右边的元素
			//                 // 在判断各自是否回文，满足一种情况即可
			return isPalinedrome(s,left+1,right) || isPalinedrome(s,left,right-1);
		}
		left++;
		right--;
	}
	return true;
}
int main()
{
	string s = "aba";
	cout<<validPalindrome(s)<<endl;
	return 0;
}
