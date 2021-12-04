#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkInclusion(string s1,string s2)
{
	if(s1.length() > s2.length())return false;

	vector<int> hash(26,0),hashZero(26,0);

	for(int i = 0; i < s1.length(); i++)
	{
		hash[s1[i] - 'a']++;
		hash[s2[i] - 'a']--;
	}

	if(hash == hashZero) return true;
	for(int i = s1.length(); i < s2.length(); i++)
	{
		hash[s2[i] - 'a']--;
		hash[s2[i - s1.length()] - 'a']++;
		if(hash == hashZero) return true;
	}
	return false;
}

int main()
{
	string s1 = "ab";
	string s2 = "eidbaooo";

	cout << checkInclusion(s1,s2) << endl;
	 
	return 0;
}
