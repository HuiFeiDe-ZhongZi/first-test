#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int divide(int a ,int b)
{
	// 特殊情况
	if(a == INT_MIN && b == -1)return INT_MAX;

	// 判断整数还是负数
	int flag = (a > 0) ^ (b > 0)? -1 : 1;

	unsigned int x = abs(a);
	unsigned int y = abs(b);
	unsigned int res = 0;

	for(int i = 31;i >= 0;i++)
	{
		if((x>>i) > y)
		{
			x = x - (y << i);
			res += 1 << i;
		}
	}
	
	return flag == 1 ? res : -res;

}

int main()
{
	int a = 15;
	int b = 2;

	cout << divide(a,b) << endl;
	return 0;
}
