Node* insert(Node* head, int insertVal) {
	Node *node = new Node(insertVal);
	if(head == NULL)  // 处理链表为空的情况
	{
		head = node;
		node->next = head;
	}

	else if(head->next == NULL)  // 处理链表只有一个节点的情况
	{
		head->next = node;
		node->next = head;
	}

	else       // 链表中超过一个节点的情况
	{
		insertCore(head,node);
	}
	return head;
}

void insertCore(Node* head,Node *node)
{
	Node* cur = head;
	Node* next = head->next;
	Node* maxVal = head;
	// 试图找到相邻的两个节点cur与next 使待插入值大于cur且小于next
	while(!(cur->val <= node->val && next->val >= node->val) && (next != head))
	{
		cur = next;
		next = next->next;
		if(cur->val >= maxVal->val) maxVal = cur;
	}

	if(cur->val <= node->val && next->val >= node->val)
	{
		cur->next = node;
		node->next = next;
	}
	else            // 如果没有找到符合条件的节点，说明新节点比所有的节点值都大或者都小
	{               // 那么就把新节点插入到值最大节点的后面 也就是图中1-4的中间位置
		node->next = maxVal->next;
		maxVal->next = node;
	}
}
