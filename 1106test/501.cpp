class Solution {
public:
	int maxCount; // ���Ƶ��
	int count; // ͳ��Ƶ��
	TreeNode *pre;
	vector<int> res;
	void traversal(TreeNode *root)
	{
		if (root == NULL) return;
		traversal(root->left);  // ��

		if (pre == NULL)         // �� ��һ���ڵ�
		{
			count = 1;
		}
		else if (pre->val == root->val)  // ��ǰһ���ڵ�����ͬ
		{
			count++;
		}
		else // ��ǰһ���ڵ�����ͬ
		{
			count = 1;
		}
		pre = root;

		if (count == maxCount) // ������ֵ��ͬ���룬����res
		{
			res.push_back(root->val);
		}

		if (count > maxCount) // ��ǰ�����������Ƶ�� �������Ƶ��
		{
			maxCount = count;
			res.clear(); // ���ԭ����ߵ���ֵ
			res.push_back(root->val);
		}

		traversal(root->right);  // ��
	}
	vector<int> findMode(TreeNode* root) {
		count = 0;
		maxCount = 0;
		pre = NULL; // ��¼ǰһ���ڵ�
		res.clear();

		traversal(root);
		return res;


	}
};