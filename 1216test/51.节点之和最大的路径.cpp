class Solution {
	public:
		int maxPathSum(TreeNode* root) {
			int maxSum = INT_MIN;
			dfs(root,maxSum);
			return maxSum;
		}

		int dfs(TreeNode *root,int& maxSum)
		{
			if(root == NULL) return 0;

			int left = max(0,dfs(root->left,maxSum)); // 若当前子树和小于0，则不选当前子树所在的路径，于是取0
			int right = max(0,dfs(root->right,maxSum));

			maxSum = max(maxSum,root->val + left + right); // 路径同时经过当前节点左右子树的情况
			return root->val + max(left,right);  // 函数的返回值是经过当前节点root并前往其左子树或右子树的路径的节点值之和的最大值
		}
};
