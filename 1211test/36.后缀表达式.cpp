#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> st;
	for(int i = 0; i < tokens.size(); i++)
	{
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||  tokens[i] == "/")
		{
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			if(tokens[i] == "+") st.push(num2 + num1);  // 运算时必须为nums2在前num1在后
			if(tokens[i] == "-") st.push(num2 - num1);
			if(tokens[i] == "*") st.push(num2 * num1);
			if(tokens[i] == "/") st.push(num2 / num1);
		}
		else
		{
			st.push(stoi(tokens[i]));
		}
	}
	int res = st.top();
	st.pop();
	return res;
}
int main()
{
	vector<string> tokens = {"2","1","+","3","*"};

	cout<< evalRPN(tokens) << endl;


	return 0;
}
