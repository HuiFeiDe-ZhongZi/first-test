#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct trie
{
	int nCount;
	char *str;
	struct trie *pCharacter[26];
}TrieTree;

TrieTree *GetNode()
{
	TrieTree *pTemp = NULL;
	pTemp = (TrieTree*)malloc(sizeof(TrieTree));
	memset(pTemp,0,sizeof(TrieTree));
	return pTemp;
}

void Addword(TrieTree *pTree,char *str)
{
	int i =0;
	while(i<strlen(str))
	{
		if(pTree->pCharacter[str[i]-97] == NULL)
		{
			pTree->pCharacter[str[i]-97] =GetNode();
		}
		pTree = pTree->pCharacter[str[i]-97];
		i++;
	}

	//末尾标志
	pTree->nCount++;
	pTree->str=str;
}

TrieTree *CreateTrieTree(char *str[],int nLen)
{
	if(str == NULL || nLen <= 0)return NULL;

	//根
	TrieTree *pRoot = GetNode();
	
	//单词添加
	int i;
	for(i =0;i<nLen;i++)
	{
		Addword(pRoot,str[i]);
	}

	return pRoot;
}

void Search(TrieTree *pTree,char *str)
{
	if(pTree == NULL || str == NULL)return;

	int i=0;
	while(i<strlen(str))
	{
		if(pTree->pCharacter[str[i]-97] == NULL)
		{
			printf("failed TAT\n");
			return;
		}
		pTree=pTree->pCharacter[str[i]-97];
		i++;
	}

	//末尾检测
	if(pTree->nCount != 0)
	{
		printf("%s\n",pTree->str);
	}
	else
	{
		printf("failed QAQ \n");
		return;
	}
}

void Traversal(TrieTree *pTree)
{
	if(pTree == NULL)return;

	if(pTree->nCount !=0)
	{
		printf("%s\n",pTree->str);
	}

	int i;
	for(i=0;i<26;i++)
	{
		Traversal(pTree->pCharacter[i]);
	}
}


int main()
{
	char *str[]={"apple","lemon","peach","grape","crambola","orange","app","watermelon"};
	TrieTree *pRoot = CreateTrieTree(str,sizeof(str)/sizeof(str[0]));
	//Traversal(pRoot);
	
	Search(pRoot,"appl");
	

	return 0;
}
