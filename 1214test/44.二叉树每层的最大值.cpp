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
	pTree->val = 1;

	// 根的左
	pTree->left = (TreeNode*)malloc(sizeof(TreeNode));
	pTree->left->val = 2;
	pTree->left->left = NULL;
	pTree->left->right = NULL;
	pTree->right = (TreeNode*)malloc(sizeof(TreeNode));
	pTree->right->val = 3;
	pTree->right->left = NULL;
	pTree->right->right = NULL;

	return pTree;
}

vector<int> largestValues(TreeNode* root) {
	vector<int> res;
	if (root == nullptr) return res;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		int size = q.size();
		int maxVal = INT_MIN;               //要求最大值，所以初始化为最小
		while (size -- )
		{
			TreeNode* t = q.front();
			q.pop();
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);

			maxVal = max(maxVal, t->val);   //更新最大值
		}

		res.push_back(maxVal);              //当前层已遍历完毕，存入当前层最大值
	}

	return res;
}

int main()
{
	
	TreeNode *root = CreateTree();
	vector<int> res= largestValues(root);

	for(int i : res)
	{
		cout << i << " ";
	}
	cout << endl;



	return 0;
}
