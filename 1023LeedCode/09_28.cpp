#include<iostream>
#include<vector>
using namespace std;


// j：前缀末尾及相等子串最大长度 i：后缀末尾 
void getNext(int *next,string s)
{
	// 1.初始化
	int j = 0;
	next[0] = 0;
	for(int i = 1; i < s.size(); i++)
	{
		// 2.前后缀不相同
		while(j > 0 && s[i] != s[j])
		{
			j = next[j-1];
		}
		// 3.前后缀相同
		if(s[i] == s[j]) j++;
		// 4.更新next的值
		next[i] = j;
	}
}


int strStr(string haystack,string neddle)
{
	if(neddle.size() == 0)
		return 0;
	int next[neddle.size()];
	getNext(next,neddle);
	
	// 字符串匹配
	int j = 0;
	for(int i = 0; i < haystack.size(); i++)
	{
		while(j > 0 && haystack[i] != neddle[j])
		{
			j = next[j - 1];
		}
		if(haystack[i] == neddle[j]) j++;

		if(j == neddle.size())
		{
			return (i - neddle.size() + 1);
		}
	}
	return -1;
}

int main()
{
	string haystack = "hello";
	string neddle = "el";
	int a = strStr(haystack,neddle);
	cout<< a << endl;

	return 0;
}

