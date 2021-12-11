#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> res(temperatures.size(),0);
	stack<int> st;

	for(int i = 0; i < temperatures.size(); i++)
	{
		while(!st.empty() && temperatures[i] > temperatures[st.top()])
		{
			int prev = st.top();
			st.pop();
			res[prev] = i - prev;
		}

		st.push(i);
	}

	return res;
}

int main()
{
	vector<int> temperatures = {73,74,75,71,69,72,76,73};

	vector<int> res = dailyTemperatures(temperatures);

	for(int i: res)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
}
