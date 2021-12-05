#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string minWindow(string s, string t) {
	int sLen = s.length();
	int tLen = t.length();
	if(sLen < tLen) return "";

	int left = 0; 
	int right = 0;
	int len = 0; // 当前符合条件的长度
	string res;
	unordered_map<char,int> mps,mpt; // mpt统计t中字符的数量 mps统计滑动窗口中字符的数量
	for(int i = 0; i < t.size(); i++)
	{
		mpt[t[i]]++;
	}
	for(;right < s.size(); right++)
	{
		mps[s[right]]++;
		if(mps[s[right]] <= mpt[s[right]]) len++;
		while(mps[s[left]] > mpt[s[left]]) 
		{
			mps[s[left++]]--;
		}
		if (len == t.size())
		{
			if (res == "" || res.size() > right - left+1) res = s.substr(left, right - left + 1);
		}
	}
	return res;
}

int main()
{

	string s = "ADOBECODEBANC";
	string t = "ABC";
	
	cout << minWindow(s,t) << endl;
	return 0;
}
