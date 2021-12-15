class Solution {
	public:
		TreeNode* pruneTree(TreeNode* root) {
			if(root == NULL) return NULL;

			TreeNode* left = pruneTree(root->left);
			TreeNode* right = pruneTree(root->right);

			if(root->val == 0 && left == NULL && right == NULL)  // 当左右节点都为空且当前节点的值为0的情况下，即可减枝
			{
				return NULL;
			}

			root->left = left;
			root->right = right;
			return root;
		}
};
