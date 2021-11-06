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

// ������������������ 
// �Ƚ��������ڵ� �Ƿ����� �Ϳ����жϳ��Ƿ��Ƕ���������