#include<stdio.h>
#include<stdlib.h>

enum COLOR{RED,BLACK};

typedef struct tree
{
	int nValue;
	int nColor;
	struct tree *pLeft;
	struct tree *pRight;
	struct tree *pFather;
}RBT;


RBT *pRBT=NULL;

void  RightRotate(RBT **pTree)
{
	if(*pTree==NULL||(*pTree)->pLeft==NULL)return;

	RBT *pNode=*pTree;//A
	RBT *pMark=pNode->pLeft;//B
	
	//三个孩子关系
	pNode->pLeft = pMark->pRight;//E是A的左
	pMark->pRight=pNode;//A是B的右

	//根  B是X的孩子
	if(pNode->pFather==NULL)
	{
		pRBT=pMark;
	}
	else
	{
		if(pNode ==pNode->pFather->pLeft)
		{
			pNode->pFather->pLeft=pMark;
		}
		else
		{
			pNode->pFather->pRight=pMark;
		}
	}
	
	//三个父亲关系
	if(pNode->pLeft != NULL)
	{
		pNode->pLeft->pFather=pNode;//E的父亲是A
	}
	pMark->pFather=pNode->pFather;//B的父亲是X
	pNode->pFather=pMark;//A的父亲是B

}
void  LeftRotate(RBT **pTree)
{
	if(*pTree==NULL||(*pTree)->pRight==NULL)return;

	RBT *pNode=*pTree;//A
	RBT *pMark=pNode->pRight;//B
	
	pNode->pRight = pMark->pLeft;
	pMark->pLeft=pNode;

	if(pNode->pFather==NULL)
	{
		pRBT=pMark;
	}
	else
	{
		if(pNode ==pNode->pFather->pLeft)
		{
			pNode->pFather->pLeft=pMark;
		}
		else
		{
			pNode->pFather->pRight=pMark;
		}
	}
	
	if(pNode->pRight != NULL)
	{ 
		pNode->pRight->pFather=pNode;
	}
	pMark->pFather=pNode->pFather;
	pNode->pFather=pMark;

}
//查找
RBT *Search(RBT *pTree,int nNum)
{
	while(pTree)
	{
		if(pTree->nValue>nNum)
		{
			if(pTree->pLeft==NULL)
			{
				return pTree;
			}
			pTree=pTree->pLeft;
		}
		else if(pTree->nValue<nNum)
		{
			if(pTree->pRight==NULL)
			{
				return pTree;
			}
			pTree=pTree->pRight;
		}
		else
		{
			//数值相同 错误
			printf("Data is mistake\n");
			exit(1);
		}
	}
	return NULL;
}

//找叔叔节点
RBT *GetUncle(RBT *pNode)
{
	if(pNode==pNode->pFather->pLeft)
		return pNode->pFather->pRight;
	else
		return pNode->pFather->pLeft;
}


void AddNode(RBT *pTree,int nNum)
{

	//查找
	RBT *pNode=NULL;//父亲
	pNode=Search(pRBT,nNum);

	//申请空间
	RBT *pTemp=(RBT*)malloc(sizeof(RBT));
	pTemp->nValue=nNum;
	pTemp->nColor=RED;
	pTemp->pFather=pNode;
	pTemp->pLeft=NULL;
	pTemp->pRight=NULL;

	//1.根
	if(pNode==NULL)
	{
		pRBT=pTemp;
		pRBT->nColor=BLACK;
		return;
	}
	//2.非根
	//节点放入树中
	if(pNode->nValue>nNum)
	{
		pNode->pLeft=pTemp;
	}
	else
	{
		pNode->pRight=pTemp;
	}

	//2.1父亲是黑的
	if(pNode->nColor==BLACK)
	{
		return;
	}

	//2.2父亲是红的
	RBT *pGrandFather=NULL;
	RBT *pUncle=NULL;

	while(pNode->nColor==RED)
	{
		pGrandFather=pNode->pFather;
		pUncle=GetUncle(pNode);
	
		//2.2.1叔叔是红的
		if(pUncle->nColor==RED && pUncle!=NULL)
		{
			pNode->nColor=BLACK;
			pUncle->nColor=BLACK;
			pGrandFather->nColor=RED;

			pTemp = pGrandFather;
			pNode=pTemp->pFather;
			//原爷爷是不是根
			if(pNode==NULL)
			{
				pRBT->nColor=BLACK;
				break;
			}
			continue;
		}
		//2.2.2叔叔是黑的
		if(pUncle==NULL || pUncle->nColor==BLACK)
		{
			//2.2.2.1父是爷爷的左
			if(pNode==pGrandFather->pLeft)
			{
				//2.2.2.1.1当前节点是父亲的右
				if(pTemp==pNode->pRight)
				{
					pTemp=pNode;
					LeftRotate(&pTemp);
					pNode=pTemp->pFather;
					continue;
				}
				//2.2.2.1.2当前节点是父的左
				if(pTemp==pNode->pLeft)
				{
					pGrandFather->nColor=RED;
					pNode->nColor=BLACK;
					RightRotate(&pGrandFather);
					break;
				}
			}

			//2.2.2.2父是爷爷的右
			if(pNode==pGrandFather->pRight)
			{
				//2.2.2.2.1当前节点是父亲的左
				if(pTemp==pNode->pLeft)
				{
					pTemp=pNode;
					RightRotate(&pTemp);
					pNode=pTemp->pFather;
					continue;
				}
				//2.2.2.2.2当前节点是父的右
				if(pTemp == pNode->pRight)
				{
					pGrandFather->nColor=RED;
					pNode->nColor=BLACK;
					LeftRotate(&pGrandFather);
					break;
				}
			}
		}
	}
}

//创建红黑树
void CreatTree(int arr[],int Len)
{
	if(arr==NULL||Len<=0)return;

	int i;
	for(i=0;i<Len;i++)
	{
		AddNode(pRBT,arr[i]);
	}
}
void InOrderTraversal(RBT *pTree)
{
	if(pTree==NULL)return;

	//根
	printf("value == %d\tcolor == %d\n ",pTree->nValue,pTree->nColor);

	//左
	InOrderTraversal(pTree->pLeft);

	//右
	InOrderTraversal(pTree->pRight);
}


int main()
{
	int arr[]={11,2,14,1,7,15,5,8,4};
	CreatTree(arr,sizeof(arr)/sizeof(arr[0]));
	InOrderTraversal(pRBT);
	
	return 0;
}
