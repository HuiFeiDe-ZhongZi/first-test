#include<iostream>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

//声明
void Print(ListNode *pHead);
ListNode *reverseList(ListNode *pHead);

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

void addTwoNumbers(ListNode* l1, ListNode* l2) {
	l1 = reverseList(l1);
	l2 = reverseList(l2);

	int carry = 0;  //进位标志
	ListNode *dummy = new ListNode(0);
	ListNode *p = dummy;
	while(l1 || l2 || carry)
	{
		int a = l1 == NULL? 0 : l1->val;
		int b = l2 == NULL? 0 : l2->val;
		if(l1) l1 = l1->next;
		if(l2) l2 = l2->next;
		int sum = a + b + carry;
		ListNode *cur = new ListNode(sum%10);
		carry = sum /10;
		p->next = cur;
		//p = p->next;
		p = cur;
	}
	Print(reverseList(dummy->next));
}

ListNode *reverseList(ListNode *pHead)
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
	ListNode *pHead1 = NULL;
	ListNode *pEnd1 = NULL;
	ListNode *pHead2 = NULL;
	ListNode *pEnd2 = NULL;


	addNode(&pHead1,&pEnd1,7);
	addNode(&pHead1,&pEnd1,2);
	addNode(&pHead1,&pEnd1,4);
	addNode(&pHead1,&pEnd1,3);

	addNode(&pHead2,&pEnd2,5);
	addNode(&pHead2,&pEnd2,6);
	addNode(&pHead2,&pEnd2,4);

	addTwoNumbers(pHead1,pHead2);


	return 0;
}
