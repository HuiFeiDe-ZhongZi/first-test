#include<stdio.h>

void SelectSort(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	int i,j;
	int nMin;
	
	for(i =0;i<len-1;i++)
	{
		nMin =i;
		for(j =i +1;j<len;j++)
		{
			if(arr[j]<arr[nMin])
			{
				arr[j] = arr[j]^arr[nMin];
				arr[nMin] = arr[j]^arr[nMin];
				arr[j] = arr[j]^arr[nMin];
			}
		}
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
	SelectSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
