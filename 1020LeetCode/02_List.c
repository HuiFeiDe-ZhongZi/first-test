#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int nValue;
	struct Node *pNext;
}List;

//������ӽڵ�
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

//�������ڵ�
void InsertNode(List **ppHead, List **ppEnd, List *pNode, int id)
{
	List *pMark = *ppHead;
	//1.ͷ����
	if ((*ppHead)->nValue == id)
	{
		pNode->pNext = *ppHead;
		*ppHead = pNode;
		return;
	}
	//2.�м����
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
	//3.β����
	(*ppEnd)->pNext = pNode;
	*ppEnd = pNode;


}

//����ɾ���ڵ�
void DelNode(List **ppHead, List **ppEnd, int id)
{
	List *pDel = NULL;
	List *pMark = *ppHead;

	//1.ͷɾ��
	if ((*ppHead)->nValue == id)
	{
		pDel = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pDel);
		pDel = NULL;
		return;
	}
	//2.�м�ɾ��
	while (pMark->pNext != NULL)
	{
		if (pMark->pNext->nValue == id)
		{
			pDel = pMark->pNext;
			pMark->pNext = pMark->pNext->pNext;
			free(pDel);
			pDel = NULL;
			//�Ƿ���ɾ��β
			if (pMark->pNext == NULL)
			{
				*ppEnd = pMark;
			}
			return;
		}
		pMark = pMark->pNext;
	}
}

//�����ӡ
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