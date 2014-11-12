#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct node
{
	struct node *pNext;//指针域
	int value;//数据域
}NODE, *PNODE;

typedef enum _bool
{
	false,true
}bool;

//函数声明
/*尾插法创建链表*/
PNODE createLinkedList();
/*头插法创建链表*/
PNODE createLinkedList2();
/*遍历链表*/
void traverseLinkedList(PNODE pHeadNode);
// /*删除节点*/
// bool deleteNode(PNODE pHeadNode, int index);
/*删除节点*/
bool deleteNode(PNODE pHeadNode, int index, int *value);
/*添加节点*/
bool insertNode(PNODE pHeadNode, int index, int value);
/*判断链表时候为空*/
bool isEmpty(PNODE pHeadNode);
/*链表长度*/
int length(PNODE pHeadNode);
/*冒泡排序*/
void bubbleSort(PNODE pHeadNode);
/*反转单链表*/
PNODE reverse(PNODE pHeadNode);
int main(void)
{
	int d_value;
	PNODE pReverseNode;
	//创建链表
	//PNODE pHeadNode = createLinkedList();
	PNODE pHeadNode = createLinkedList();

	//链表的长度
 	printf("链表长度为 %d \n",length(pHeadNode));
	//遍历链表
	traverseLinkedList(pHeadNode);

	pReverseNode = reverse(pHeadNode);
	traverseLinkedList(pReverseNode);

//  	//排序
// 	bubbleSort(pHeadNode);
// 	traverseLinkedList(pHeadNode);

// 	//添加节点
// 	insertNode(pHeadNode,4,100);
// 	traverseLinkedList(pHeadNode);
// 	//删除节点
// 	deleteNode(pHeadNode,4,&d_value);
// 	traverseLinkedList(pHeadNode);
// 	printf("被删除的数字是 %d \n",d_value);

}

/*****************************************************************************
    * @function    	: createLinkedList 创建一个单链表
    * @author   	: ZhangLe
    * @date     	: 2014/11/11 21:21
    * @version  	: ver 2.0
    * @inparam  	: void
    * @outparam 	: void
    * @description 	: 
*****************************************************************************/
PNODE createLinkedList()
{
	int i;
	int length;
	int value;
	//为头节点申请内存空间
	PNODE pHeadNode = (PNODE)malloc(sizeof(NODE));
	//尾节点
	PNODE pTailNode = pHeadNode;
	pTailNode->pNext = NULL;
	//判断内存申请是否成功
	if (NULL == pHeadNode)
	{
		printf("内存申请失败，退出程序。\n");
		exit(-1);
	}
	//输入链表的长度，即节点的个数
	printf("请输出链表的长度: ");
	scanf("%d",&length);
	//利用循环添加节点
	for (i=0; i<length; ++i)
	{
		//申请一个新的节点
		PNODE pNewNode = (PNODE)malloc(sizeof(NODE));
		//判断内存申请是否成功
		if (NULL == pNewNode)
		{
			printf("内存申请失败，退出程序。\n");
			exit(-1);
		}
		printf("请输入第%d个节点的值 = ",i+1);
		scanf("%d",&value);
		pNewNode->value = value;
		pTailNode->pNext = pNewNode;//pTailNode,pHeadNode下一个节点地址指向pNewNode
		pNewNode->pNext = NULL;
		pTailNode = pNewNode;//将pNewNode指定为pTailNode,pHeadNode->pNext指向pNewNode，现在也指向pTailNode
	}
	return pHeadNode;
}

/*****************************************************************************
    * @function    	: createLinkedList2 利用头插法创建单链表
    * @author   	: ZhangLe
    * @date     	: 2014/11/11 21:34
    * @version  	: ver 1.0
    * @inparam  	: void
    * @description 	:
*****************************************************************************/
PNODE createLinkedList2()
{
	//声明头节点，并为它动态分配内存
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	int length; //待创建链表的长度
	int data;   //节点的值
	int i;      //循环变量
	PNODE pNew;
	//检查内存是否分配成功
	if (NULL == pHead)
	{
		printf("动态分配内存失败，程序退出。\n");
		exit(-1);
	}
	pHead->pNext = NULL; //初始化为空链表
	//内存分配成功，开始头插法创建链表
	printf("Please input the length of linked list you want to create: ");
	scanf("%d",&length);
	for (i=0; i<length; ++i)
	{
		//为新节点分配内存
		pNew = (PNODE)malloc(sizeof(NODE));
		//检查内存是否分配成功
		if (NULL == pNew)
		{
			printf("动态分配内存失败，程序退出。\n");
			exit(-1);
		}
		//内存分配成功，提示为新节点输入值
		printf("Please input a value for new node: ");
		scanf("%d", &data);
		pNew->value = data;
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;
	}
	return pHead;
}

