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

void reverseList(ListNode* head) {
	ListNode *cur = head;
	ListNode *pre = NULL;
	ListNode *Temp = NULL;

	while(cur != NULL)
	{
		Temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = Temp; 

	}

	Print(pre);
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

	reverseList(pHead);


	return 0;
}
