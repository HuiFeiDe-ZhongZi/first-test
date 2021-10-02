#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Sort(int arr[],int nLow,int nHigh)
{
	int temp;
	temp = arr[nLow];

	while(nLow < nHigh)
	{
		while(nLow < nHigh)
		{
			//从后向前找比标准值小的
			if(arr[nHigh]<temp)
			{
				arr[nLow] = arr[nHigh];
				nLow++;
				break;
			}
			nHigh--;
		}
		while(nLow<nHigh)
		{
			//从前向后找比标准值大的
			if(arr[nLow]>temp)
			{
				arr[nHigh] = arr[nLow];
				nHigh--;
				break;
			}
			nLow++;
		}
	}
	//标准值放入
	arr[nLow]=temp;
	return temp;
}

int Sort1(int arr[],int nLow,int nHigh)
{
	int nSmall = nLow-1;

	for(nLow;nLow<nHigh;nLow++)
	{
		//小区间扩张
		if(arr[nLow]<arr[nHigh])
		{
			if(++nSmall!=nLow)
			{
				arr[nSmall]=arr[nSmall]^arr[nLow];
				arr[nLow]=arr[nSmall]^arr[nLow];
				arr[nSmall]=arr[nSmall]^arr[nLow];
			}
		}
	}
	if(++nSmall != nHigh)
	{
		arr[nSmall]=arr[nSmall]^arr[nHigh];
		arr[nHigh]=arr[nSmall]^arr[nHigh];
		arr[nSmall]=arr[nSmall]^arr[nHigh];
	}
	return nSmall;
}


void QuickSort(int arr[],int nLow,int nHigh)
{
	if(arr == NULL || nLow >= nHigh)return;

	//标准值
	int nStandard;

	nStandard = Sort1(arr,nLow,nHigh);

	//两边继续
	QuickSort(arr,nLow,nStandard-1);
	QuickSort(arr,nStandard+1,nHigh);
}

void Print(int arr[],int len)
{
	if(arr == NULL || len<=0)return;

	int i;
	for(i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[]={5,8,0,4,6,2,3,1,7,9};
	QuickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	Print(arr,sizeof(arr)/sizeof(arr[0]));


	return 0;
}

