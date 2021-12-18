class MyCalendar {
	private:
		map<int, int> hash;

	public:
		MyCalendar() {}

		bool book(int start, int end) {
			map<int, int>::iterator event = hash.lower_bound(start);

			//当前迭代器存在，并且迭代器左边界小于待插入日程的右边界
			if (event != hash.end() && event->first < end) return false;

			//上一迭代器存在，并且迭代器右边界大于待插入日程的左边界
			if (event != hash.begin() && ( -- event)->second > start) return false;

			hash[start] = end;

			return true;
		}
};
