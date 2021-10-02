#include<stdio.h>
#include<stdlib.h>


typedef struct list
{
	int nValue;
	struct list *pNext;
}List;

List *CreateList()
{
	int nNum;
	printf("请输入链表个数：\n");
	scanf("%d",&nNum);

	List *pHead = NULL;
	List *pTail = NULL;
	List *pTemp = NULL;

	int i;
	int tem;
	for(i = 0;i<nNum;i++)
	{
		printf("请输入对应的值:\n");
		scanf("%d",&tem);

		pTemp = (List*)malloc(sizeof(List));
		pTemp->nValue = tem;
		pTemp->pNext = NULL;

		if(pHead == NULL)
		{
			pHead = pTemp;
		}
		else
		{
			pTail->pNext=pTemp;
		}
		pTail=pTemp;
	}
	return pHead;
}

void ReversePrint(List *pHead)
{
	if(pHead == NULL)return;

	ReversePrint(pHead->pNext);

	printf("%d ",pHead->nValue);
}

void Print(List *pHead)
{
	while(pHead)
	{
		printf("%d ",pHead->nValue);
		pHead = pHead->pNext;
	}
	printf("\n");
}

List *Reverse(List *pHead)
{
	if(pHead == NULL || pHead->pNext ==NULL)return pHead;

	List *p1 = NULL;
	List *p2 =pHead;
	List *p3 =pHead->pNext;

	while(p3)
	{
		p2->pNext=p1;

		p1 = p2;
		p2 = p3;
		p3 = p3->pNext;
	}

	p2->pNext = p1;
	return p2;
}

int main()
{
	List *pHead =NULL;
	pHead = CreateList();
	Print(pHead);
	ReversePrint(pHead);
	printf("\n");	
	pHead = Reverse(pHead);
	Print(pHead);


	return 0;
}

