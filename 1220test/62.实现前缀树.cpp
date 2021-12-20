class Trie {
	public:
		/** Initialize your data structure here. */
		vector<Trie*> children;
		bool isEnd;
		Trie():children(26),isEnd(false) 
	{

	}

		/** Inserts a word into the trie. */
		void insert(string word) {
			Trie * node = this;
			for(char & c : word)
			{
				if(node->children[c - 'a'] == NULL) // 子节点不存在，创建一个新的子节点，记录在children数组的对应位置上,然后沿着指针移动到子节点，继续搜索下一个字符
				{
					node->children[c - 'a'] = new Trie;
				}
				node = node->children[c - 'a']; // 相当于新来的等于头
			}
			node->isEnd = true;
		}

		/** Returns if the word is in the trie. */
		bool search(string word) {
			Trie *node = this;
			for(char & c : word)
			{
				node = node->children[c - 'a'];
				if(node == NULL)
				{
					return false;
				}
			}
			return node->isEnd;
		}

		/** Returns if there is any word in the trie that starts with the given prefix. */
		bool startsWith(string prefix) {
			Trie *node = this;
			for(char & c : prefix)
			{
				node = node->children[c - 'a'];
				if(node == NULL)
				{
					return false;
				}
			}
			return true;
		}
};
