#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addBinary(string a,string b)
{
	string res = "";
	int l1 = a.length()-1;
	int l2 = b.length()-1;
	int carry = 0;

	while(l1 >= 0 || l2 >= 0)
	{
		int x = l1 < 0? 0 :a[l1]-'0';
		int y = l2 < 0? 0 :b[l2]-'0';
		
		int sum = x + y + carry;
		res.push_back('0' + sum%2);
		carry = sum/2;
		
		l1--;
		l2--;
	}
	if(carry)res.push_back(carry+'0');
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	string a = "11";
	string b = "10";
	cout<<addBinary(a,b)<<endl;

	return 0;
}
