class Solution {
	private:
		TreeNode *res = NULL;
		bool flag = false;
	public:
		TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
			dfs(root,p);
			return res;
		}
		void dfs(TreeNode *root,TreeNode *p)
		{
			if(root == NULL) return;

			dfs(root->left,p);
			if(root->val == p->val)
			{
				flag = true;
			}
			else if(flag == true)
			{
				res = root;
				flag = false;
				return;
			}
			dfs(root->right,p);
		}
};

// 中序遍历 建立标记  记录下一个节点
