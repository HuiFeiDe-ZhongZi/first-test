#include<stdio.h>

//挖坑填补
int Sort(int arr[],int nLow,int nHigh)
{
	int temp;
	temp = arr[nLow];

	while(nLow < nHigh)
	{
		//从后向前找比标准值小的
		while(nLow<nHigh)
		{
			if(arr[nHigh]<temp)
			{
				arr[nLow]=arr[nHigh];
				nLow++;
				break;
			}
			nHigh--;
		}

		//从前向后找比标准值大的
		while(nLow<nHigh)
		{
			if(arr[nLow]>temp)
			{
				arr[nHigh]=arr[nLow];
				nHigh--;
				break;
			}
			nLow++;
		}
	}

	//标准值放入
	arr[nLow] =temp;
	return nLow;
}


//区间分割
int Sort1(int arr[],int nLow,int nHigh)
{
	int small =nLow -1;

	for(nLow;nLow<nHigh;nLow++)
	{
		if(arr[nLow] <arr[nHigh])
		{
			if(++small != nLow)
			{
				arr[small] = arr[nLow]^arr[small];
				arr[nLow] = arr[nLow]^arr[small];
				arr[small] = arr[nLow]^arr[small];
			}
		}
	}
	//值放入
	if(++small != nHigh)
	{ 
		arr[small]=arr[nHigh]^arr[small];
		arr[nHigh]=arr[nHigh]^arr[small];
		arr[small]=arr[nHigh]^arr[small];
	}
	return small;
}

void QuickSort(int arr[],int nLow,int nHigh)
{
	if(arr == NULL || nLow>= nHigh)return;

	//标准值
	int nStandard;

	nStandard = Sort1(arr,nLow,nHigh);

	//分为两部分
	QuickSort(arr,nLow,nStandard-1);
	QuickSort(arr,nStandard+1,nHigh);
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
	QuickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
