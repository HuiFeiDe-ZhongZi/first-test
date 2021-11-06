class Solution {
public:
	vector<int> res;
	void traversal(TreeNode* root)
	{
		if (root == NULL) return;
		traversal(root->left);
		res.push_back(root->val);
		traversal(root->right);
	}
	bool isValidBST(TreeNode* root) {
		traversal(root);
		for (int i = 1; i < res.size(); i++)
		{
			if (res[i] <= res[i - 1]) return false;
		}
		return true;
	}
};

// 中序遍历出来是有序的 
// 比较相邻两节点 是否都有序 就可以判断出是否是二叉搜索树