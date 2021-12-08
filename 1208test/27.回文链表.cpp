#include<iostream>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
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
bool isPalindrome(ListNode* head) {
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
	half = reverseList(half);
	ListNode *cur = dummy->next;

	while(half != NULL)
	{
		if(half->val != cur->val)
		{
			return false;
		}
		half = half->next;
		cur = cur->next;
	}
	return true;
}

int main()
{
	ListNode *pHead = NULL;
	ListNode *pEnd = NULL;

	addNode(&pHead,&pEnd,1);
	addNode(&pHead,&pEnd,2);
	addNode(&pHead,&pEnd,3);
	addNode(&pHead,&pEnd,3);
	addNode(&pHead,&pEnd,2);
	addNode(&pHead,&pEnd,1);

	cout<<isPalindrome(pHead)<<endl;


	return 0;
}
