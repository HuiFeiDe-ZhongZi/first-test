class BSTIterator {
	public:
		stack<TreeNode*> st;
		BSTIterator(TreeNode* root) {
			inorder(root);
		}

		void inorder(TreeNode *root)
		{
			while(root != NULL)
			{
				st.push(root);       // 保存沿路的左子树
				root = root->left;
			}
		}

		int next() {
			TreeNode *tmp = st.top();
			st.pop();

			if(tmp->right != NULL)
			{
				inorder(tmp->right);   // 中序遍历下一节点的右子树
			}
			return tmp->val;
		}

		bool hasNext() {
			return !st.empty();
		}
};
