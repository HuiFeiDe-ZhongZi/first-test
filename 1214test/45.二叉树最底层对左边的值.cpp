#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode *CreateTree()
{
	TreeNode *pTree = NULL;

	// 根
	pTree = (TreeNode*)malloc(sizeof(TreeNode));
	pTree->val = 2;

	// 根的左
	pTree->left = (TreeNode*)malloc(sizeof(TreeNode));
	pTree->left->val = 1;
	pTree->left->left = NULL;
	pTree->left->right = NULL;
	pTree->right = (TreeNode*)malloc(sizeof(TreeNode));
	pTree->right->val = 3;
	pTree->right->left = NULL;
	pTree->right->right = NULL;

	return pTree;
}

int findBottomLeftValue(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	int result = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (i == 0) result = node->val; // 记录最后一行第一个元素
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return result;
}

int main()
{

	TreeNode *root = CreateTree();

	cout << findBottomLeftValue(root) << endl;


	return 0;
}
