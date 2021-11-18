#include<stdio.h>

#define LEFT 2*nRootId+1
#define RIGHT 2*nRootId+2
void Adjust1(int arr[], int len, int nRootId)
{
	while (1)
	{
		// 两个孩子
		if (RIGHT < len)
		{
			// 比较两个孩子的大小
			if (arr[LEFT] > arr[RIGHT])
			{
				// 大的和父亲比较
				if (arr[LEFT] > arr[nRootId])
				{
					arr[LEFT] = arr[nRootId] ^ arr[LEFT];
					arr[nRootId] = arr[nRootId] ^ arr[LEFT];
					arr[LEFT] = arr[nRootId] ^ arr[LEFT];

					nRootId = LEFT;
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (arr[RIGHT] > arr[nRootId])
				{
					arr[RIGHT] = arr[nRootId] ^ arr[RIGHT];
					arr[nRootId] = arr[nRootId] ^ arr[RIGHT];
					arr[RIGHT] = arr[nRootId] ^ arr[RIGHT];

					nRootId = RIGHT;
					continue;
				}
				else
				{
					break;
				}
			}
		}
		// 一个孩子
		else if (LEFT < len)
		{
			if (arr[LEFT] > arr[nRootId])
			{
				arr[LEFT] = arr[nRootId] ^ arr[LEFT];
				arr[nRootId] = arr[nRootId] ^ arr[LEFT];
				arr[LEFT] = arr[nRootId] ^ arr[LEFT];

				nRootId = LEFT;
				continue;
			}
			else
			{
				break;
			}
		}
		// 没有孩子
		else
		{
			break;
		}
	}
}

void Adjust2(int arr[], int len, int nRootId)
{
	int MAX;

	for (MAX = LEFT; MAX < len; MAX = LEFT)
	{
		if (RIGHT < len)
		{
			if (arr[RIGHT] > arr[MAX])
			{
				MAX = RIGHT;
			}
		}

		// 大值与父亲比较
		if (arr[MAX] > arr[nRootId])
		{
			arr[MAX] = arr[nRootId] ^ arr[MAX];
			arr[nRootId] = arr[nRootId] ^ arr[MAX];
			arr[MAX] = arr[nRootId] ^ arr[MAX];

			nRootId = MAX;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int arr[], int len)
{
	if (arr == NULL || len <= 0)return;

	// 建初始堆
	int i;
	for (int i = len / 2 - 1; i>=0; i--)
	{
		// 调整各父亲节点
		Adjust2(arr, len, i);
	}

	for (i = len - 1; i >= 0; i--)
	{
		arr[0] = arr[i] ^ arr[0];
		arr[i] = arr[i] ^ arr[0];
		arr[0] = arr[i] ^ arr[0];

		Adjust2(arr, i, 0);
	}
}

void Print(int arr[], int len)
{
	if (arr == NULL || len <= 0)return;
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[] = { 8,1,5,0,6,4,9,3,2,7 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	

	return 0;
}