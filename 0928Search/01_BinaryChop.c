#include<stdio.h>

int BinaryChop(int arr[],int len,int nNum)
{
	if(arr == NULL || len <= 0)return -1;

	int mid;
	int pHead=0;
	int pTail=len-1;
	while(pHead <= pTail)
	{
		mid=pHead+(pTail-pHead)/2;
		if(arr[mid] == nNum)
		{
			return mid;
		}
		else if(arr[mid]>nNum)
		{
			//左侧
			pTail = mid-1; 
		}
		else
		{
			//右侧
			pHead= mid+1;
		}
	}	
	return -1;
}



int main()
{
	int arr[]={1,2,3,4,5,6,7};
	printf("%d\n",BinaryChop(arr,sizeof(arr)/sizeof(arr[0]),3));
	return 0;
}

