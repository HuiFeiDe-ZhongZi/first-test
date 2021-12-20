class Trie{
	public:
		bool isWord;
		vector<Trie*> children;
		Trie():isWord(false),children(26){ }

		void insert(const string& str)
		{
			Trie *node = this;
			for(auto& ch: str)
			{
				if(node->children[ch - 'a'] == NULL)
				{
					node->children[ch - 'a'] = new Trie();
				}
				node = node->children[ch - 'a'];
			}
			node->isWord = true;
		}
};

class MagicDictionary {
	private:
		Trie* root;
		bool dfs(Trie* root, string& word, int i, int edit) {
			if (root == nullptr) {
				return false;
			}

			if (root->isWord && i == word.size() && edit == 1) {
				return true;
			}

			if (i < word.size() && edit <= 1) {
				bool found = false;
				for (int j = 0; j < 26 && !found; ++j) {
					int next = (j == word[i] - 'a') ? edit : edit + 1;
					found = dfs(root->children[j], word, i + 1, next);
				}

				return found;
			}

			return false;
		}

	public:
		/** Initialize your data structure here. */
		MagicDictionary() {
			root = new Trie();
		}

		void buildDict(vector<string> dictionary) {
			for (auto& word : dictionary) {
				root->insert(word);
			}
		}

		bool search(string searchWord) {
			return dfs(root, searchWord, 0, 0);
		}
};
