class Solution {
	public:
		void midOrder(TreeNode *root,vector<int>& res)
		{
			if(root == NULL) return;

			midOrder(root->left,res);
			res.push_back(root->val);
			midOrder(root->right,res);
		}
		TreeNode* increasingBST(TreeNode* root) {
			vector<int> res;
			midOrder(root,res);

			TreeNode *dummy = new TreeNode(0);
			TreeNode *p = dummy;
			for(int i = 0; i < res.size(); i++)
			{
				TreeNode *tmp = new TreeNode(res[i]);
				p->right = tmp;    // 头的下一个 等于新来的  头指向新来的
				p = tmp;
			}
			return dummy->right;
		}
};
