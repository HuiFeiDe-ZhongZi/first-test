class Solution {
	public:
		int count = 0;
		int pathSum(TreeNode* root, int targetSum) {
			if(root == NULL) return 0;

			dfs(root,targetSum); // 以root为起点查找路径
			pathSum(root->left,targetSum); // 左子树递归
			pathSum(root->right,targetSum); // 右子树递归
			return count;
		}

		void dfs(TreeNode* root,int sum)
		{
			if(root == NULL) return;

			sum -= root->val;
			if(sum == 0)    
				count++;
			dfs(root->left,sum);
			dfs(root->right,sum);
		}

};
