#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct node
{
	struct node *pNext;//ָ����
	int value;//������
}NODE, *PNODE;

typedef enum _bool
{
	false,true
}bool;

//��������
/*��������*/
PNODE createLinkedList();
/*��������*/
void traverseLinkedList(PNODE pHeadNode);
// /*ɾ���ڵ�*/
// bool deleteNode(PNODE pHeadNode, int index);
/*ɾ���ڵ�*/
bool deleteNode(PNODE pHeadNode, int index, int *value);
/*���ӽڵ�*/
bool insertNode(PNODE pHeadNode, int index, int value);
/*�ж�����ʱ��Ϊ��*/
bool isEmpty(PNODE pHeadNode);
/*��������*/
int length(PNODE pHeadNode);
/*ð������*/
void bubbleSort(PNODE pHeadNode);
int main(void)
{
	int d_value;
	//��������
	PNODE pHeadNode = createLinkedList();
// 	//�ж�����ʱ��Ϊ��
// 	if (isEmpty(pHeadNode))
// 	{
// 		printf("����Ϊ�ա�\n");
// 	}
// 	else
// 	{
// 		printf("������Ϊ�ա�\n");
// 	}
// 	//�����ĳ���
// 	printf("��������Ϊ %d \n",length(pHeadNode));
	//��������
	traverseLinkedList(pHeadNode);

//  	//����
// 	bubbleSort(pHeadNode);
// 	traverseLinkedList(pHeadNode);

	//���ӽڵ�
	insertNode(pHeadNode,4,100);
	traverseLinkedList(pHeadNode);
	//ɾ���ڵ�

	deleteNode(pHeadNode,4,&d_value);
	traverseLinkedList(pHeadNode);
	printf("��ɾ���������� %d \n",d_value);
}

/*****************************************************************************
    *  @brief    : createLinkedList ����������
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:10
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
PNODE createLinkedList()
{
	int i;
	int length;
	int value;
	//Ϊͷ�ڵ������ڴ�ռ�
	PNODE pHeadNode = (PNODE)malloc(sizeof(NODE));
	//β�ڵ�
	PNODE pTailNode = pHeadNode;
	pTailNode->pNext = NULL;
	//�ж��ڴ������Ƿ�ɹ�
	if (NULL == pHeadNode)
	{
		printf("�ڴ�����ʧ�ܣ��˳�����\n");
		exit(-1);
	}

	//���������ĳ��ȣ����ڵ�ĸ���
	printf("����������ĳ���: ");
	scanf("%d",&length);
	//����ѭ�����ӽڵ�
	for (i=0; i<length; ++i)
	{
		//����һ���µĽڵ�
		PNODE pNewNode = (PNODE)malloc(sizeof(NODE));
		//�ж��ڴ������Ƿ�ɹ�
		if (NULL == pNewNode)
		{
			printf("�ڴ�����ʧ�ܣ��˳�����\n");
			exit(-1);
		}
		printf("�������%d���ڵ��ֵ = ",i+1);
		scanf("%d",&value);
		pNewNode->value = value;
		pTailNode->pNext = pNewNode;
		pNewNode->pNext = NULL;
		pTailNode = pNewNode;
	}
	return pHeadNode;
}
/*****************************************************************************
    *  @brief    : traverseLinkedList ����������
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:19
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverseLinkedList(PNODE pHeadNode)
{
	PNODE p = pHeadNode->pNext;
	printf("��ʼ��������\n");
	while(NULL != p)
	{
		printf("%d ",p->value);
		p = p->pNext;
	}
	printf("\n");
}
/*****************************************************************************
    *  @brief    : isEmpty �ж�����ʱ��Ϊ��
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
    *  @brief    : length ��ȡ��������
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
    *  @brief    : bubbleSort ����������ð������
    *  @author   : Zhangle
    *  @date     : 2014/10/19 10:47
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void bubbleSort(PNODE pHeadNode)
{
	int len;//��������
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
				//����
				temp = q->value;
				q->value = p->value;
				p->value = temp;
			}
		}
	}
	return;
}
/*****************************************************************************
    *  @brief    : insertNode ��pHeadNodeָ��������е�indexǰ����ڵ㡣������ڵ�ֵΪvalue�������е�һ���ڵ������ֵΪ1��
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
	//Ϊ�½ڵ㶯̬�����ڴ�
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
    *  @brief    : deleteNode ɾ��pHeadNodeָ��������ĵ�index���ڵ㡣�����нڵ��1��ʼ������
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
// 	q = p->pNext;//��ɾ���Ľڵ�ĵ�ַ
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
	q = p->pNext;//��ɾ���Ľڵ�ĵ�ַ
	*val = q->value;
	p->pNext = q->pNext;
	free(q);
	q = NULL;
}