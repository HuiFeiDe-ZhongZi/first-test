#include<stdio.h>


//挖坑填补
int Sort(int arr[],int nLow,int nHigh)
{
	int temp;
	temp = arr[nLow];

	while(nLow<nHigh)
	{
		//从后向前找比标准值小的
		while(nLow<nHigh)
		{
			if(arr[nHigh]<temp)
			{
				//放前面
				arr[nLow]=arr[nHigh];
				nLow++;
				break;
			}
			nHigh--;
		}
		//从前找比标准值大的
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
	arr[nLow]=temp;
	return nLow;
}

//区间分割
int Sort1(int arr[],int nLow,int nHigh)
{
	int nSmall = nLow - 1;

	for(nLow;nLow<nHigh;nLow++)
	{
		if(arr[nLow]<arr[nHigh])
		{
			if(++nSmall != nLow)
			{
				arr[nSmall]=arr[nSmall]^arr[nLow];
				arr[nLow]=arr[nSmall]^arr[nLow];
				arr[nSmall]=arr[nSmall]^arr[nLow];
			}
		}
	}

	//值放入
	if(++nSmall != nHigh)
	{
		arr[nSmall]=arr[nHigh]^arr[nSmall];
		arr[nHigh]=arr[nHigh]^arr[nSmall];
		arr[nSmall]=arr[nHigh]^arr[nSmall];
	}
	return nSmall;
}
void QuickSort(int arr[],int nLow,int nHigh)
{
	if(arr == NULL || nLow >=nHigh )return;

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
	for(i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {3,9,2,6,8,0,1,5};

	QuickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
