class CBTInserter{
	private:
		TreeNode *root;
		queue<TreeNode*> q;
	public:
		CBTInserter(TreeNode* root) {
			this->root = root;
			q.push(root);
			while(q.front()->left && q.front()->right) // 队列中留存的：要么左，要么右没有分支   跳出while为不满二叉树 可以进行添加
			{
				TreeNode *tmp = q.front();
				q.push(tmp->left);
				q.push(tmp->right); 
				q.pop();
			}
		}

		int insert(int v) {
			TreeNode *parent = q.front();
			TreeNode *pNode = new TreeNode(v);

			if(parent->left == NULL)
			{
				parent->left = pNode;  
			}
			else
			{
				parent->right = pNode;
				q.push(parent->left);
				q.push(parent->right);
				q.pop();  
			}

			return parent->val;
		}

		TreeNode* get_root() {
			return root;
		}
};

