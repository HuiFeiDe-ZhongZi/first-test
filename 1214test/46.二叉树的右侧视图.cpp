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
	pTree->left = NULL;
	pTree->right = (TreeNode*)malloc(sizeof(TreeNode));
	pTree->right->val = 3;
	pTree->right->left = NULL;
	pTree->right->right = NULL;

	return pTree;
}

vector<int> rightSideView(TreeNode* root) {  
	vector<int> res;
	if(root == NULL) return res; 
	queue<TreeNode*> que;
	que.push(root);

	while(!que.empty())
	{
		int size = que.size();
		while(size--)
		{
			TreeNode *tmp = que.front();
			que.pop();
			if(tmp->left) que.push(tmp->left);
			if(tmp->right) que.push(tmp->right);
			if(size == 0) res.push_back(tmp->val);
		}
	}
	return res;
}

int main()
{

	TreeNode *root = CreateTree();
	vector<int> res= rightSideView(root);

	for(int i : res)
	{
		cout << i << " ";
	}
	cout << endl;



	return 0;
}
