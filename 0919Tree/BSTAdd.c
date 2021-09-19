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


int main()
{
	int arr[]={9,5,4,18,23,45,24,16};
	BinaryTree *pTree = CreatTree(arr,sizeof(arr)/sizeof(arr[0]));
	InOrderTraversal(pTree);
	printf("\n");
	return 0;
}