/*****************************************************************************
    *  @brief    : traverseLinkedList 遍历单链表
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:19
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverseLinkedList(PNODE pHeadNode)
{
	PNODE p = pHeadNode->pNext;
	printf("开始遍历链表\n");
	while(NULL != p)
	{
		printf("%d ",p->value);
		p = p->pNext;
	}
	printf("\n");
}
/*****************************************************************************
    *  @brief    : isEmpty 判断链表时候为空
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:36
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isEmpty(PNODE pHeadNode)
{
	if (NULL == pHeadNode->pNext)
	{
		return true;
	}
	return false;
}
/*****************************************************************************
    *  @brief    : length 获取链表长度
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:39
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
int length(PNODE pHeadNode)
{
	int len = 0;
	PNODE p = pHeadNode->pNext;
	while(NULL != p)
	{
		++len;
		p = p->pNext;
	}
	return len;
}
/*****************************************************************************
    *  @brief    : bubbleSort 对链表进行冒泡排序
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:47
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void bubbleSort(PNODE pHeadNode)
{
	int len;//链表长度
	int i,j,temp;
	PNODE p,q;
	p = pHeadNode->pNext;
	len = length(pHeadNode);
	for (i=0, p=pHeadNode->pNext; i<len; ++i, p=p->pNext)
	{
		for (j=i+1, q=p->pNext; j<len; ++j, q=q->pNext)
		{
			if(p->value > q->value)
			{
				//交换
				temp = q->value;
				q->value = p->value;
				p->value = temp;
			}
		}
	}
	return;
}
/*****************************************************************************
    *  @brief    : insertNode 向pHeadNode指向的链表中第index前插入节点。待插入节点值为value。链表中第一个节点的索引值为1。
    *  @author   : Zhangle
    *  @date     : 2014/10/19 11:56
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool insertNode(PNODE pHeadNode, int index, int value)
{
	int i = 0;
	PNODE p = pHeadNode;
	//为新节点动态分配内存
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	PNODE q;
	while(NULL != p && i<index-1)
	{
		p = p->pNext;
		i++;
	}
	if (i>index-1 && NULL == p)
	{
		return false;
	}
// 	pNew->value = value;
// 	pNew->pNext = p->pNext;
// 	p->pNext = pNew;

	pNew->value = value;
	q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}

/*****************************************************************************
    *  @brief    : deleteNode 删除pHeadNode指向的链表的第index个节点。链表中节点从1开始计数。
    *  @author   : Zhangle
    *  @date     : 2014/10/19 12:11
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
// bool deleteNode(PNODE pHeadNode, int index)
// {
// 	int i=0;
// 	PNODE p = pHeadNode;
// 	PNODE q;
// 	while(NULL != p->pNext && i<index-1)
// 	{
// 		p = p->pNext;
// 		++i;
// 	}
// 	if (NULL == p->pNext && i>index-1)
// 	{
// 		return false;
// 	}
// 	q = p->pNext;//待删除的节点的地址
// 	p->pNext = q->pNext;
// 	free(q);
// 	q = NULL;
// }

bool deleteNode(PNODE pHeadNode, int index, int *val)
{
	int i=0;
	PNODE p = pHeadNode;
	PNODE q;
	while(NULL != p->pNext && i<index-1)
	{
		p = p->pNext;
		++i;
	}
	if (NULL == p->pNext && i>index-1)
	{
		return false;
	}
	q = p->pNext;//待删除的节点的地址
	*val = q->value;
	p->pNext = q->pNext;
	free(q);
	q = NULL;
}

/*
 * @function    : reverse 单链表反转
 * @author   	: ZhangLe
 * @date     	: 2014/11/12 21:09
 * @version  	: ver 1.0
 * @inparam  	: pHeadNode 被反转的单链表的头节点
 * @outparam    : pReverseHead 反转后单链表的头节点
 * @description : 
 */
PNODE reverse(PNODE pHeadNode)
{
	PNODE pReverseHead;
	PNODE pCurrNode;
	//PNODE pTemp;
	//动态分配内存
	pReverseHead = (PNODE)malloc(sizeof(NODE));
	pReverseHead->pNext = NULL;
	//检查内存是否分配成功
	if (NULL == pReverseHead)
	{
		printf("内存分配失败，程序退出");
		exit(-1);
	}
	pCurrNode = pHeadNode->pNext;
	//pTemp = pCurrNode;
	while (NULL != pCurrNode)//如果当前节点不为空
	{
		PNODE pTemp = pCurrNode;
 		pTemp->pNext = pReverseHead->pNext;
 		pReverseHead->pNext = pTemp;
		pCurrNode = pCurrNode->pNext;
	}
	return pReverseHead;
}
