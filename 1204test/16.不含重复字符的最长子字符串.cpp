#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

int lengthOfLongetSubstring(string s)
{
	int n = s.length();
	if(n <= 1) return n;

	int maxLen = 0;
	int left = 0;
	int right = 0;
	unordered_set<char> res;
	while(right < n)
	{
		if(!res.count(s[right]))
		{
			maxLen = max(maxLen,right - left + 1);
			res.insert(s[right]);
			right++;
		}
		else
		{
			res.erase(s[left]);
			left++;
		}
	}
	return maxLen;
}

int main()
{
	string s = "abcabcbb";
	cout << lengthOfLongetSubstring(s) << endl;

	return 0;
}
