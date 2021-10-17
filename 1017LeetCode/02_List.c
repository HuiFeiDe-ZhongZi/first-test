#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int nValue;
	struct Node *pNext;
}List;

//链表添加节点
void AddNode(List **ppHead, List **ppEnd, int id)
{
	List *pTemp = (List*)malloc(sizeof(List));
	pTemp->nValue = id;
	pTemp->pNext = NULL;

	if (*ppHead == NULL)
	{
		*ppHead = pTemp;
	}
	else
	{
		(*ppEnd)->pNext = pTemp;
	}
	*ppEnd = pTemp;
}

//链表插入节点
void InsertNode(List **ppHead, List **ppEnd, List *pNode, int id)
{
	List *pMark = *ppHead;
	//1.头插入
	if ((*ppHead)->nValue == id)
	{
		pNode->pNext = *ppHead;
		*ppHead = pNode;
		return;
	}
	//2.中间插入
	while (pMark->pNext != NULL)
	{
		if (pMark->pNext->nValue == id)
		{
			pNode->pNext = pMark->pNext;
			pMark->pNext = pNode;
			return;
		}
		pMark = pMark->pNext;
	}
	//3.尾插入
	(*ppEnd)->pNext = pNode;
	*ppEnd = pNode;


}

//链表删除节点
void DelNode(List **ppHead, List **ppEnd, int id)
{
	List *pDel = NULL;
	List *pMark = *ppHead;

	//1.头删除
	if ((*ppHead)->nValue == id)
	{
		pDel = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pDel);
		pDel = NULL;
		return;
	}
	//2.中间删除
	while (pMark->pNext != NULL)
	{
		if (pMark->pNext->nValue == id)
		{
			pDel = pMark->pNext;
			pMark->pNext = pMark->pNext->pNext;
			free(pDel);
			pDel = NULL;
			//是否是删除尾
			if (pMark->pNext == NULL)
			{
				*ppEnd = pMark;
			}
			return;
		}
		pMark = pMark->pNext;
	}
}

//链表打印
void Print(List *pHead)
{
	while (pHead)
	{
		printf("%d ", pHead->nValue);
		pHead = pHead->pNext;
	}
	printf("\n");
}
int main()
{
	List *pHead = NULL;
	List *pEnd = NULL;
	List a = { 7,NULL };

	AddNode(&pHead, &pEnd, 1);
	AddNode(&pHead, &pEnd, 2);
	AddNode(&pHead, &pEnd, 3);
	AddNode(&pHead, &pEnd, 4);
	AddNode(&pHead, &pEnd, 5);

	Print(pHead);

	InsertNode(&pHead, &pEnd, &a, 3);

	Print(pHead);

	DelNode(&pHead, &pEnd, 5);

	Print(pHead);

	return 0;
}