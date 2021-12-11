#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
	stack<int> st;

	for(int tmp: asteroids)
	{
		while(!st.empty() && st.top() > 0 && st.top() < -tmp)
		{
			st.pop();
		}

		if(!st.empty() && tmp < 0 && st.top() == -tmp)
		{
			st.pop();
		}
		else if(tmp > 0 || st.empty() || st.top() < 0)
		{
			st.push(tmp);
		}
	}

	int size = st.size();
	vector<int> res(size,0);
	for(int i = 0; i < size; i++)
	{
		res[size - 1 -i] = st.top();
		st.pop();
	}
	return res;
}

int main()
{
	vector<int> asteroids = {5,10,-5};

	vector<int> res = asteroidCollision(asteroids);

	for(int i: res)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
}
