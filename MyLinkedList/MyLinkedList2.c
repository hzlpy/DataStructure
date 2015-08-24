#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//定义节点
typedef struct node{
	struct node *pNext;
	int value;
} NODE, *PNODE;

PNODE createLinkedList()
{
	//声明一个头节点
	PNODE pHeadNode = (PNODE)malloc(sizeof(NODE));
	PNODE pTailNode;
	int length = 0;
	int i = 0;
	int value = 0;
	if (NULL == pHeadNode) {
		printf("内存申请失败，退出程序。\n");
		exit(-1);
	}

	pTailNode = pHeadNode;
	pTailNode->pNext = NULL;
	printf("input length:\n");

	scanf("%d", &length);
	for (i = 1; i <= length; i++)
	{

		//申请一个新节点
		PNODE pNode = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNode) {
			printf("内存申请失败，退出程序。\n");
			exit(-1);
		}

		printf("input %dth node's value.\n", i);
		scanf("%d", &value);
		pNode->value = value;
		pTailNode->pNext = pNode;
		pTailNode = pNode;
		pNode->pNext = NULL;
	}
	return pHeadNode;
}

int length (PNODE pHeadNode)
{
	int len = 0;
	PNODE pNode;
	if (NULL == pHeadNode)
	{
		return len;
	}
	pNode = pHeadNode->pNext;
	while (NULL != pNode)
	{
		len ++;
		pNode = pNode->pNext;
	}
	return len;
}

void traverse(PNODE pHeadNode)
{
	PNODE pNode;
	if (NULL == pHeadNode)
	{
		return;
	}
	pNode = pHeadNode->pNext;
	printf("traverse.. \n");
	while (NULL != pNode)
	{
		printf("%d ", pNode->value);
		pNode = pNode->pNext;
	}
	printf("\n");
}

PNODE reverse(PNODE pHeadNode)
{
	PNODE pReverseHead;
	PNODE pTemp;
	PNODE pNode;
	if (NULL == pHeadNode)
	{
		exit(-1);
	}
	pReverseHead = (PNODE)malloc(sizeof(NODE));

	if (NULL == pReverseHead)
	{
		printf("内存申请失败，退出程序。\n");
		exit(-1);
	}
	pReverseHead->pNext = NULL;
	pNode = pHeadNode->pNext;
	while (NULL != pNode)
	{
		pTemp = pReverseHead->pNext;
		pReverseHead->pNext = pNode;
		pNode = pNode->pNext;
		pReverseHead->pNext->pNext = pTemp;
	}
	return pReverseHead;
}

//如果index = 2，表示在第2个节点前插入一个新节点
void insert(PNODE pHeadNode, int index, int value)
{
    int i = 0;
    PNODE pNode;//定义一个节点，表示第(index-1)个节点
    PNODE pNew;
    printf("input new node's index and value..\n");
    scanf("%d,%d", &index, &value);
    if (NULL == pHeadNode)
    {
        return;
    }
    if (index <= 0 && index > length(pHeadNode)+1)
    {
        return;
    }

    pNode = pHeadNode;
    while (NULL != pNode->pNext)
    {
        i ++;
        if (i <= index - 1)
        {
            pNode = pNode->pNext;
        }
        else
        {
            break;
        }
    }
    //我们需要在第(index-1)个节点与第index个节点之间插入一个新的节点
    pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        return;
    }
    pNew->value = value;
    pNew->pNext = NULL;
    if (index == length(pHeadNode)+1)
    {
        pNode->pNext = pNew;
    }
    else
    {
        pNew->pNext = pNode->pNext;
        pNode->pNext = pNew;
    }
}
//链表节点从1开始计数。
//删掉第index个节点
void deleteNode(PNODE pHeadNode, int index)
{
    PNODE pNode;
    int i = 0;
    if(pHeadNode == NULL)
    {
        return;
    }

    printf("input delete node's index..\n");
    scanf("%d", &index);

    if (index <= 0 && index > length(pHeadNode))
    {
        return;
    }
    //pNode为第(index-1)个节点
    pNode = pHeadNode;
    while (NULL != pNode->pNext)
    {
        i++;
        if (i<index) {
            pNode = pNode->pNext;
        }
        else {
            break;
        }
    }
    if (index == length(pHeadNode))
    {
        //pNode = pNode->pNext;
        //free(pNode);
        //pNode = NULL;
        pNode->pNext = NULL;
        return;
    }
    PNODE pTemp = pNode->pNext;
    pNode->pNext = pNode->pNext->pNext;
    free(pTemp);
    pTemp = NULL;
}

//找出单链表中倒数第k个节点
PNODE getLastKNode(PNODE pHeadNode, int k)
{
	if (NULL == pHeadNode || k <= 0) {
		return NULL;
	}
	PNODE p1, p2;
	int i = 0;
	p1 = p2 = pHeadNode;
	//让p1先走k步
	for (i=0; i < k; i++) {
		p1 = p1->pNext;
	}
	//然后p1, p2一起走。当p1到达链表的最后一个结点时，p2指向的便是链表的倒数第k个结点
	while (p1 != NULL) {
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	return p2;
}

//逆序输出单链表
void printReverse(PNODE pHeadNode)
{
	if (pHeadNode->pNext != NULL) {
		printReverse(pHeadNode->pNext);
		printf("%d ", pHeadNode->pNext->value);
	}
}

int main()
{
	PNODE pHeadNode = createLinkedList();
	int len = length(pHeadNode);
	PNODE pReverseHead;
    int index,value, k;
	printf("len = %d\n", len);
	traverse(pHeadNode);
	//pReverseHead = reverse(pHeadNode);
	//traverse(pReverseHead);
    //insert(pHeadNode, index, value);
    //traverse(pHeadNode);
    //deleteNode(pHeadNode, index);
    //traverse(pHeadNode);
	printReverse(pHeadNode);
	printf("\n");
	k = 2;
	printf("Last %d node is %d\n",k, getLastKNode(pHeadNode, k)->value);
	return 0;
}
