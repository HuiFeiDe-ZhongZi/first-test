#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[],int nLow,int nHigh)
{
	int nBegin1;
	int nBegin2;
	int nEnd1;
	int nEnd2;

	int *pTemp = (int*)malloc(sizeof(int)*(nHigh - nLow +1));

	nBegin1 = nLow;
	nEnd1 = nLow + (nHigh - nLow)/2;
	nBegin2 = nEnd1 +1;
	nEnd2 = nHigh;

	//合并
	int i =0;
	while(nBegin1 <= nEnd1 && nBegin2 <= nEnd2)
	{
		if(arr[nBegin1] < arr[nBegin2])
		{
			pTemp[i] = arr[nBegin1];
			i++;
			nBegin1++;
		}
		else
		{
			pTemp[i] = arr[nBegin2];
			i++;
			nBegin2++;
		}
	}
	//将有剩余的数组元素依次放入
	while(nBegin1 <= nEnd1)
	{
		pTemp[i]=arr[nBegin1];
		i++;
		nBegin1++;
	}

	while(nBegin2 <= nEnd2)
	{
		pTemp[i]= arr[nBegin2];
		i++;
		nBegin2++;
	}

	//放回原数组
	for(i=0;i<nHigh-nLow + 1;i++)
	{
		arr[nLow+i] = pTemp[i];
	}

	//释放
	free(pTemp);
	pTemp = NULL;
}
		

void MergeSort(int arr[],int nLow,int nHigh)
{
	if(arr == NULL || nLow >=nHigh )return;

	//标准值
	int mid =nLow+(nHigh-nLow)/2; 

	//分为两部分
	MergeSort(arr,nLow,mid);
	MergeSort(arr,mid+1,nHigh);

	//合并
	Merge(arr,nLow,nHigh);

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

	MergeSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
