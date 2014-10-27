//  [10/27/2014 Happy]
/************************************************************************/
/*							单向循环链表                                 */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//定义结构体
typedef struct Node {
	int data;		//节点数据
	struct Node* pNext;	//指向下一个节点的指针
} NODE, *PNODE; 

typedef enum{
	false,true
}bool;

//声明函数
//创建单向循环链表
PNODE create();
//遍历单向循环链表
void traverse(PNODE pHead);
//插入节点。向pHead指向的链表中index处插入节点。待插入节点值为value。链表中第一个节点的索引值为1。
bool insertNode(PNODE pHead, int index, int value);
//删除节点。删除pHead指向的链表中的index处的节点。
bool deleteNode(PNODE pHead, int index);
//统计循环链表中节点的个数（链表长度）
int length(PNODE pHead);
//判断单向循环链表是否为空
bool isEmpty(PNODE pHead);


int main(void)
{
	PNODE pHead = create();
	traverse(pHead);
	printf("链表的长度为 %d \n",length(pHead));
	insertNode(pHead,1,100);
	traverse(pHead);
	printf("链表的长度为 %d \n",length(pHead));
	deleteNode(pHead,2);
	traverse(pHead);
}
/*****************************************************************************
    *  @brief    : create 创建一个单向循环链表
    *  @author   : Zhangle
    *  @date     : 2014/10/27 16:26
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
PNODE create()
{
	PNODE pHead,pTail;
	int len;
	int i;
	int value;
	pHead = (PNODE)malloc(sizeof(NODE));
	pTail = pHead;
	pTail->pNext = pHead;
	//检查动态分配内存是否成功
	if (NULL == pHead)
	{
		printf("动态分配内存失败，程序退出。\n");
		exit(-1);
	}

	//输入要建立的链表的长度
	printf("请输入需要建立的链表的长度：");
	scanf("%d",&len);
	//尾插法创建链表
	for (i=0; i<len; ++i)
	{
		//为新节点动态分配内存
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		//检查为新节点动态分配内存是否成功
		if (NULL == pNew)
		{
			printf("动态内存分配失败，程序退出。\n");
			exit(-1);
		}
		//输入新节点的数据
		printf("请为新节点输入数据：");
		scanf("%d",&value);
		//将值赋给新节点
		pNew->data = value;
		//将链表的头指针指向新节点
		pTail->pNext = pNew;
		pNew->pNext = pHead;
		pTail = pNew;
	}
	return pHead;
}
/*****************************************************************************
    *  @brief    : traverse 遍历链表
    *  @author   : Zhangle
    *  @date     : 2014/10/27 16:56
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverse(PNODE pHead)
{
	PNODE pNode = pHead->pNext;
	printf("开始遍历链表：\n");
	while (pHead != pNode)
	{
		printf("%d ",pNode->data);
		pNode = pNode->pNext;
	}
	printf("\n");
}

/*****************************************************************************
    *  @brief    : length 求单向循环链表的长度即链表中节点的个数 头节点为第1个节点 
    *  @author   : Zhangle
    *  @date     : 2014/10/27 20:05
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
int length(PNODE pHead)
{
	int len = 0;
	PNODE pNode = pHead->pNext;
	while (pHead != pNode)
	{
		len ++;
		pNode = pNode->pNext;
	}
	return len;
}

/*****************************************************************************
    *  @brief    : isEmpty 判断单向循环链表是否为空
    *  @author   : Zhangle
    *  @date     : 2014/10/27 20:09
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isEmpty(PNODE pHead)
{
	if (pHead == pHead->pNext)
	{
		return true;
	}
	return false;
}
/*****************************************************************************
    *  @brief    : insertNode 在index处插入一个节点 头节点记为第1个节点
    *  @author   : Zhangle
    *  @date     : 2014/10/27 20:13
    *  @version  : ver 1.0
    *  @inparam  : pHead 指向链表的头指针
	*  @inparam  : pos 新节点的位置 新节点插入至第pos个节点处
	*  @inparam  : value 新节点的值
    *  @outparam :  
*****************************************************************************/
bool insertNode(PNODE pHead, int pos, int value)
{
	int len = length(pHead);
	if (pos == 1)
	{
		//为新节点动态分布内存
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = value;
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;
		return true;
	} 
	else if (pos > 1 && pos <= len)
	{
		PNODE pNode = pHead->pNext;
		//为新节点动态分布内存
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = value;
		pos--;
		while (1 != pos)
		{
			pNode = pNode->pNext;
			pos--;
		}
		pNew->pNext = pNode->pNext;
		pNode->pNext = pNew;
		return true;
	}
	else 
	{
		printf("新节点想插入的位置不符合规则。\n");
		exit(-1);
		return false;
	}
}
/*****************************************************************************
    *  @brief    : deleteNode 删掉指定的第index个节点
    *  @author   : Zhangle
    *  @date     : 2014/10/27 21:18
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool deleteNode(PNODE pHead, int index)
{
	//先判断链表是否为空
	if (isEmpty(pHead))
	{
		printf("链表为空，删除指定节点失败。\n");
		return false;
	} 
	//开始删除节点，节点删除时很两步。1.将该节点的前一个节点的指针直接指向后一个节点；2.释放当前删除节点的内存
	if(index >= 1 && index <= length(pHead))
	{
		if (1 == index)//删除第一个节点，即头指针指向的下一个节点（首节点）
		{
			PNODE pNode = pHead->pNext;
			pHead->pNext = pNode->pNext;
			free(pNode);
		} 
		else //
		{
			PNODE pNode = pHead->pNext;
			PNODE temp;
			index --;
			while (1 != index)
			{
				pNode = pNode->pNext;
				index --;
			}
			temp = pNode->pNext;
			pNode->pNext = temp->pNext;
			free(temp);
		}
		return true;
	}
	else
	{
		printf("输入的想删除节点的位置不符合规则。\n");
		exit(-1);
		return false;
	}
}