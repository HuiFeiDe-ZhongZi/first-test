#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bucket
{
	int nValue;
	struct bucket *pNext;
}Bucket;

void Sort(Bucket *pHead)
{
	if(pHead == NULL || pHead->pNext == NULL)return;
	
	Bucket *pTemp = pHead;
	Bucket *pNode = pHead;
	while(pNode->pNext != NULL)
	{
		pTemp=pHead;
		while(pTemp->pNext != NULL)
		{
			if(pTemp->nValue > pTemp->pNext->nValue)
			{
				pTemp->nValue = pTemp->nValue ^ pTemp->pNext->nValue;
				pTemp->pNext->nValue = pTemp->nValue ^ pTemp->pNext->nValue;
				pTemp->nValue = pTemp->nValue ^ pTemp->pNext->nValue;
			}
			pTemp = pTemp->pNext;
		}
		pNode = pNode->pNext;
	}
}

void BucketSort(int arr[],int len)
{
	if(arr == NULL || len <=0 )return;
	//最大值 最小值
	int i;
	int nMin = arr[0];
	int nMax = arr[0];
	for(i=1;i<len;i++)
	{
		if(arr[i]>nMax)
		{
			nMax = arr[i];
		}

		if(arr[i]<nMin)
		{
			nMin=arr[i];
		}
	}

	//拆高位
	int nNum = nMin;
	int nCount =1;

	while(nNum)
	{
		nNum/=10;
		nCount*=10;
	}

	nCount/=10;

	int nMinIndex = nMin/nCount;
	int nMaxIndex = nMax/nCount;

	//桶申请
	Bucket **pBucket =NULL;
	pBucket = (Bucket**)malloc(sizeof(Bucket*)*(nMaxIndex-nMinIndex+1));
	bzero(pBucket,sizeof(Bucket*)*(nMaxIndex-nMinIndex+1));

	//元素入桶
	Bucket *pTemp = NULL;
	for(i = 0;i<len;i++)
	{
		nNum = arr[i]/nCount - nMinIndex;
		
		pTemp = (Bucket*)malloc(sizeof(Bucket));
		pTemp->nValue = arr[i];

		pTemp->pNext=pBucket[nNum];
		pBucket[nNum]=pTemp;
	}

	//各桶之内排序
	for(i=0;i<nMaxIndex-nMinIndex+1;i++)
	{
		Sort(pBucket[i]);
	}
	
	//元素放回原数组
	nNum=0;
	for(i=0;i<nMaxIndex-nMinIndex+1;i++)
	{
		pTemp = pBucket[i];
		while(pTemp)
		{
			arr[nNum]=pTemp->nValue;
			nNum++;
			pTemp=pTemp->pNext;
		}
	}
	
	//释放
	Bucket *pDel = NULL;
	for(i=0;i<nMaxIndex-nMinIndex+1;i++)
	{
		pTemp = pBucket[i];
		while(pTemp)
		{
			pDel=pTemp;
			pTemp=pTemp->pNext;
			free(pDel);
			pDel=NULL;
		}
	}
	free(pBucket);
	pBucket=NULL;

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
	int arr[] = {206,823,171,162,293,234,305,116};

	BucketSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
