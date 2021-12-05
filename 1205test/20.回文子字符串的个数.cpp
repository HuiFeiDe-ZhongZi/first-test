#include<iostream>
#include<string>
using namespace std;


int extend(const string &s,int i,int j,int n)
{
	int res = 0;
	while(i >= 0 && j < n && s[i] == s[j])
	{
		i--;
		j++;
		res++;
	}
	return res;
}
int countSubstrings(string s) {
	int result = 0;
	for(int i = 0; i < s.size(); i++)
	{
		result += extend(s,i,i,s.size());
		result += extend(s,i,i+1,s.size());
	}
	return result;
}
int main()
{
	string s = "abc";
	cout<<countSubstrings(s)<<endl;
	return 0;
}
