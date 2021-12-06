#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}; // 节点的构造函数
};

void addNode(ListNode **ppHead,ListNode **ppEnd,int id)
{
	ListNode *pTemp = new ListNode(0);
	pTemp->val = id;
	pTemp->next = NULL;

	if(*ppHead == NULL)
	{
		*ppHead = pTemp;
	}
	else
	{
		(*ppEnd)->next = pTemp;
	}
	*ppEnd = pTemp;
}

ListNode *detectCycle(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			ListNode *index1 = head;
			ListNode *index2 = slow;
			while(index1 != index2 )
			{
				index1 = index1->next;
				index2 = index2->next; 
			}
			return index2;
		}
	}
	return NULL;
}

int main()
{
	ListNode *pHead = NULL;
	ListNode *pEnd = NULL;

	addNode(&pHead,&pEnd,3);
	addNode(&pHead,&pEnd,2);
	addNode(&pHead,&pEnd,0);
	addNode(&pHead,&pEnd,-4);

	detectCycle(pHead);

	return 0;
}
