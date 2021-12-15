class Solution {
	public:
		int sumNumbers(TreeNode* root) {
			return dfs(root,0);
		}

		int dfs(TreeNode *root,int path)
		{
			if(root == NULL)
			{
				return 0;
			}

			path = path * 10 + root->val;

			if(root->left == NULL && root->right == NULL)
			{
				return path;
			}

			return dfs(root->left,path) + dfs(root->right,path);
		}
};


