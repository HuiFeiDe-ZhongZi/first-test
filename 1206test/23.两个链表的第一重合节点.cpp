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
void getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA == NULL || headB == NULL) return;
	ListNode *curA = headA;
	ListNode *curB = headB;

	int lenA = 0;
	int lenB = 0;
	while(curA->next)
	{
		curA = curA->next;
		lenA++;
	}
	while(curB->next)
	{
		curB = curB->next;
		lenB++;
	}

	int len = 0;
	if(lenA > lenB)
	{
		len = lenA - lenB;
		while(len)
		{
			headA = headA->next;
			len--;
		}
	}
	if(lenB > lenA)
	{
		len = lenB - lenA;
		while(len)
		{
			headB = headB->next;
			len--;
		}
	}

	while(headA->val !=  headB->val )
	{
		headA = headA->next;
		headB = headB->next;
	}
	cout << headA->val<<endl;

}


int main()
{
	ListNode *pHead1 = NULL;
	ListNode *pEnd1 = NULL;
	ListNode *pHead2 = NULL;
	ListNode *pEnd2 = NULL;

	addNode(&pHead1,&pEnd1,4);
	addNode(&pHead1,&pEnd1,1);
	addNode(&pHead1,&pEnd1,8);
	addNode(&pHead1,&pEnd1,4);
	addNode(&pHead1,&pEnd1,5);

	addNode(&pHead2,&pEnd2,5);
	addNode(&pHead2,&pEnd2,0);
	addNode(&pHead2,&pEnd2,1);
	addNode(&pHead2,&pEnd2,8);
	addNode(&pHead2,&pEnd2,4);
	addNode(&pHead2,&pEnd2,5);

	getIntersectionNode(pHead1,pHead2);
	
	return 0;
}
