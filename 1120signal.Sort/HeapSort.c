#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEFT 2*nRootId+1
#define RIGHT 2*nRootId+2

void Adjust(int arr[],int len,int nRootId)
{
	int Max;
	for(Max = LEFT; Max < len; Max = LEFT)
	{
		//两个孩子情况
		if(RIGHT < len)
		{
			if(arr[RIGHT]>arr[Max])
			{
				Max = RIGHT;
			}
		}

		if(arr[Max]>arr[nRootId])
		{
			arr[Max] = arr[nRootId]^arr[Max];
			arr[nRootId] = arr[nRootId]^arr[Max];
			arr[Max] = arr[nRootId]^arr[Max];

			nRootId = Max;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int arr[],int len)
{
	if(arr == NULL|| len <= 0)return;

	// 建立初始堆
	for(int i = len/2; i >=0; i--)
	{
		Adjust(arr,len,i);
	}

	// 交换首尾位置 在不断调整
	for(int i = len-1;i >= 0; i--)
	{
		arr[0] = arr[i]^arr[0];
		arr[i] = arr[i]^arr[0];
		arr[0] = arr[i]^arr[0];

		Adjust(arr,i,0);
	}
}

void Print(int arr[],int len)
{
	if(arr == NULL|| len <= 0)return;

	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[]={8,4,0,6,2,7,9,3,1,5};
	HeapSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
