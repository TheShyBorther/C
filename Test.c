#include <stdio.h>
#include <stdlib.h>

void AddListHead(int a);
void AddListTail(int a);
void ScanList();
void FreeList();
void DeleListHead();
void  DeleListTail();
void AddListRand(int index, int a);
void DeleListRand(int index);
struct Node* SelectNode(int a);


struct Node
{
	int data;
	struct Node* pNext;

};

struct Node* g_pHead = NULL;
struct Node* g_pEnd = NULL;






int main(void)
{
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	g_pHead;
	for (int i = 0; i < 10;i++)
	{
		AddListHead(a[i]);
	}
	ScanList();
	DeleListHead();
	ScanList();
	

	
	system("pause");

	return 0;
}

void AddListHead(int a)
{
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	pTemp->data = a;
	pTemp->pNext = NULL;

	if (NULL == g_pHead)
	{
		g_pEnd = pTemp;
		g_pHead = pTemp;

	}
	else
	{
		g_pHead->pNext = pTemp;
		g_pHead = pTemp;
	}

}

void AddListTail(int a)
{
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	pTemp->data = a;
	pTemp->pNext = NULL;

	if (NULL == g_pHead)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else
	{
		g_pEnd->pNext = pTemp;
		g_pEnd = pTemp;

	}
}

void ScanList()
{
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		printf("  %d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
}

struct  Node* SeleteList(int a)
{
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (a == pTemp->data)
		{
			return pTemp;
		}
		return NULL;
	}
};

void FreeList()
{
	
		struct Node* pTemp = g_pHead;
		while(pTemp != NULL)
		{
		struct Node* pt = pTemp;
		
		pTemp = pTemp->pNext;
		free(pt);
		
		}
	g_pHead = NULL;
	g_pEnd = NULL;
}

void DeleListHead()
{
	if (NULL == g_pHead)    //   []->[]->[]
	{
		return NULL;
	}
	
		struct Node* pTemp = g_pHead;
		g_pHead = g_pHead->pNext;//删去头节点顺便更新头指针
		free(pTemp);
	


}

void  DeleListTail()
{
	if (NULL == g_pHead)
	{
		return NULL;
	}
	else
	{
		struct Node* pTemp = g_pHead;
		while (pTemp->pNext == g_pEnd)
		{
			pTemp = pTemp->pNext;
		}
		g_pEnd = pTemp;
		free(pTemp);
	}
}

void AddListRand(int index, int a)
{
	struct Node* pt = SeleteList(index);

	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	pTemp->data = a;
	pTemp->pNext = NULL;


	if (NULL == g_pHead)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else if (g_pHead == pTemp)
	{
		AddListHead(a);
	}
	else if (g_pEnd == pTemp)
	{
		AddListTail(a);
	}
	else
	{
		pTemp->pNext = pt->pNext;
		pt->pNext = pTemp;

	}
}

void DeleListRand(int index)
	{
	struct Node* pt = SeleteList(index);

	struct Node* pTemp = g_pHead;


	if (NULL == g_pHead)
	{
		return NULL;
	}
	else if (g_pHead == pTemp)
	{
		DeleListHead();
	}
	else if (g_pEnd == pTemp)
	{
		DeleListTail();
	}
	else
	{
		while (pTemp->pNext != pt)
		{
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pt->pNext;
		free(pt);
	}
}

struct Node* SelectNode(int a) 
{
	return NULL;
}


