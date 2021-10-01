#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CountSort(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	int i;
	int nMin = arr[0];
	int nMax = arr[0];

	//找最大值 最小值
	for(i =1;i<len;i++)
	{
		while(arr[i] >nMax)
		{
			nMax=arr[i];
		}
		while(arr[i]<nMin)
		{
			nMin = arr[i];
		}
	}
	
	//计数数组
	int *pCount = (int*)malloc(sizeof(int)*(nMax-nMin+1));
	memset(pCount,0,sizeof(int)*(nMax-nMin+1));

	//计数
	for(i =0;i<len;i++)
	{
		pCount[arr[i]-nMin]++;
	}

	//放数据
	int j =0;
	for(i =0;i<nMax-nMin+1;i++)
	{
		while(pCount[i] != 0)
		{
			arr[j] = i + nMin;
			j++;
			pCount[i]--;
		}
	}

	//释放
	free(pCount);
	pCount=NULL;

}

void Print(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	int i;
	for(i =0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");
}

int main()
{
	int arr[]={3,8,1,0,6,9,4,2,5,7};
	CountSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
