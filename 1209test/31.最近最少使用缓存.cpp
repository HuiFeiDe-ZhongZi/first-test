/*定义双向链表*/
struct Node
{
	int key;
	int value;
	Node *left;
	Node *right;
	Node(int _key,int _value):key(_key),value(_value),left(NULL),right(NULL){}
}*L,*R; //双链表的最左和最右节点，不存值
int n;
unordered_map<int,Node*> hash;

LRUCache(int capacity) {
	n = capacity;
	L = new Node(-1,-1),R = new Node(-1,-1);
	L->right = R;
	R->left = L;
}

int get(int key) {
	if(!hash.count(key)) return -1;  // 不存在关键字 key
	Node *p = hash[key];
	remove(p);
	insert(p); // 将当前节点放在双链表的第一位
	return p->value;
}

void put(int key, int value) {
	if(hash.count(key)) // 如果key存在,则修改对应的value
	{
		Node *p = hash[key];
		p->value = value;
		remove(p);
		insert(p);
	}
	else
	{
		if(hash.size() == n) // 如果缓存已经满了，则删除双链表最右侧的节点
		{
			Node *p = R->left;
			remove(p);
			hash.erase(p->key); // 更新哈希表
			delete p;
		}
		Node *p = new Node(key,value);
		hash[key] = p;
		insert(p);
	}
}

void remove(Node *p)
{
	p->right->left  = p->left;
	p->left->right = p->right;
}

void insert(Node *p)
{
	p->right = L->right;
	p->left = L;
	L->right->left = p;
	L->right = p;
}
