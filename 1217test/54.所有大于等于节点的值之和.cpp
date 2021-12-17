class Solution {
	public:
		TreeNode* convertBST(TreeNode* root) {
			int sum = 0;    // //sum表示大于等于当前节点值的所有节点值之和
			dfs(root,sum);
			return root;
		}
		void dfs(TreeNode* root,int &sum)
		{
			if(root == NULL) return;

			dfs(root->right,sum);

			sum += root->val;   //累加当前节点值
			root->val = sum;    //再赋值给当前节点


			dfs(root->left,sum);
		}
};
