#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int maxDiffTime = 1440; // 24小时及1440分钟

int comper(bool minuteFlags[])
{
	int minDiff = maxDiffTime - 1;
	int prev = -1;  // 记录上一次时间与cur(当前时间) 相减
	int first = maxDiffTime - 1; // 数组中最早的时间 
	int last = -1; // 数组中最晚的时间 主要是为了计算00:00 与 26:59这类情况

	for(int cur = 0; cur < maxDiffTime; cur++)
	{
		if(minuteFlags[cur])
		{
			if(prev >= 0) minDiff = min(minDiff,cur - prev);

			prev = cur;  // 保存的上一个节点值
			first = min(first,cur);
			last = max(last,cur);
		}
	}
	minDiff = min(minDiff,first + maxDiffTime - last); // 0 + 1440 - 1439
	return minDiff;
}
int findMinDifference(vector<string>& timePoints) {
	if(timePoints.size() > maxDiffTime) return 0;

	bool minuteFlags[1440] = {0};
	for(string& time: timePoints) // 将时间转换为总的分钟数
	{
		int minute = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
		if(minuteFlags[minute]) return 0;
		minuteFlags[minute] = true;
	}

	return comper(minuteFlags);
}
int main()
{
	//vector<string> timePoints = {"23:59","00:00"};
	vector<string> timePoints = {"00:00","23:59","00:00"};
	cout << findMinDifference(timePoints) << endl;

	return 0;
}
