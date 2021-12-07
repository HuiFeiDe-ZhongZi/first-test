#include<iostream>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

void Print(ListNode *pHead);
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

ListNode *rerverList(ListNode *pHead)
{
	ListNode *cur = pHead;
	ListNode *pre = NULL;
	ListNode *temp = NULL;

	while(cur)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}
void reorderList(ListNode* head) {
	ListNode *dummy = new ListNode(0);
	ListNode *slow = dummy;
	ListNode *fast = dummy;
	dummy->next = head;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *half = slow->next;
	slow->next = NULL;
	half = rerverList(half);
	ListNode *cur = dummy->next;
	
	while(cur && half)
	{
		ListNode *p1 = cur->next;
		ListNode *p2 = half->next;

		cur->next = half;
		cur = p1;

		half->next = cur;
		half = p2; 
	}
	Print(dummy->next);
}

void Print(ListNode *pHead)
{
	while(pHead)
	{
		cout << pHead->val << " ";
		pHead = pHead->next;
	}
	cout<<endl;
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

	reorderList(pHead);


	return 0;
}
