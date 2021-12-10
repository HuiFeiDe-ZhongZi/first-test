unordered_map<int,int> hash;
vector<int> nums;

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool insert(int val) {
	if(hash.count(val)) return false;

	hash[val] = nums.size();  // 哈希表的键所是数值，值是数值在数组中的位置
	nums.push_back(val);      //  数值放入数组中
	return true;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool remove(int val) {
	if(!hash.count(val)) return false; 
	nums[hash[val]] = nums.back();   // 将数组尾部的数值放到待删除数组的位置
	hash[nums.back()] = hash[val];   // 在哈希表中更新原数组尾部数值的位置
	hash.erase(val);                 // 从哈希表中删除该数值
	nums.pop_back();                 // 从数组中删除该数值
	return true;
}

/** Get a random element from the set. */
int getRandom() {
	return nums[rand() % nums.size()]; // 采取随机数 随机返回集合内任一数值
}



