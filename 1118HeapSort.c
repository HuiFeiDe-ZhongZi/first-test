#include<stdio.h>

#define LEFT 2*nRootId+1
#define RIGHT 2*nRootId+2
void Adjust1(int arr[], int len, int nRootId)
{
	while (1)
	{
		// ��������
		if (RIGHT < len)
		{
			// �Ƚ��������ӵĴ�С
			if (arr[LEFT] > arr[RIGHT])
			{
				// ��ĺ͸��ױȽ�
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
		// һ������
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
		// û�к���
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

		// ��ֵ�븸�ױȽ�
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

	// ����ʼ��
	int i;
	for (int i = len / 2 - 1; i>=0; i--)
	{
		// ���������׽ڵ�
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