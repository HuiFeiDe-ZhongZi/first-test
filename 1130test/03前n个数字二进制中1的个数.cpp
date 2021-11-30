#include<iostream>
#include<vector>
using namespace std;

vector<int> coutBits(int n)
{
	vector<int> res(n+1,0);

	for(int i = 1; i<=n;i++)
	{
		res[i] = res[i>>1]+(i&1);
	}
	return res;
}
int main()
{

	int n =5;
	vector<int> res = coutBits(n);
	for(int a: res)
	{
		cout << a <<endl;
	}
	return 0;
}
