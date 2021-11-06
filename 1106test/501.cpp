class Solution {
public:
	int maxCount; // 最大频率
	int count; // 统计频率
	TreeNode *pre;
	vector<int> res;
	void traversal(TreeNode *root)
	{
		if (root == NULL) return;
		traversal(root->left);  // 左

		if (pre == NULL)         // 根 第一个节点
		{
			count = 1;
		}
		else if (pre->val == root->val)  // 与前一个节点数相同
		{
			count++;
		}
		else // 与前一个节点数不同
		{
			count = 1;
		}
		pre = root;

		if (count == maxCount) // 如果最大值相同放入，放入res
		{
			res.push_back(root->val);
		}

		if (count > maxCount) // 当前计数大于最大频率 更新最大频率
		{
			maxCount = count;
			res.clear(); // 清空原来里边的数值
			res.push_back(root->val);
		}

		traversal(root->right);  // 右
	}
	vector<int> findMode(TreeNode* root) {
		count = 0;
		maxCount = 0;
		pre = NULL; // 记录前一个节点
		res.clear();

		traversal(root);
		return res;


	}
};