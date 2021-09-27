#include<stdio.h>


void ShellSort(int arr[],int len)
{
	if(arr == NULL || len <=0 )return;
	
	int nGap;//间隔
	int i;//分组
	int j;//各组之内排序
	int k;//有序
	int temp;//无序

	//间隔
	for(nGap = len/2;nGap>=1;nGap/=2)
	{
		//分组
		for(i = 0;i<nGap;i++)
		{
			//各组之内无序元素排序
			for(j=i+nGap;j<len;j+=nGap)
			{
				k = j-nGap;  //有序的最后一个元素
				temp = arr[j]; //无序的第一个元素
				while(arr[k] > temp && k>=i)
				{
					arr[k+nGap] = arr[k];
					k -= nGap;
				}

				//元素放入
				arr[k + nGap]=temp;
			}
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

	ShellSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
