#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> findAnagrams(string p,string s)
{
	vector<int> hash(26,0),hashZero(26,0);
	vector<int> res;
	if(s.length() > p.length())return res;

	for(int i = 0; i < s.length(); i++)
	{
		hash[s[i] - 'a']++;
		hash[p[i] - 'a']--;
	}

	if(hash == hashZero) res.push_back(0);
	for(int i = s.length(); i < p.length(); i++)
	{
		hash[p[i] - 'a']--;
		hash[p[i - s.length()] - 'a']++;
		if(hash == hashZero) res.push_back(i - s.length() + 1);
	}
	return res;
}


int main()
{
	string s = "cbaebabacd";
	string p = "abc";

	vector<int> res = findAnagrams(s,p);
	for(int a : res)
	{
		cout << a << endl;
	}


	return 0;
}
