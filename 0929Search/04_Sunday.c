#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *GetNext(char *match)
{
	int *pNext = NULL;
	pNext =(int*)malloc(sizeof(int)*256);

	//初值
	memset(pNext,-1,sizeof(int)*256);

	//下标
	int i;
	for(i = 0;i<strlen(match);i++)
	{
		pNext[match[i]]=i;
	}
	return pNext;
}


int SundaySearch(char *src,char *match)
{
	if(src == NULL || match == NULL)return -1;

	//获得next数组
	int *pNext = NULL;
	pNext = GetNext(match);

	//匹配
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < strlen(src)&& j<strlen(match))
	{
		if(src[i] == match[j])
		{
			i++;
			j++;
		}
		else
		{
			if(k +strlen(match) < strlen(src))
			{
				k = k + strlen(match) - pNext[src[k+strlen(match)]];
				i = k;
				j = 0;
			}
			else
			{
				return -1;
			}
		}
	}

	if(j == strlen(match))
	{
		return i -j;
	}
	else
	{
		return -1;
	}
}


int main()
{
	int k;
	k = SundaySearch("sakafjdslaksdfjla","jdslak");
	printf("%d\n",k);

	return 0;
}
