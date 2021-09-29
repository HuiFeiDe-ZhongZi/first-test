#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct hash
{
	int nValue;
	struct hash *pNext;
}Hash;

Hash **CreateHashTable(int arr[],int len)
{
	if(arr == NULL || len <= 0)return NULL;

	//申请
	Hash ** pHash = (Hash**)malloc(sizeof(Hash*)*len);
	bzero(pHash,sizeof(Hash*)*len);

	//元素入表
	int i;
	int nIndex;
	Hash *pTemp = NULL;
	for(i = 0;i <len;i++)
	{
		nIndex=arr[i]%len;

		pTemp = (Hash*)malloc(sizeof(Hash));
		pTemp->nValue = arr[i];

		//头添加
		pTemp->pNext = pHash[nIndex];
		pHash[nIndex]=pTemp;
	}

	return pHash;
}

void HashSearch(Hash **pHash,int len,int nNum)
{
	if(pHash == NULL || len<=0)return;

	int nIndex =nNum%len;
	Hash *pNode =pHash[nIndex];

	while(pNode)
	{
		if(pNode->nValue == nNum)
		{
			printf("%d\n",nNum);
			return;
		}
		pNode = pNode->pNext;
	}
	printf("failed.\n");
}


int main()
{
	int arr[] = {10,88,26,1,45,209,17,288,53};
	Hash **pHash=CreateHashTable(arr,sizeof(arr)/sizeof(arr[0]));
	HashSearch(pHash,sizeof(arr)/sizeof(arr[0]),4);
	return 0;
}
