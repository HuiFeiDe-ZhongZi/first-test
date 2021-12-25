class Solution {
	public:
		vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
			vector<int> map(1001,0);

			int idx = 0;
			for(int &num :arr1) map[num]++;
			for(int &num :arr2)
			{
				while(map[num] > 0)
				{
					arr1[idx++] = num;
					map[num]--;
				}
			}

			for(int i = 0; i < map.size(); i++)
			{
				while(map[i] > 0)
				{
					arr1[idx++] = i;
					map[i]--;
				}
			}

			return arr1;
		}
};
