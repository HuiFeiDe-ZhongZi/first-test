class Node{
	public:
		bool isRoot;
		vector<Node*> next;
		Node():isRoot(false),next(26){}
};

class Solution {
	public:

		void insert(const string &s,Node *root)
		{
			int size = s.size();
			Node *cur = root;
			for(int i = 0; i < size; i++)
			{
				if(cur->next[s[i] - 'a'] == NULL) cur->next[s[i] - 'a'] = new Node();
				cur = cur->next[s[i] - 'a'];
			}
			cur->isRoot = true;
		}

		string replaceWords(vector<string>& dictionary, string sentence) {
			Node *root = new Node();
			int sizeDic = dictionary.size();
			for(int i = 0; i < sizeDic; i++)
			{
				insert(dictionary[i],root);
			}

			vector<string> sentenceV = splitSentence(sentence);    
			string ans="";
			int sentenceWordsNum=sentenceV.size();

			for(int i=0;i<sentenceWordsNum;i++){
				Node *cur=root;
				int wordsLength=sentenceV[i].size();
				string words=sentenceV[i];
				for(int j=0;j<wordsLength;j++){
					if(!cur->next[words[j]-'a']){
						for(int k=j;k<wordsLength;k++){
							ans+=words[k];
						}
						break;
					}
					if(cur->next[words[j]-'a']->isRoot){
						ans+=words[j];
						break;
					}
					ans+=words[j];
					cur=cur->next[words[j]-'a'];
				}
				if(i<sentenceWordsNum-1) ans+=" ";
			}

			return ans;

		}

		vector<string> splitSentence(const string &s)
		{
			int size = s.size();
			int num = 0;
			vector<string> sentenceV;
			string temp;
			for(int i = 0; i <= size; i++)
			{
				if(s[i] == ' '||i == size)
				{
					sentenceV.emplace_back(temp);
					temp.clear();
					continue;
				}
				temp+=s[i];
			}
			return sentenceV;
		}
};
