#include<iostream>
#include<string>
using namespace std;

string replaceSpace(string s)
{
	int count = 0;
	int oldSize = s.size();
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ' ')
		{
			count++;
		}
	}
	s.resize(s.size() + 2*count);
	int newSize = s.size();

	for(int i = newSize-1,j = oldSize-1;j<i;i--,j--)
	{
		if(s[j] != ' ')
		{
			s[i] = s[j];
		}
		else
		{
			s[i] = '0';
			s[i-1] = '2';
			s[i-2] = '%';
			i-=2;
		}
	}
	return s;
}
			

int main()
{
	string s = "We are happy";
	string p = replaceSpace(s);
	for(int i = 0; i<p.size(); i++)
	{
		cout<<p[i];
	}
	cout<<endl;


	return 0;
}
