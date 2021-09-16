#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int nValue;
	struct node *pNext;
}Node;

typedef struct Stack
{
	int count;
	Node *pTop;
}Mystack;

void s_Init(Mystack **pStack)
{
	*pStack=(Mystack*)malloc(sizeof(Mystack));
	(*pStack)->count=0;
	(*pStack)->pTop=NULL;
}

void s_Push(Mystack *pStack,int nNum)
{
	if(pStack==NULL)exit(1);
	Node *pTemp=(Node*)malloc(sizeof(Node));
	pTemp->nValue=nNum;
	pTemp->pNext=pStack->pTop;
	pStack->pTop=pTemp;
	pStack->count++;
}

int s_Pop(Mystack *pStack)
{
	if(pStack==NULL)exit(1);
	if(pStack->count==0)return -1;
	Node *pDel=pStack->pTop;
	int nNum=pDel->nValue;

	pStack->pTop= pStack->pTop->pNext;
	free(pDel);
	pDel=NULL;
	pStack->count--;
	return nNum;
}

void s_clear(Mystack *pStack)
{
	if(pStack==NULL)exit(1);
	while(pStack->count!=0)
	{
		s_Pop(pStack);
	}
}

void s_Destory(Mystack **pStack)
{
	s_clear(*pStack);

	free(pStack);
	*pStack=NULL;
}

Node *s_GetTop(Mystack *pStack)
{
	if(pStack==NULL)exit(1);
	return pStack->pTop;
}

int s_IsEmpty(Mystack *pStack)
{
	if(pStack==NULL)exit(1);
	return pStack->count==0 ?1:0;
}
int main()
{
	Mystack *pStack=NULL;
	s_Init(&pStack);
	s_Push(pStack,1);
	s_Push(pStack,2);
	s_Push(pStack,3);
	s_Push(pStack,4);

	printf("%d\n",s_Pop(pStack));
	printf("%d\n",s_Pop(pStack));
	printf("%d\n",s_Pop(pStack));
	printf("%d\n",s_Pop(pStack));


	return 0;
}

