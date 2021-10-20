#include<iostream>
#include<string>
using namespace std;


bool isAnagram(string s,string t)
{
	int record[26] = {0};
	for(int i = 0;i < s.size();i++)
	{
		record[s[i]-'a']++;
	}
	for(int i = 0;i < t.size();i++)
	{
		record[t[i]-'a']--;
	}
	for(int i = 0;i < 26;i++)
	{
		if(record[i] != 0)
		{
			return false;
		}
	}
	return true;
}




int main()
{
	string s = "anagram";
	string t = "nagaram";
	bool a = isAnagram(s,t);
	if(a)
	{
		cout << "true"<<endl;
	}
	else 
	{
		cout << "false"<<endl;
	}

	return 0;
}
