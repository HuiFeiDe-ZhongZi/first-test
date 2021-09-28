#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *GetNext(char *match)
{
	int *pNext =NULL;
	pNext = (int*)malloc(sizeof(int)*strlen(match));

	pNext[0]=0;
	
	int i = 1;
	int j=i-1;
	while(i <strlen(match))
	{
		if(match[i] == match[pNext[j]])
		{
			pNext[i] = pNext[j]+1;
			i++;
			j=i-1;
		}
		else if(pNext[j]==0)
		{
			pNext[i]=0;
			i++;
			j=i-1;
		}
		else
		{
			//向前跳转 找下一次比较的对象
			j=pNext[j]-1;
		}
	}
	return pNext;
}


int KMP(char *src, char *match)
{
	if(src == NULL || match == NULL)return -1;

	//获得Next数组
	int *pNext = NULL;
	pNext = GetNext(match);

	//匹配
	int i = 0;
	int j = 0;
	while(i<strlen(src) && j<strlen(match))
	{
		if(src[i] == match[j])
		{
			i++;
			j++;
		}
		else
		{
			//不等 匹配串向前跳
			if(j==0)
			{
				i++;
			}
			else
			{
				j = pNext[j-1];
			}
		}
	}

	//匹配成功 匹配串走完
	if(j == strlen(match))
	{
		return i-j;
	}
	//匹配失败
	else
	{
		return -1;
	}
}

	


int main()
{
	
	int n;
	n =KMP("aweqreyabcabcdasio","abcabcd");
	printf("%d\n",n);
	

	return 0;
}
