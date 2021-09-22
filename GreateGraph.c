#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data
{
	int nValue;
	struct data *pNext;
}Data;

typedef struct queue
{
	int nCount;
	Data *pHead;
	Data *pTail;
}Queue;


void q_Init(Queue **pQueue)
{
	*pQueue=(Queue*)malloc(sizeof(Queue));
	(*pQueue)->nCount=0;
	(*pQueue)->pHead=NULL;
	(*pQueue)->pTail=NULL;
}

Queue *q_Push(Queue *pQueue,int nNum)
{
	if(pQueue==NULL)exit(1);
	
	Data *pTemp=(Data*)malloc(sizeof(Data));
	pTemp->nValue=nNum;
	pTemp->pNext=NULL;
	pQueue->nCount++;

	if(pQueue->pHead==NULL)
	{
			pQueue->pHead=pTemp;
	}
	else
	{
		pQueue->pTail->pNext=pTemp;
	}
	pQueue->pTail=pTemp;
}
	
int q_Pop(Queue *pQueue)
{
	if(pQueue==NULL)exit(1);
	if(pQueue->nCount==0)return -1;

	Data* pDel=pQueue->pHead;
	int num=pQueue->pHead->nValue;
	pQueue->pHead=pQueue->pHead->pNext;
	free(pDel);
	pDel=NULL;

	pQueue->nCount--;

	return num;
}

int q_Isempty(Queue *pQueue)
{
	if(pQueue==NULL)exit(1);

	return pQueue->nCount==0? 1 :0;
}

typedef struct graph
{
	int nVertex;
	int nEdge;
	int *pMatrix;
}Graph;

Graph *CreateGraph()
{
	Graph *pGraph = NULL;
	pGraph = (Graph*)malloc(sizeof(Graph));

	printf("请输入定点个数与边的条数:\n");
	int nV;
	int nE;
	scanf("%d%d",&nV,&nE);
	pGraph->nVertex=nV;
	pGraph->nEdge=nE;

	//空间
	pGraph->pMatrix=(int*)malloc(sizeof(int)*nV*nV);
	bzero(pGraph->pMatrix,sizeof(int)*nV*nV);

	//边
	int v1,v2;
	int i =0;
	for(i=0;i<nE;i++)
	{
		printf("请输入两个顶点确定一条边:\n");
		scanf("%d%d",&v1,&v2);

		if(v1 >= 1 && v1 <= nV && v2 >= 1 &&v2 <= nV && v1 != v2 && pGraph->pMatrix[(v1-1)*nV+(v2-1)] == 0)
		{
			pGraph->pMatrix[(v1-1)*nV+(v2-1)] = 1; 
			pGraph->pMatrix[(v2-1)*nV+(v1-1)] = 1;
		}
		else
		{
			i--;
		}
	}
	return pGraph;
}

void MyDFS(Graph *pGraph,int nBegin,int *pMark)
{
	//打印
	printf("%d ",nBegin);
	//标记
	pMark[nBegin-1]=1;
	//遍历
	int i;
	for(i=0;i<pGraph->nVertex;i++)
	{
		//与其有关的 且未被打印过的顶点
		if(pGraph->pMatrix[(nBegin-1)*pGraph->nVertex+i] == 1 && pMark[i]==0)
		{
			MyDFS(pGraph,i+1,pMark);
		}

	}
}

void DFS(Graph *pGraph,int nBegin)
{
	if(pGraph==NULL)return;

	//标记数组
	int *pMark=(int*)malloc(sizeof(int)*pGraph->nVertex);
	bzero(pMark,sizeof(int)*pGraph->nVertex);

	//顶点处理
	MyDFS(pGraph,nBegin,pMark);

}

void BFS(Graph *pGraph,int nBegin)
{
	if(pGraph==NULL)return;
		
	//队列
	Queue *pQueue=NULL;
	q_Init(&pQueue);

	//计数数组
	int *pMark=(int*)malloc(sizeof(int)*pGraph->nVertex);
	bzero(pMark,sizeof(int)*pGraph->nVertex);

	//入队
	q_Push(pQueue,nBegin);
	pMark[nBegin-1]=1;
	//相关顶点
	while(pQueue->nCount!=0)
	{
		//弹出
		nBegin = q_Pop(pQueue);
		printf("%d ",nBegin);
		//找相关顶点
		int i;
		for(i=0;i<pGraph->nVertex;i++)
		{
			//相关的且未标记的入队
			if(pGraph->pMatrix[(nBegin-1)*pGraph->nVertex+i] == 1 && pMark[i] == 0)
			{
				q_Push(pQueue,i+1);
				pMark[i]=1;
			}
		}
	}

}

int main()
{
	Graph *pGraph=NULL;
	pGraph=CreateGraph();
	DFS(pGraph,3);
	printf("\n");
	
	BFS(pGraph,3);
	printf("\n");

	//数组打印
	/*int i;
	for(i = 0; i<pGraph->nVertex*pGraph->nVertex;i++)
	{
		if(i%pGraph->nVertex == 0)
		{
			printf("\n");
		}

		printf("%d ",pGraph->pMatrix[i]);
	}
	printf("\n");*/


	return 0;
}
