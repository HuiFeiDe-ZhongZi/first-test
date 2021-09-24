#include<stdio.h>


void SelectSort(int arr[],int len)
{
	if(arr == NULL || len <=0 )return;
	int i;
	int j;
	int nMin;

	for(i = 0; i < len-1; i++)
	{
		nMin = i;
		for(j = i+1;j<len;j++)
		{
			if(arr[j]<arr[nMin])
			{
				nMin = j;
			}
		}

		//最小值放入
		if(i != nMin)
		{
			arr[i] = arr[i]^arr[nMin];
			arr[nMin] = arr[i]^arr[nMin];
			arr[i] = arr[i]^arr[nMin];
		}
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

	SelectSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
