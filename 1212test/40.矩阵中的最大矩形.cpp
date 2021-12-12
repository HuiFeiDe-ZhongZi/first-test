#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	stack<int> st;
	st.push(-1);  // 第一根柱子的下标是0，所以第一根柱子左侧的下标应该是-1

	int maxArea = 0;
	for(int i = 0; i < heights.size(); i++)
	{
		while(st.top() != -1 && heights[i] < heights[st.top()])  // 栈不为空，且当前柱子高度小于栈顶柱子高度时，计算栈顶柱子所表示的矩形的最大面积
		{
			int height = heights[st.top()];
			st.pop();
			int width = i - st.top() -1;
			maxArea = max(maxArea,height * width);
		}

		st.push(i);
	}

	while(st.top() != -1)   // 遍历一遍后，若栈中还有剩余的柱子，则表示他们右侧已经没有更矮的柱子了
	{
		int height = heights[st.top()];
		st.pop();
		int width = heights.size() - st.top() - 1;
		maxArea = max(maxArea,height * width);
	}
	return maxArea;
}


int maximalRectangle(vector<string>& matrix) {
	if(matrix.empty()) return 0;

	int maxArea = 0;
	vector<int> heights(matrix[0].size(),0); 

	for(string& row: matrix)
	{
		for(int i = 0; i < row.size(); i++)
		{
			if(row[i] == '0') heights[i] = 0;  // 当前格子为0，则它所在的柱子高度为0
			else heights[i]++;                 // 格子为1，则它的高度为上一行同位置高度+1
		}
		maxArea = max(maxArea,largestRectangleArea(heights));
	}
	return maxArea;
}

int main()
{

	vector<string> matrix = {"10100","10111","11111","10010"};

	cout << maximalRectangle(matrix) << endl;


	return 0;
}
