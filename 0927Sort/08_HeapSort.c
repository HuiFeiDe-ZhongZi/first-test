#include<stdio.h>

#define LEFT 2*nRootID+1
#define RIGHT 2*nRootID+2


//无优化
void Adjust(int arr[],int len,int nRootID)
{
	while(1)
	{
		//两个孩子
		if(RIGHT < len)
		{
			//比较两个孩子的大小
			if(arr[LEFT]>arr[RIGHT])
			{
				//大的和父亲比较
				if(arr[LEFT]>arr[nRootID])
				{
					arr[LEFT] = arr[LEFT]^arr[nRootID]; 
					arr[nRootID] = arr[LEFT]^arr[nRootID]; 
					arr[LEFT] = arr[LEFT]^arr[nRootID]; 

					nRootID = LEFT;
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(arr[RIGHT]>arr[nRootID])
				{
					arr[RIGHT] = arr[nRootID] ^ arr[RIGHT];
					arr[nRootID] = arr[nRootID] ^ arr[RIGHT];
					arr[RIGHT] = arr[nRootID] ^ arr[RIGHT];

					nRootID = RIGHT;
					continue;
				}
				else
				{
					break;
				}
			}
		}
		//一个孩子
		else if(LEFT < len)
		{
			if(arr[LEFT]>arr[nRootID])
			{
				arr[LEFT] = arr[LEFT]^arr[nRootID]; 
				arr[nRootID] = arr[LEFT]^arr[nRootID]; 
				arr[LEFT] = arr[LEFT]^arr[nRootID]; 

				nRootID = LEFT;
				continue;
			}
			else
			{
				break;
			}
		}
		//没有孩子
		else
		{
			break;
		}

	}
}

//有优化
void Adjust2(int arr[],int len,int nRootID)
{
	int Max;
	for(Max = LEFT;Max<len;Max=LEFT)
	{
		//两个孩子
		if(RIGHT <len)
		{
			if(arr[Max]<arr[RIGHT])
			{
				Max = RIGHT;
			}
		}

		if(arr[Max]>arr[nRootID])
		{
			arr[Max] = arr[Max] ^arr[nRootID];
			arr[nRootID] = arr[Max] ^arr[nRootID];
			arr[Max] = arr[Max] ^arr[nRootID];

			nRootID=Max;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int arr[],int len)
{
	if(arr == NULL || len <= 0)return;

	//创建初始堆
	int i;
	for(i = len/2-1;i>=0;i--)
	{
		//调整父亲节点
		Adjust2(arr,len,i);
	}

	//排序
	for(i= len-1;i>0;i--)
	{
		//交换
		arr[0] = arr[0]^arr[i];
		arr[i] = arr[0]^arr[i];
		arr[0] = arr[0]^arr[i];
		
		//调整对顶
		Adjust2(arr,i,0);
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

	HeapSort(arr,sizeof(arr)/sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}
