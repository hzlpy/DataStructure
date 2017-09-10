//  [10/27/2014 Happy]
/************************************************************************/
/*							����ѭ������                                 */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//����ṹ��
typedef struct Node {
	int data;		//�ڵ�����
	struct Node* pNext;	//ָ����һ���ڵ��ָ��
} NODE, *PNODE; 

typedef enum{
	false,true
}bool;

//��������
//��������ѭ������
PNODE create();
//��������ѭ������
void traverse(PNODE pHead);
//����ڵ㡣��pHeadָ���������index������ڵ㡣������ڵ�ֵΪvalue�������е�һ���ڵ������ֵΪ1��
bool insertNode(PNODE pHead, int index, int value);
//ɾ���ڵ㡣ɾ��pHeadָ��������е�index���Ľڵ㡣
bool deleteNode(PNODE pHead, int index);
//ͳ��ѭ�������нڵ�ĸ����������ȣ�
int length(PNODE pHead);
//�жϵ���ѭ�������Ƿ�Ϊ��
bool isEmpty(PNODE pHead);


int main(void)
{
	PNODE pHead = create();
	traverse(pHead);
	printf("����ĳ���Ϊ %d \n",length(pHead));
	insertNode(pHead,1,100);
	traverse(pHead);
	printf("����ĳ���Ϊ %d \n",length(pHead));
	deleteNode(pHead,2);
	traverse(pHead);
}
/*****************************************************************************
    *  @brief    : create ����һ������ѭ������
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
	//��鶯̬�����ڴ��Ƿ�ɹ�
	if (NULL == pHead)
	{
		printf("��̬�����ڴ�ʧ�ܣ������˳���\n");
		exit(-1);
	}

	//����Ҫ����������ĳ���
	printf("��������Ҫ����������ĳ��ȣ�");
	scanf("%d",&len);
	//β�巨��������
	for (i=0; i<len; ++i)
	{
		//Ϊ�½ڵ㶯̬�����ڴ�
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		//���Ϊ�½ڵ㶯̬�����ڴ��Ƿ�ɹ�
		if (NULL == pNew)
		{
			printf("��̬�ڴ����ʧ�ܣ������˳���\n");
			exit(-1);
		}
		//�����½ڵ������
		printf("��Ϊ�½ڵ��������ݣ�");
		scanf("%d",&value);
		//��ֵ�����½ڵ�
		pNew->data = value;
		//�������ͷָ��ָ���½ڵ�
		pTail->pNext = pNew;
		pNew->pNext = pHead;
		pTail = pNew;
	}
	return pHead;
}
/*****************************************************************************
    *  @brief    : traverse ��������
    *  @author   : Zhangle
    *  @date     : 2014/10/27 16:56
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverse(PNODE pHead)
{
	PNODE pNode = pHead->pNext;
	printf("��ʼ��������\n");
	while (pHead != pNode)
	{
		printf("%d ",pNode->data);
		pNode = pNode->pNext;
	}
	printf("\n");
}

/*****************************************************************************
    *  @brief    : length ����ѭ������ĳ��ȼ������нڵ�ĸ��� ͷ�ڵ�Ϊ��1���ڵ� 
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
    *  @brief    : isEmpty �жϵ���ѭ�������Ƿ�Ϊ��
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
    *  @brief    : insertNode ��index������һ���ڵ� ͷ�ڵ��Ϊ��1���ڵ�
    *  @author   : Zhangle
    *  @date     : 2014/10/27 20:13
    *  @version  : ver 1.0
    *  @inparam  : pHead ָ�������ͷָ��
	*  @inparam  : pos �½ڵ��λ�� �½ڵ��������pos���ڵ㴦
	*  @inparam  : value �½ڵ��ֵ
    *  @outparam :  
*****************************************************************************/
bool insertNode(PNODE pHead, int pos, int value)
{
	int len = length(pHead);
	if (pos == 1)
	{
		//Ϊ�½ڵ㶯̬�ֲ��ڴ�
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = value;
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;
		return true;
	} 
	else if (pos > 1 && pos <= len)
	{
		PNODE pNode = pHead->pNext;
		//Ϊ�½ڵ㶯̬�ֲ��ڴ�
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
		printf("�½ڵ�������λ�ò����Ϲ���\n");
		exit(-1);
		return false;
	}
}
/*****************************************************************************
    *  @brief    : deleteNode ɾ��ָ���ĵ�index���ڵ�
    *  @author   : Zhangle
    *  @date     : 2014/10/27 21:18
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool deleteNode(PNODE pHead, int index)
{
	//���ж������Ƿ�Ϊ��
	if (isEmpty(pHead))
	{
		printf("����Ϊ�գ�ɾ��ָ���ڵ�ʧ�ܡ�\n");
		return false;
	} 
	//��ʼɾ���ڵ㣬�ڵ�ɾ��ʱ��������1.���ýڵ��ǰһ���ڵ��ָ��ֱ��ָ���һ���ڵ㣻2.�ͷŵ�ǰɾ���ڵ���ڴ�
	if(index >= 1 && index <= length(pHead))
	{
		if (1 == index)//ɾ����һ���ڵ㣬��ͷָ��ָ�����һ���ڵ㣨�׽ڵ㣩
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
		printf("�������ɾ���ڵ��λ�ò����Ϲ���\n");
		exit(-1);
		return false;
	}
}