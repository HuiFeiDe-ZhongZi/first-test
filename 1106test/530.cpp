
// 方法1：
class Solution {
public:
	// 中序遍历
	vector<int> res;
	void traversal(TreeNode *root)
	{
		if (root == NULL) return;
		traversal(root->left);
		res.push_back(root->val);
		traversal(root->right);
	}
	int getMinimumDifference(TreeNode* root) {
		traversal(root);
		if (res.size() < 2) return 0;
		int result = INT_MAX;
		for (int i = 1; i < res.size(); i++)
		{
			result = min(result, res[i] - res[i - 1]);
		}
		return result;
	}
};

// 平衡二叉树在求差值 最值之类的 要时刻想到用中序 遍历 在做其他操作

// 方法2：
class Solution {
public:
	TreeNode *pre;
	int res = INT_MAX;
	void traversal(TreeNode *cur)
	{
		if (cur == NULL) return;
		traversal(cur->left);  // 左
		if (pre != NULL)        // 中
		{
			res = min(res, cur->val - pre->val);
		}
		pre = cur;
		traversal(cur->right);  // 右
	}
	int getMinimumDifference(TreeNode* root) {
		traversal(root);
		return res;
	}
};