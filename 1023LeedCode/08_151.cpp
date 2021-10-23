#include<iostream>
#include<string>
using namespace std;


// 1.移除多余空格
void removeExtraSpace(string& s)
{
	int slow = 0;
	int fast = 0;
	// 1.去掉字符串前面的空格
	while(0 < s.size() && fast < s.size() && s[fast] == ' ')
	{
		fast++;
	}
	// 2.去字符串中间的空格
	for(;fast < s.size();fast++)
	{
		if(fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
		{
			continue;
		}
		else
		{
			s[slow++] = s[fast];
		}
	}
	// 3.去掉字符串末尾的空格
	if(slow - 1 > 0 && s[slow - 1] == ' ')
	{
		s.resize(slow - 1);
	}
	else
	{
		s.resize(slow);
	}
}

// 2.将整个字符串翻转
void reverse(string& s,int start,int end)
{
	for(int i = start, j = end; i < j; i++, j--)
	{
		swap(s[i],s[j]);
	}
}

string reverseWords(string s)
{
	removeExtraSpace(s);
	reverse(s,0,s.size()-1);
	for(int i = 0; i < s.size(); i++)
	{
		int j = i;
		while(j < s.size() && s[j] != ' ') j++;
		reverse(s,i,j - 1);
		i = j;
	}
	return s;
}



int main()
{
	string s = "the sky is blue";
	string p = reverseWords(s);
	for(int i = 0; i < p.size(); i++)
	{
		cout<< p[i];
	}
	cout<<endl;

	return 0;
}



