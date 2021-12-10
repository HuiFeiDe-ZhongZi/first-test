#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string s,string t)
{
	if(s.size() != t.size() || s == t) return false;

	vector<int> hash(26,0);

	for(int i = 0; i < s.size(); i++)
	{
		hash[s[i] - 'a']++;
	}

	for(int i = 0; i < t.size(); i++)
	{
		if(hash[t[i]-'a']== 0)return false;
		hash[t[i]-'a']--;
	}
	return true;
}


int main()
{
	string s = "anagram";
	string t = "nagaram";

	cout << isAnagram(s,t) << endl;

	return 0;
}
