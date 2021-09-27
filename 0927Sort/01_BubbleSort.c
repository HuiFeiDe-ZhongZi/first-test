#include<stdio.h>


void BubbleSort(int arr[],int len)
{
	if(arr == NULL || len <=0 )return;
	int i;
	int j;
	int nflag;
	int nCount = 0;
	for(i=0;i<len-1;i++)
	{
		nflag=0;
		for(j = 0;j<len -1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				nflag=j+1;
			}
			nCount++;
		}
		if(nflag==0)break;// 标记 若不进去比较
		i=len-nflag-1;//从不进行交换前 在进行比较
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

	BubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
