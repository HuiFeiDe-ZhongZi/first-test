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


void resmoveNthFromEnd(ListNode *head,int n)
{
	ListNode *dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode *slow = dummyHead;
	ListNode *fast = dummyHead;

	while(n-- && fast != NULL)
	{
		fast = fast->next;
	}

	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;
	
	ListNode *pHead = dummyHead->next;
	while(pHead)
	{
		cout<<pHead->val<<endl;
		pHead = pHead->next;
	}
}

int main()
{
	ListNode *pHead = NULL;
	ListNode *pEnd = NULL;
	
	addNode(&pHead,&pEnd,1);
	addNode(&pHead,&pEnd,2);
	addNode(&pHead,&pEnd,3);
	addNode(&pHead,&pEnd,4);
	addNode(&pHead,&pEnd,5);

	int n = 2;
	resmoveNthFromEnd(pHead,n);

	return 0;
}
