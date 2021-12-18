class Solution {
	public:
		bool findTarget(TreeNode* root, int k) {
			if(root == NULL) return false;

			unordered_set<int> hash;
			queue<TreeNode*> que;
			que.push(root);

			while(!que.empty())
			{
				TreeNode *tmp = que.front();
				que.pop();

				if(hash.find(k - tmp->val) != hash.end()) // 利用hash 寻找保存的数中是否存在该值
				{
					return true;
				}              
				else 
				{
					hash.insert(tmp->val); 
				}

				if(tmp->left) que.push(tmp->left);
				if(tmp->right) que.push(tmp->right);
			}
			return false;
		}
};
