
// ����1��
class Solution {
public:
	// �������
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

// ƽ������������ֵ ��ֵ֮��� Ҫʱ���뵽������ ���� ������������

// ����2��
class Solution {
public:
	TreeNode *pre;
	int res = INT_MAX;
	void traversal(TreeNode *cur)
	{
		if (cur == NULL) return;
		traversal(cur->left);  // ��
		if (pre != NULL)        // ��
		{
			res = min(res, cur->val - pre->val);
		}
		pre = cur;
		traversal(cur->right);  // ��
	}
	int getMinimumDifference(TreeNode* root) {
		traversal(root);
		return res;
	}
};