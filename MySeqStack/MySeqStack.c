#include <stdio.h>
#include <stdlib.h>
#define StackSize 10 //假定预分配的栈空间最多为StackSize个元素
typedef char DataType;//假定栈元素的数据类型为字符
typedef enum
{
	false,true
}bool;

//结构体定义
typedef struct SeqStack
{
	DataType data[StackSize];
	int top;
}SEQSTACK, *PSEQSTACK;

//函数声明
//初始化栈
void initStack(PSEQSTACK S);
//判断栈时候为空
bool isEmpty(PSEQSTACK S);
//判断栈满
bool isFull(PSEQSTACK S);
//入栈
void push(PSEQSTACK S, DataType d);
//出栈
DataType pop(PSEQSTACK S);
//遍历栈
void traverse(PSEQSTACK S);

int main(void)
{
	SEQSTACK S;
	initStack(&S);
	push(&S,'A');
	push(&S,'B');
	push(&S,'C');
	push(&S,'D');
	push(&S,'E');
	push(&S,'F');
	push(&S,'G');
	push(&S,'H');
	push(&S,'I');
	push(&S,'J');
	traverse(&S);
	pop(&S);
	pop(&S);
	pop(&S);
	traverse(&S);
}
/*****************************************************************************
    *  @brief    : initStack 初始化栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 8:53
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void initStack(PSEQSTACK S)
{
	S->top = 0; //约定top为0时，栈中无元素，即为空
}
/*****************************************************************************
    *  @brief    : isEmpty 判断栈是否为空
    *  @author   : Zhangle
    *  @date     : 2014/10/21 8:54
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isEmpty(PSEQSTACK S)
{
	return S->top == 0;
}
/*****************************************************************************
    *  @brief    : isFull 判断栈是否已满
    *  @author   : Zhangle
    *  @date     : 2014/10/21 8:55
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isFull(PSEQSTACK S)
{
	return S->top == StackSize;
}

/*****************************************************************************
    *  @brief    : push 入栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:01
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void push(PSEQSTACK S, DataType d)
{
	//进栈之前先判断栈是否已满
	if (isFull(S)) 			// 栈满
	{
		printf("栈已满，入栈失败。\n");
		exit(-1);
	}
	S->top ++; 				// 栈顶指针加 1
	S->data[S->top] = d; 	// d 入栈
}
/*****************************************************************************
    *  @brief    : pop 出栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:02
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
DataType pop(PSEQSTACK S)
{
	DataType data;
	//出栈前先判断栈是否为空
	if (isEmpty(S))
	{
		printf("栈空，无法出栈。\n");
		exit(-1);
	}
	data = S->data[S->top];		// 出栈
	S->top--; 					// 头指针减 1
	return data;
}
/*****************************************************************************
    *  @brief    : traverse 遍历栈
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:10
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverse(PSEQSTACK S)
{
	int i = 0;
	//栈是先进后出，故先从栈顶输出
	for (i=S->top; i>0; --i)
	{
		printf("%c ",S->data[i]);
	}
	printf("\n");
}