#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSorted(string& word1,string& word2,vector<int>& orderArray)
{
	int i = 0;
	for(i; i < word1.size() && i < word2.size(); i++)
	{
		if(orderArray[word1[i] - 'a'] > orderArray[word2[i] - 'a'])
		{
			return false;
		}
		if(orderArray[word1[i] - 'a'] < orderArray[word2[i] - 'a'])
		{
			return true;
		}
	}

	return i == word1.size();
}

bool isAlienSorted(vector<string>& words, string order) {
	vector<int> orderArray(26,0);
	for(int i = 0; i < order.size();i++)
	{
		orderArray[order[i] - 'a'] = i;
	}

	for(int i = 0; i < words.size() - 1; i++)
	{
		if(!isSorted(words[i],words[i+1],orderArray))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	vector<string> words = {"hello","leetcode"};
	string order = "hlabcdefgijmnopqrstuvwxyz";
	cout<< isAlienSorted(words,order)<< endl;

	return 0;
}
