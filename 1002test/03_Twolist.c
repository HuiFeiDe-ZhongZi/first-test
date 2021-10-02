#include<stdio.h>
#include<stdlib.h>


typedef struct list
{
	int nValue;
	struct list *pNext;
}List;

List *CreateList()
{
	int nNum;
	printf("请输入链表个数：\n");
	scanf("%d",&nNum);

	List *pHead = NULL;
	List *pTail = NULL;
	List *pTemp = NULL;

	int i;
	int tem;
	for(i = 0;i<nNum;i++)
	{
		printf("请输入对应的值:\n");
		scanf("%d",&tem);

		pTemp = (List*)malloc(sizeof(List));
		pTemp->nValue = tem;
		pTemp->pNext = NULL;

		if(pHead == NULL)
		{
			pHead = pTemp;
		}
		else
		{
			pTail->pNext=pTemp;
		}
		pTail=pTemp;
	}
	return pHead;
}

//链表递归 倒序打印
void ReversePrint(List *pHead)
{
	if(pHead == NULL)return;

	ReversePrint(pHead->pNext);

	printf("%d ",pHead->nValue);
}

void Print(List *pHead)
{
	while(pHead)
	{
		printf("%d ",pHead->nValue);
		pHead = pHead->pNext;
	}
	printf("\n");
}

//链表节点翻转
List *Reverse(List *pHead)
{
	if(pHead == NULL || pHead->pNext ==NULL)return pHead;

	List *p1 = NULL;
	List *p2 =pHead;
	List *p3 =pHead->pNext;

	while(p3)
	{
		p2->pNext=p1;

		p1 = p2;
		p2 = p3;
		p3 = p3->pNext;
	}

	p2->pNext = p1;
	return p2;
}


//两链表相交是否相交  相交的交点
List *Jiaodian(List *pHead1,List *pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL)return NULL;

	//定义两变量记录 链表1 链表2个数
	int len1 = 0;
	int len2 = 0;
	List *p1 = pHead1;
	List *p2 = pHead2;
	//看链表是否相交  看两链表最后一个节点数据是否相同
	while(pHead1->pNext)
	{
		pHead1 = pHead1->pNext;
		len1++;
	}
	while(pHead2->pNext)
	{
		pHead2=pHead2->pNext;
		len2++;
	}
	if(pHead1->nValue == pHead2->nValue)
	{
		printf("两链表相交\n");
	}
	else
	{
		printf("两链表不相交\n");
	}
	
	//两链表交点  两链表节点数相减后 一起继续向前走
	int len3 = 0;

	if(len1 > len2)
	{
		len3 = len1-len2;
		while(len3)
		{
			len3--;
			p1=p1->pNext;
		}
	}
	else
	{
		len3 = len2 -len1;
		while(len3)
		{
			len3--;
			p2=p2->pNext;
		}
	}

	//让两个一起走 走到同一交点退出 返回
	while(p1->nValue != p2->nValue)
	{
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	return p1;
}

	


int main()
{
	List *pHead1 = CreateList();
	List *pHead2 = CreateList();
	Print(pHead1);
	Print(pHead2);
	List *pNode = Jiaodian(pHead1,pHead2);
	printf("%d\n",pNode->nValue);

	




	return 0;
}

