#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int nValue;
	struct tree *pLeft;
	struct tree *pRight;
}BinaryTree;

void AddNode(BinaryTree **pTree,int nNum)
{
	//节点
	BinaryTree *pTemp=(BinaryTree*)malloc(sizeof(BinaryTree));
	pTemp->nValue=nNum;
	pTemp->pLeft=NULL;
	pTemp->pRight=NULL;

	//空
	if(*pTree==NULL)
	{
		*pTree=pTemp;
		return;
	}

	//非空
	BinaryTree *pNode=*pTree;

	while(pNode)
	{
		//左侧
		if(pNode->nValue>nNum)
		{
			//为空放入
			if(pNode->pLeft==NULL)
			{
				pNode->pLeft=pTemp;
				return;
			}
			//不为空继续向左走
			pNode=pNode->pLeft;
		}
		//右侧
		else if(pNode->nValue<nNum)
		{
			if(pNode->pRight==NULL)
			{
				pNode->pRight=pTemp;
				return;
			}
			pNode=pNode->pRight;
		}
		//相等出错
		else
		{
			printf("此值错误：%d\n",nNum);
			free(pTemp);
			pTemp=NULL;
			return;
		}
	}
}

BinaryTree *CreatTree(int arr[],int Len)
{
	if(arr==NULL||Len<=0)return NULL;

	BinaryTree *pTree=NULL;

	int i;
	for(i=0;i<Len;i++)
	{
		AddNode(&pTree,arr[i]);
	}

	return pTree;
}
void InOrderTraversal(BinaryTree *pTree)
{
	if(pTree==NULL)return;

	//左
	InOrderTraversal(pTree->pLeft);

	//根
	printf("%d ",pTree->nValue);

	//右
	InOrderTraversal(pTree->pRight);
}

void Search(BinaryTree *pTree,BinaryTree **pDel,BinaryTree **pFather,int nNum)
{
	while(pTree)
	{
		if(pTree->nValue==nNum)
		{
			*pDel=pTree;
			return;
		}
		else if(pTree->nValue > nNum)
		{
			//左侧
			*pFather=pTree;
			pTree=pTree->pLeft;
		}
		else
		{
			*pFather=pTree;
			pTree=pTree->pRight;
		}
	}
	*pFather=NULL;
}

void DelNode(BinaryTree **pTree,int nNum)
{
	if(*pTree==NULL)return;

	//查找
	BinaryTree *pDel=NULL;
	BinaryTree *pFather=NULL;

	Search(*pTree,&pDel,&pFather,nNum);
	
	//情况分析
	if(pDel==NULL)return;

	//两个孩子情况
	BinaryTree *pMark =NULL;
	if(pDel->pLeft!=NULL && pDel->pRight!=NULL)
	{
		pMark=pDel;
		//左的最右
		//先向左走一步
		pFather=pDel;
		pDel=pDel->pLeft;
		//最右
		while(pDel->pRight!=NULL)
		{
			pFather=pDel;
			pDel=pDel->pRight;
		}
		//值覆盖
		pMark->nValue=pDel->nValue;
	}
	//1个或0个
	//根
	if(pFather==NULL)
	{
		*pTree=pDel->pLeft?pDel->pLeft:pDel->pRight;
		free(pDel);
		pDel=NULL;
		return;
	}
	//非根
	if(pDel==pFather->pLeft)
	{
		pFather->pLeft=pDel->pLeft ? pDel->pLeft : pDel->pRight;
	}
	else
	{
		pFather->pRight=pDel->pLeft ? pDel->pLeft : pDel->pRight;
	}
	free(pDel);
	pDel=NULL;
}


int main()
{
	//添加
	int arr[]={9,5,4,18,23,45,24,16};
	BinaryTree *pTree = CreatTree(arr,sizeof(arr)/sizeof(arr[0]));
	InOrderTraversal(pTree);
	printf("\n");
	//删除
	DelNode(&pTree,45);
	InOrderTraversal(pTree);
	printf("\n");

	return 0;
}
