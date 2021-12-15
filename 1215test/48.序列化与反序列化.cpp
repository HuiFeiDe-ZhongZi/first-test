class Codec {
	public:

		// Encodes a tree to a single string.
		string res; 
		string serialize(TreeNode* root) {
			dfs(root);
			return res;   
		}

		void dfs(TreeNode* root)                    //用前序遍历的方式序列化二叉树
		{
			if (!root) res += "NULL,";              //空节点存入NULL字符串
			else
			{
				res += to_string(root->val) + ',';  //非空节点存入字符串数值
				dfs(root->left);                    //这里也可以用中序或后序
				dfs(root->right);                   //只要保证反序列化时也用同样的方式即可
			}
		}

        // Decodes your encoded data to tree.
		queue<string> que;  
		TreeNode* deserialize(string data) {      //反序列化阶段
			int i = 0;                            //用双指针按照逗号来分割字符串        
			int j = 0;                            //以逗号分割字符串，存入队列q中
			while(i < data.size())
			{
				while(data[i] != ',' && i < data.size()) i++;
				string tmp = data.substr(j,i - j);
				que.push(tmp);
				i++;
				j = i;
			}

			return de_dfs();
		}

		TreeNode *de_dfs()
		{
			auto t = que.front();
			que.pop();

			if(t == "NULL") return NULL;

			TreeNode *root = new TreeNode(stoi(t)); 
			root->left = de_dfs();
			root->right = de_dfs();

			return root;
		}
};
