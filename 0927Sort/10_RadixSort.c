#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct radix
{
	int nValue;
	struct radix *pNext;
}Radix;

void Sort(int arr[],int len,int nBegin)
{
	//计算基数
	int nBase = 1;
	while(nBegin>1)
	{
		nBase*=10;
		nBegin--;
	}

	//申请空间
	Radix **pRadix = (Radix**)malloc(sizeof(Radix*)*10);
	memset(pRadix,0,sizeof(Radix*)*10);

	//数字入组
	int i;
	int nIndex;
	Radix *pTemp = NULL;
	Radix *pNode = NULL;
	for(i = 0;i<len;i++)
	{
		nIndex = arr[i]/nBase%10;

		pTemp = (Radix*)malloc(sizeof(Radix));
		pTemp->nValue=arr[i];
		pTemp->pNext =NULL;

		//尾添加
		if(pRadix[nIndex] == NULL)
		{
			pRadix[nIndex] = pTemp;
		}
		else
		{
			pNode = pRadix[nIndex];
			while(pNode->pNext != NULL)
			{
				pNode = pNode->pNext;
			}
			pNode->pNext = pTemp;
		}
	}

	//数字放回数组
	int j=0;
	for(i = 0;i<10;i++)
	{
		pTemp = pRadix[i];
		while(pTemp)
		{
			arr[j]=pTemp->nValue;
			j++;
			pTemp=pTemp->pNext;
		}
	}

	//释放
	for(i = 0;i<10;i++)
	{
		pTemp=pRadix[i];
		while(pTemp)
		{
			pNode=pTemp;
			pTemp=pTemp->pNext;
			free(pNode);
			pNode=NULL;
		}
	}

	free(pRadix);
	pRadix=NULL;
}


void RadixSort(int arr[],int len)
{
	if(arr == NULL || len <=0 )return;

	//找最大值
	int nMax;
	int i;
	nMax = arr[0];
	for(i =1;i<len;i++)
	{
		if(arr[i]>nMax)
		{
			nMax = arr[i];
		}
	}
	//计算位数
	int nLoopTimes = 0;
	while(nMax)
	{
		nMax/=10;
		nLoopTimes++;
	}
	//按位处理
	for(i = 1;i<=nLoopTimes;i++)
	{
		Sort(arr,len,i);
	}
}

void Print(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	int i;
	for(i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {3,9,2,6,8,0,1,5};

	RadixSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
} 
