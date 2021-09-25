#include<stdio.h>


void InsertSort(int arr[],int len)
{
	if(arr == NULL || len <=0 )return;
	
	int i;//有序
	int j;//无序
	int temp;//临时的保存变量

	//无序元素
	for(i = 1;i<len;i++)
	{
		j=i-1;//有序的最后一个元素
		temp = arr[i];//无序的第一个元素

		while(arr[j] > temp && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}

		//无序值放入
		arr[j + 1] = temp;
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

	InsertSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
