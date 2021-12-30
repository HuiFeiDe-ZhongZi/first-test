class Solution {
	public:
		vector<string> res;
		string s;

		void backtracking(int head,int end)
		{
			if(head == 0 && end ==0)
			{
				res.push_back(s);
				return;
			}

			if(head > 0)
			{
				s.push_back('(');
				backtracking(head - 1,end);
				s.pop_back();
			}
			if(head < end)
			{
				s.push_back(')');
				backtracking(head,end - 1);
				s.pop_back();
			}
		}
		vector<string> generateParenthesis(int n) {
			int head = n;
			int end = n;
			backtracking(head,end);
			return res;
		}
};

