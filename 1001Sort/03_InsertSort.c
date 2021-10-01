#include<stdio.h>

void BubbldeSort(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	int i;
	int j;
	int temp;
	
	for(int i = 1;i<len;i++)
	{
		j = i-1; //有序最后一个元素
		temp = arr[i];//无序的第一个元素

		while(arr[j]>temp && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}

		arr[j+1] = temp;
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
