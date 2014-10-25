//  [10/13/2014 Happy]

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef enum _bool
{
	false = 0,
	true = 1
}bool;

//����ṹ��
struct Array
{
	int * pBase;
	int length;
	int count;//��ЧԪ�صĸ���
};

//��������
void init(struct Array *pArray, int length);
void print(struct Array *pArray);
void append(struct Array *pArray, int value);
void insert(struct Array *pArray, int index, int value);//positionָ��������Ԫ�ص�������Ԫ�ز���ɹ���index��Ӧ��Ԫ���Ժ��Ԫ�����˺���һλ
int length();
bool isEmpty(struct Array *pArray);
bool isFull(struct Array *pArray);
int main(void)
{
	struct Array pArr;
	int len = 10;
	init(&pArr,len);
	print(&pArr);
	append(&pArr,1);
	append(&pArr,2);
	append(&pArr,3);
	append(&pArr,5);
	append(&pArr,6);
	insert(&pArr,3,4);
	print(&pArr);
}
/*****************************************************************************
    *  @brief    : init ��ʼ������
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void init(struct Array *pArray, int length)
{
	//��̬�����ڴ�
	pArray->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == pArray->pBase)
	{
		printf("��̬�����ڴ�ʧ��..\n");
		exit(-1);
	} 
	else
	{
		pArray->length = length;
		pArray->count = 0;
	}
	return;
}
/*****************************************************************************
    *  @brief    : isEmpty �ж�����ʱ��Ϊ��
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isEmpty(struct Array *pArray)
{
	if (pArray->count == 0)//��������ЧԪ�ظ���Ϊ0������Ϊ�գ�����true
	{
		return true;
	} 
	else
	{
		return false;
	}
}
/*****************************************************************************
    *  @brief    : isFull �ж������Ƿ�����
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isFull(struct Array *pArray)
{
	//�ж�count��length�Ĵ�С
	if (pArray->count >= pArray->length)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*****************************************************************************
    *  @brief    : print ��ӡ����
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void print(struct Array *pArray)
{
	if (isEmpty(pArray))
	{
		printf("The array is null.\n");
	} 
	else
	{
		int i=0;
		for (i=0; i<pArray->count; i++)
		{
			printf("%d ",pArray->pBase[i]);
		}
		printf("\n");
	}
}

/*****************************************************************************
    *  @brief    : append Ϊ����׷��Ԫ��
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:16
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void append(struct Array *pArray, int value)
{
	//׷��Ԫ��ǰ���ж�count��length�Ĵ�С
	if (isFull(pArray))
	{
		//������������Ϊ�������µ��ڴ�
	} 
	else //׷��Ԫ��
	{
		pArray->pBase[pArray->count] = value;
		pArray->count ++;
	}
}

/*****************************************************************************
    *  @brief    : insert
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:16
    *  @version  : ver 1.0
    *  @inparam  : pArray
	*  @inparam  : index ָ��������Ԫ�ص�������Ԫ�ز���ɹ���index��ӦԪ�غ��Ԫ�����κ���һλ
	*  @inparam  : value �������ֵ
    *  @outparam :  
*****************************************************************************/
void insert(struct Array *pArray, int index, int value)
{
	int i = 0;
	//����Ԫ��ǰ���ж�count��length�Ĵ�С
	if (isFull(pArray))
	{
		printf("insert error. \n");
	} 
	else
	{
		//�Ƚ�index��ӦԪ�غ��Ԫ�����κ���һλ
		for (i=pArray->length-1; i>index; i--)
		{
			pArray->pBase[i] = pArray->pBase[i-1];
		}
		//��index������Ԫ��
		pArray->pBase[index] = value;
		//�����count��1
		pArray->count++;
	}
}