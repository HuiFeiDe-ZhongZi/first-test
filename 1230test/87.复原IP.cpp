class Solution {
	public:
		vector<string> res; //记录结果

		void backtracking(string& s,int startIndex,int pointNum)
		{
			if(pointNum == 3)// 逗点数量为3时 开始判断最后一段字符是否合法
			{
				if(isValid(s,startIndex,s.size() - 1))
				{
					res.push_back(s);
				}
				return;
			}

			for(int i = startIndex; i < s.size(); i++)
			{
				if(isValid(s,startIndex,i))
				{
					s.insert(s.begin() + i + 1,'.');
					pointNum++;
					backtracking(s,i + 2,pointNum);
					pointNum--;
					s.erase(s.begin() + i + 1);
				}
				else break;
			}
		}

		bool isValid(const string& s,int start,int end)
		{
			if(start > end)
			{
				return false;
			}
			if(s[start] == '0' && start != end) // 不能含有前导0
			{
				return false;
			}

			int num = 0;
			for(int i = start; i <= end; i++)
			{
				num = num*10 + (s[i] - '0'); // 每个整数位于0-255之间
				if(num > 255)
				{
					return false;
				}
			}

			return true;
		}
		vector<string> restoreIpAddresses(string s) {
			if(s.size() > 12) return res;
			backtracking(s,0,0);
			return res;
		}
};
