#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef enum
{
	false,true
}bool;

//�ṹ�嶨��
typedef struct node
{
	DataType data;
	struct node *pNext;
}NODE, *PNODE;

typedef struct linkedstack
{
	PNODE top;//ջ��ָ��
}LINKEDSTACK, *PLINKEDSTACK;

//��������
//��ʼ��ջ
void initStack(PLINKEDSTACK pLinkedStack);
//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(PLINKEDSTACK pLinkedStack);
//��ջ����
void push(PLINKEDSTACK pLinkedStack, DataType data);
//��ջ����
DataType pop(PLINKEDSTACK pLinkedStack);
//����ջ
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
	printf("%c��ջ\n",pop(&linkedStack));
	printf("%c��ջ\n",pop(&linkedStack));
	traverse(&linkedStack);
	return 0;
}

/*****************************************************************************
    *  @brief    : initStack ��ʼ��ջ
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
    *  @brief    : push Ԫ����ջ
    *  @author   : Zhangle
    *  @date     : 2014/10/21 9:47
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void push(PLINKEDSTACK pLinkedStack, DataType data)
{
	//����һ���½ڵ㣬Ϊ�½ڵ㶯̬�����ڴ�
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	//�ж϶�̬�����ڴ�ʱ��ɹ�
	if (pNew == NULL)
	{
		printf("��̬�����ڴ�ʧ�ܡ�\n");
		exit(-1);
	}
	pNew->data = data;//��ֵdata�����½ڵ�
	pNew->pNext = pLinkedStack->top;//�½ڵ��ָ��pNextָ�������ͷ�ڵ�
	pLinkedStack->top = pNew;//�½ڵ��Ϊͷ�ڵ�
}
/*****************************************************************************
    *  @brief    : pop Ԫ�س�ջ
    *  @author   : Zhangle
    *  @date     : 2014/10/21 10:03
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
DataType pop(PLINKEDSTACK pLinkedStack)
{
	DataType data;
	PNODE pTop = pLinkedStack->top;//����ջ��ָ��
	//�ж�ջ�Ƿ�Ϊ��
	if (isEmpty(pLinkedStack))
	{
		printf("ջΪ�գ���ջʧ�ܣ��˳�����\n");
		exit(-1);
	}
	data = pTop->data;//��ͷ�ڵ��ֵ����data��������
	pLinkedStack->top = pTop->pNext;//ͷ�ڵ��ָ��ָ����һ���ڵ�
	free(pTop);
	pTop = NULL;
	return data;
}
/*****************************************************************************
    *  @brief    : traverse ����ջ
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
