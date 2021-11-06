class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL || root->val == val) return root;

		if (root->val > val) return searchBST(root->left, val);
		if (root->val < val) return searchBST(root->right, val);
		return NULL;
	}
};
// ��Ϊ������Ŀ��ڵ��ˣ���Ҫ����return�ˣ����������ҵ��ڵ�ͷ��أ�����ĳһ���ߣ����������return�����Ǳ����������ˡ�
// ��Ϊ�� ���߽ڵ��ҵ��� �������ر��ڵ�
// ����Ƚϴ�С ������������ ����������