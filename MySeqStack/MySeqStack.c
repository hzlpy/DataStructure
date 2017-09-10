#include <stdio.h>
#include <stdlib.h>
#define StackSize 10 //�ٶ�Ԥ�����ջ�ռ����ΪStackSize��Ԫ��
typedef char DataType;//�ٶ�ջԪ�ص���������Ϊ�ַ�
typedef enum
{
	false,true
}bool;

//�ṹ�嶨��
typedef struct SeqStack
{
	DataType data[StackSize];
	int top;
}SEQSTACK, *PSEQSTACK;

//��������
//��ʼ��ջ
void initStack(PSEQSTACK S);
//�ж�ջʱ��Ϊ��
bool isEmpty(PSEQSTACK S);
//�ж�ջ��
bool isFull(PSEQSTACK S);
//��ջ
void push(PSEQSTACK S, DataType d);
//��ջ
DataType pop(PSEQSTACK S);
//����ջ
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
    *  @brief    : initStack ��ʼ��ջ
    *  @author   : Zhangle
    *  @date     : 2014/10/21 8:53
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void initStack(PSEQSTACK S)
{
	S->top = 0; //Լ��topΪ0ʱ��ջ����Ԫ�أ���Ϊ��
}
/*****************************************************************************
    *  @brief    : isEmpty �ж�ջ�Ƿ�Ϊ��
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
    *  @brief    : isFull �ж�ջ�Ƿ�����
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
    *  @brief    : push ��ջ
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:01
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void push(PSEQSTACK S, DataType d)
{
	//��ջ֮ǰ���ж�ջ�Ƿ�����
	if (isFull(S)) //ջ��
	{
		printf("ջ��������ջʧ�ܡ�\n");
		exit(-1);
	}
	S->top ++; //ջ��ָ���1
	S->data[S->top] = d; //d��ջ
}
/*****************************************************************************
    *  @brief    : pop ��ջ
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:02
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
DataType pop(PSEQSTACK S)
{
	DataType data;
	//��ջǰ���ж�ջ�Ƿ�Ϊ��
	if (isEmpty(S))
	{
		printf("ջ�գ��޷���ջ��\n");
		exit(-1);
	}
	data = S->data[S->top];//��ջ
	S->top--; //ͷָ���1
}
/*****************************************************************************
    *  @brief    : traverse ����ջ
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:10
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverse(PSEQSTACK S)
{
	int i = 0;
	//ջ���Ƚ���������ȴ�ջ�����
	for (i=S->top; i>0; --i)
	{
		printf("%c ",S->data[i]);
	}
	printf("\n");
}