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


typedef struct data
{
	BinaryTree* nValue;
	struct data *pNext;
}Data;

typedef struct queue
{
	int nCount;
	Data *pHead;
	Data *pTail;
}Queue;

void q_Init(Queue **pQueue)
{
	*pQueue=(Queue*)malloc(sizeof(Queue));
	(*pQueue)->nCount=0;
	(*pQueue)->pHead=NULL;
	(*pQueue)->pTail=NULL;
}

void q_Push(Queue *pQueue,BinaryTree* nNum)
{
	if(pQueue==NULL)exit(1);

	Data* pTemp=(Data*)malloc(sizeof(Data));
	pTemp->nValue=nNum;
	pTemp->pNext=NULL;

	if(pQueue->pHead==NULL)
	{
		pQueue->pHead=pTemp;
	}
	else
	{
		pQueue->pTail->pNext=pTemp;
	}
	pQueue->pTail=pTemp;
	pQueue->nCount++;
}

BinaryTree* q_Pop(Queue *pQueue)
{
	if(pQueue==NULL)exit(1);
	if(pQueue->nCount==0)return  NULL;

	Data *pDel=pQueue->pHead;
	BinaryTree *num=pQueue->pHead->nValue;
	pQueue->pHead=pQueue->pHead->pNext;
	free(pDel);
	pDel=NULL;
	pQueue->nCount--;
	return num;
}

int q_IsEmpty(Queue *pQueue)
{
	if(pQueue==NULL)exit(1);
	return pQueue->nCount==0?1:0;
}

/*-------------------------------------------------------特殊标记换行打印-----------------------------*/
void LevelTraversal(BinaryTree *pTree)
{
	if(pTree==NULL)return;

	//队列
	Queue *pQueue=NULL;
	q_Init(&pQueue);
	//根入队
	q_Push(pQueue,pTree);	
	q_Push(pQueue,NULL);
	while(!q_IsEmpty(pQueue))
	{
		//弹出
		pTree = q_Pop(pQueue);
		if(pTree)
		{

			//打印
			printf("%d ",pTree->nValue);
			//非空左右入队
			if(pTree->pLeft!=NULL)
			{
				q_Push(pQueue,pTree->pLeft);
			}
			if(pTree->pRight!=NULL)
			{
				q_Push(pQueue,pTree->pRight);
			}
		}
		else
		{
			if(!q_IsEmpty(pQueue))
				q_Push(pQueue,NULL);
			printf("\n");
		}
	}
}
/*-------------------------------------------------------特殊标记换行打印-----------------------------*/


/*-------------------------------------------------------双指针换行打印-----------------------------*/
void LevelTraversal(BinaryTree *pTree)
{
	if(pTree==NULL)return;

	//队列
	Queue *pQueue=NULL;
	q_Init(&pQueue);
	BinaryTree *pCur=pTree;
	BinaryTree *pLast=NULL;
	//根入队
	q_Push(pQueue,pTree);

	while(!q_IsEmpty(pQueue))
	{
		//弹出
		pTree = q_Pop(pQueue);

		//打印
		printf("%d ",pTree->nValue);
		//非空左右入队
		if(pTree->pLeft!=NULL)
		{
			q_Push(pQueue,pTree->pLeft);
			pLast=pTree->pLeft;
		}
		if(pTree->pRight!=NULL)
		{
			q_Push(pQueue,pTree->pRight);
			pLast=pTree->pRight;
		}
		if(pTree==pCur)
		{
			printf("\n");
			pCur=pLast;
			pLast=NULL;
		}
	}
}
/*-------------------------------------------------------双指针换行打印-----------------------------*/



/*-------------------------------------------------------双队列换行打印-----------------------------*/
void LevelTraversal(BinaryTree *pTree)
{
	if(pTree==NULL)return;

	//队列
	Queue *pQueue1=NULL;
	q_Init(&pQueue1);
	Queue *pQueue2=NULL;
	q_Init(&pQueue2);
	//根入队
	q_Push(pQueue1,pTree);
	while(pTree)
	{
		while(!q_IsEmpty(pQueue1))
		{
			//弹出
			pTree = q_Pop(pQueue1);
			//打印
			printf("%d ",pTree->nValue);
			//非空左右入队
			if(pTree->pLeft!=NULL)
			{
				q_Push(pQueue2,pTree->pLeft);
			}
			if(pTree->pRight!=NULL)
			{
				q_Push(pQueue2,pTree->pRight);
			}
			
			if(q_IsEmpty(pQueue1))
				printf("\n");
		}
		while(!q_IsEmpty(pQueue2))
		{
			//弹出
			pTree = q_Pop(pQueue2);

			//打印
			printf("%d ",pTree->nValue);
			//非空左右入队
			if(pTree->pLeft!=NULL)
			{
				q_Push(pQueue1,pTree->pLeft);
			}
			if(pTree->pRight!=NULL)
			{
				q_Push(pQueue1,pTree->pRight);
			}
			if(q_IsEmpty(pQueue2))
				printf("\n");
		}
		if(q_IsEmpty(pQueue1)&&q_IsEmpty(pQueue2))
			break;
	}
}
/*-------------------------------------------------------双队列换行打印-----------------------------*/

int main()
{
	BinaryTree *pTree=CreateBinaryTree();
	LevelTraversal(pTree);

	return 0;
}
