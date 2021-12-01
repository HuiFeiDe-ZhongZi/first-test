int maxProduct(vector<string>& words) {
	vector<int> hash(words.size(), 0);
	for (int i = 0; i < words.size(); ++i) {
		for (const char& ch : words[i]) {
			hash[i] |= 1 << (ch - 'a');
		}
	}
	int ret = 0;
	for (int i = 0; i < words.size(); ++i) {
		for (int j = i + 1; j < words.size(); ++j) {
			// 位操作优先级低，一定要加括号
			if ((hash[i] & hash[j]) == 0) {
				int cur = words[i].size() * words[j].size();
				ret = max(ret, cur);
			}
		}
	}
	return ret;
}
