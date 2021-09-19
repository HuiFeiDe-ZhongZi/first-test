#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int nValue;
	struct tree *pLeft;
	struct tree *pRight;
}BinaryTree;

BinaryTree *CreateBinaryTree()
{
	//根
	BinaryTree *pTree=(BinaryTree*)malloc(sizeof(BinaryTree));
	pTree->nValue=1;
	//根的左
	pTree->pLeft=(BinaryTree*)malloc(sizeof(BinaryTree));
	pTree->pLeft->nValue=2;
	//左的左
	pTree->pLeft->pLeft=(BinaryTree*)malloc(sizeof(BinaryTree));
	pTree->pLeft->pLeft->nValue=4;
	pTree->pLeft->pLeft->pLeft=NULL;
	pTree->pLeft->pLeft->pRight=NULL;
	//左的右
	pTree->pLeft->pRight=(BinaryTree*)malloc(sizeof(BinaryTree));
	pTree->pLeft->pRight->nValue=5;
	pTree->pLeft->pRight->pLeft=NULL;
	pTree->pLeft->pRight->pRight=NULL;
	//根的右
	pTree->pRight=(BinaryTree*)malloc(sizeof(BinaryTree));
	pTree->pRight->nValue=3;
	pTree->pRight->pLeft=NULL;
	pTree->pRight->pRight=NULL;

	return pTree;
}


typedef struct node
{
	BinaryTree* nValue;
	struct node *pNext;
}Node;

typedef struct Stack
{
	int nCount;
	Node *pTop;
}Mystack;

void s_Init(Mystack **pStack)
{
	*pStack=(Mystack*)malloc(sizeof(Mystack));
	(*pStack)->nCount=0;
	(*pStack)->pTop=NULL;
}

void s_Push(Mystack *pStack,BinaryTree* nNum)
{
	if(pStack==NULL)exit(1);
	Node *pTemp=(Node*)malloc(sizeof(Node));
	pTemp->nValue=nNum;
	pTemp->pNext=pStack->pTop;
	pStack->pTop=pTemp;
	pStack->nCount++;
}

BinaryTree* s_Pop(Mystack *pStack)
{
	if(pStack==NULL)exit(1);
	if(pStack->nCount==0)return NULL;
	Node *pDel=pStack->pTop;
	BinaryTree* nNum=pStack->pTop->nValue;

	pStack->pTop= pStack->pTop->pNext;
	free(pDel);
	pDel=NULL;
	pStack->nCount--;
	return nNum;
}

int s_IsEmpty(Mystack *pStack)
{
	if(pStack==NULL)exit(1);
	return pStack->nCount==0 ?1:0;
}
/*======================================================非递归前序遍历============================================*/
void NoDgPre(BinaryTree* pTree)
{
	if(pTree==NULL)return;
	//栈
	Mystack *pStack=NULL;
	s_Init(&pStack);

	while(1)
	{
		while(pTree)
		{
			//打印
			printf("%d ",pTree->nValue);
			//入栈
			s_Push(pStack,pTree);
			//向左走
			pTree=pTree->pLeft;
		}
		//弹出
		pTree=s_Pop(pStack);
		//栈空
		if(pTree==NULL)break;
		//右侧
		pTree=pTree->pRight;
	}
	printf("\n");
}
/*======================================================非递归前序遍历============================================*/



/*======================================================非递归前序遍历============================================*/
void NoDgIn(BinaryTree* pTree)
{
	if(pTree==NULL)return;
	//栈
	Mystack *pStack=NULL;
	s_Init(&pStack);

	while(1)
	{
		while(pTree)
		{
			//入栈
			s_Push(pStack,pTree);
			//向左走
			pTree=pTree->pLeft;
		}
		//弹出
		pTree=s_Pop(pStack);
		//栈空
		if(pTree==NULL)break;
		//打印
		printf("%d ",pTree->nValue);
		//右侧
		pTree=pTree->pRight;
	}
	printf("\n");
}
/*======================================================非递归前序遍历============================================*/


/*======================================================非递归前序遍历============================================*/
void NoDgLast(BinaryTree *pTree)
{
	if(pTree==NULL)return;

	//栈
	Mystack *pStack=NULL;
	s_Init(&pStack);

	BinaryTree *pMark=NULL;
	while(1)
	{
		while(pTree)
		{
			//保存
			s_Push(pStack,pTree);
			//向左走
			pTree=pTree->pLeft;
		}
		//栈空结束
		if(s_IsEmpty(pStack))
			break;
		//栈顶元素的右
		if(pStack->pTop->nValue->pRight==NULL||pStack->pTop->nValue->pRight==pMark)
		{
			// 弹出 标记 打印
			pMark=s_Pop(pStack);
			printf("%d ",pMark->nValue);
		}
		else
		{
			//右
			pTree = pStack->pTop->nValue->pRight;
		}
	}
	printf("\n");
}
/*======================================================非递归前序遍历============================================*/

int main()
{
	BinaryTree *pTree=CreateBinaryTree();
	NoDgPre(pTree);
	NoDgIn(pTree);
	NoDgLast(pTree);
	return 0;
}
