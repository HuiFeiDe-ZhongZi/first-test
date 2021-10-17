#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode
{ 
	int val;
	struct ListNode *pNext;
}List;

void AddNode(List **ppHead,List **ppEnd,int id)
{
	List *pTemp = (List*)malloc(sizeof(List));
	pTemp->val = id;
	pTemp->pNext = NULL;

	if(*ppHead == NULL)
	{
		*ppHead = pTemp;
	}
	else
	{
		(*ppEnd)->pNext = pTemp;
	}
 *ppEnd = pTemp;
}

void DelteNode(List **ppHead,List **ppEnd,int id)
{
	//1.头删除
	while((*ppHead) != NULL && (*ppHead)->val == id)
	{
		List *pDel = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pDel);
		pDel = NULL;
	}
	
	List *pMark = *ppHead;
	//2.中间删除
	while(pMark != NULL && pMark->pNext != NULL)
	{
		if(pMark->pNext->val == id)
		{
			List *pDel = pMark->pNext;
			pMark->pNext= pMark->pNext->pNext;
			free(pDel);
			pDel = NULL;
			if(pMark->pNext == NULL)
			{
				*ppEnd = pMark;
			}
		}
		else
		{
			pMark = pMark->pNext;
		}
	}
}



void Print(List *pHead)
{
	while(pHead)
	{
		printf("%d ",pHead->val);
		pHead = pHead->pNext;
	}
	printf("\n");
}

int main()
{
	List *pHead = NULL;
	List *pEnd = NULL;

	AddNode(&pHead,&pEnd,1);
	AddNode(&pHead,&pEnd,2);
	AddNode(&pHead,&pEnd,5);
	AddNode(&pHead,&pEnd,1);
	AddNode(&pHead,&pEnd,5);

	Print(pHead);
	DelteNode(&pHead,&pEnd,1);
	Print(pHead);

	return 0;
}
