#include<stdio.h>

void BubbldeSort(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	int i,j;
	int flag;
	for(i = 0; i< len -1;i++)
	{
		flag = 0;
		for(j =0;j<len -i -1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				arr[j] = arr[j]^arr[j+1];
				arr[j+1] = arr[j]^arr[j+1];
				arr[j] = arr[j]^arr[j+1];
				flag = j+1;
			}
		}
		if(flag ==0)return;
		i = len - flag -1;

	}
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
	BubbldeSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
