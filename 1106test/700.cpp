class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL || root->val == val) return root;

		if (root->val > val) return searchBST(root->left, val);
		if (root->val < val) return searchBST(root->right, val);
		return NULL;
	}
};
// 因为搜索到目标节点了，就要立即return了，这样才是找到节点就返回（搜索某一条边），如果不加return，就是遍历整棵树了。
// 根为空 或者节点找到了 立即返回本节点
// 否则比较大小 看是走左子树 还是右子树