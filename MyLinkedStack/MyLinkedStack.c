#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef enum
{
	false,true
}bool;

//结构体定义
typedef struct node
{
	DataType data;
	struct node *pNext;
}NODE, *PNODE;

typedef struct linkedstack
{
	PNODE top;		//栈顶指针
}LINKEDSTACK, *PLINKEDSTACK;

// 函数声明
// 初始化栈
void initStack(PLINKEDSTACK pLinkedStack);
// 判断栈是否为空
bool isEmpty(PLINKEDSTACK pLinkedStack);
// 入栈操作
void push(PLINKEDSTACK pLinkedStack, DataType data);
// 出栈操作
DataType pop(PLINKEDSTACK pLinkedStack);
// 遍历栈
void traverse(PLINKEDSTACK pLinkedStack);

int main(void)
{
	LINKEDSTACK linkedStack;
	initStack(&linkedStack);
	push(&linkedStack,'a');
	push(&linkedStack,'b');
	push(&linkedStack,'c');
	push(&linkedStack,'d');
	push(&linkedStack,'e');
	push(&linkedStack,'f');
	push(&linkedStack,'g');
	traverse(&linkedStack);
	printf("%c 出栈\n",pop(&linkedStack));
	printf("%c 出栈\n",pop(&linkedStack));
	traverse(&linkedStack);
	return 0;
}

/*****************************************************************************
    *  @brief    : initStack 初始化栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:42
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void initStack(PLINKEDSTACK pLinkedStack)
{
	pLinkedStack->top = NULL;
}

bool isEmpty(PLINKEDSTACK pLinkedStack)
{
	return pLinkedStack->top == NULL;
}

/*****************************************************************************
    *  @brief    : push 元素入栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:47
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void push(PLINKEDSTACK pLinkedStack, DataType data)
{
	//申请一个新节点，为新节点动态分配内存
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	//判断动态分配内存时候成功
	if (pNew == NULL)
	{
		printf("动态分配内存失败。\n");
		exit(-1);
	}
	pNew->data = data;					// 将值 data 赋给新节点
	pNew->pNext = pLinkedStack->top;	// 新节点的指针 pNext 指向链表的头节点
	pLinkedStack->top = pNew;			// 新节点变为头节点
}
/*****************************************************************************
    *  @brief    : pop 元素出栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 10:03
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
DataType pop(PLINKEDSTACK pLinkedStack)
{
	DataType data;
	PNODE pTop = pLinkedStack->top;		// 保存栈顶指针
	// 判断栈是否为空
	if (isEmpty(pLinkedStack))
	{
		printf("栈为空，出栈失败，退出程序。\n");
		exit(-1);
	}
	data = pTop->data;					// 将头节点的值赋给 data，并返回
	pLinkedStack->top = pTop->pNext;	// 头节点的指针指向下一个节点
	free(pTop);
	pTop = NULL;
	return data;
}
/*****************************************************************************
    *  @brief    : traverse 遍历栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 10:12
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverse(PLINKEDSTACK pLinkedStack)
{
	PNODE pTop = pLinkedStack->top;
	while (pTop != NULL)
	{
		printf("%c ",pTop->data);
		pTop = pTop->pNext;
	}
	printf("\n");
}