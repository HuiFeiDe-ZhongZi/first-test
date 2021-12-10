#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	unordered_map<string,vector<string>> hash;

	for(string& s:strs)      // 遍历每个单词
	{
		string tmp = s;      
		sort(tmp.begin(),tmp.end());    // 将当前单词内的字母排序
		hash[tmp].push_back(s);         // 将原始单词存入属于它的异位词组中
	}                                   // hash[tmp] 表示tmp这组异位词的集合    

	for(auto & vec:hash)                // 遍历哈希表，将值存入结果集合中
	{
		res.push_back(vec.second);
	}

	return res;
}

int main()
{
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> res = groupAnagrams(strs);
	for(auto a:res)
	{
		for(int i = 0; i < a.size();i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}


	return 0;
}
