#include <stdio.h>
#include <stdlib.h>

typedef enum _bool
{
	false = 0,
	true = 1
}bool;

// 定义结构体
typedef struct Array
{
	int * pBase;
	int length;
	int count;		// 有效元素的个数
}*PARRAY, ARRAY;

// 声明函数
void init(PARRAY, int length);
void print(PARRAY pArray);
void append(PARRAY pArray, int value);
void insert(PARRAY pArray, int index, int value);//position指定待插入元素的索引，元素插入成功后，index对应的元素以后的元素依此后移一位
int length(PARRAY pArray);
bool isEmpty(PARRAY pArray);
bool isFull(PARRAY pArray);
int MyLength(PARRAY pArray);
int MyCount(PARRAY pArray);

int main(void)
{
	ARRAY pArr;
	int len = 10;
	init(&pArr,len);
	print(&pArr);
	append(&pArr,1);
	append(&pArr,2);
	append(&pArr,3);
	append(&pArr,5);
	append(&pArr,6);
	insert(&pArr,3,4);
	append(&pArr,7);
	append(&pArr,8);
	append(&pArr,9);
	append(&pArr,10);
	append(&pArr,11);
	print(&pArr);
	append(&pArr,7);
	append(&pArr,8);
	append(&pArr,9);
	append(&pArr,10);
	append(&pArr,11);
	append(&pArr,7);
	append(&pArr,8);
	append(&pArr,9);
	append(&pArr,10);
	append(&pArr,11);
	MyLength(&pArr);
	MyCount(&pArr);
	print(&pArr);
}
/*****************************************************************************
    *  @brief    : init 初始化数组
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void init(PARRAY pArray, int length)
{
	//动态分配内存
	pArray->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArray->pBase)
	{
		printf("动态分配内存失败..\n");
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
    *  @brief    : isEmpty 判断数组时候为空
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isEmpty(PARRAY pArray)
{
	if (pArray->count == 0)		// 数组中有效元素个数为 0，数组为空，返回 true
	{
		return true;
	} 
	else
	{
		return false;
	}
}
/*****************************************************************************
    *  @brief    : isFull 判断数组是否已满
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isFull(PARRAY pArray)
{
	//判断count与length的大小
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
    *  @brief    : print 打印数组
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void print(PARRAY pArray)
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
    *  @brief    : append 为数组追加元素
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:16
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void append(PARRAY pArray, int value)
{
	//追加元素前先判断count与length的大小
	if (isFull(pArray))
	{
		//数组已满，请为它分配新的内存
		int length = pArray->length;
		int newLength = 2 * length;

		int* pBaseStart = pArray->pBase;
		int *tmpArray = (int *)malloc(sizeof(int) * length);
		int* tmpStart = tmpArray;
		if (NULL == tmpArray)
		{
			printf("申请内存失败。\n");
			exit(-1);
		}
		int i=0;
		for(i=0; i<length; i++) {
			*tmpArray = *(pArray->pBase);
			tmpArray ++;
			(pArray->pBase) ++;
		}
		pArray->pBase = pBaseStart;
		tmpArray = tmpStart;
		free(pArray->pBase);
		pArray->pBase = NULL;
		pArray->pBase = (int*)malloc(sizeof(int) * newLength);
		pArray->length = newLength;
		pBaseStart = pArray->pBase;
		if (NULL == pArray->pBase)
		{
			printf("申请内存失败。\n");
			exit(-1);
		}
		for (i=0; i<length; i++) {
			*(pArray->pBase) = *tmpArray;
			pArray->pBase ++;
			tmpArray ++;
		}
		pArray->pBase = pBaseStart;
		tmpArray = tmpStart;
		free(tmpArray);
		tmpArray = NULL;
	} 
	pArray->pBase[pArray->count] = value;
	pArray->count ++;
}

/*****************************************************************************
    *  @brief    : insert
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:16
    *  @version  : ver 1.0
    *  @inparam  : pArray
	*  @inparam  : index 指定待插入元素的索引，元素插入成功后，index对应元素后的元素依次后移一位
	*  @inparam  : value 待插入的值
    *  @outparam :  
*****************************************************************************/
void insert(PARRAY pArray, int index, int value)
{
	int i = 0;
	//插入元素前先判断count与length的大小
	if (isFull(pArray))
	{
		printf("insert error. \n");
	} 
	else
	{
		// 先将index对应元素后的元素依次后移 1 位
		for (i=pArray->length-1; i>index; i--)
		{
			pArray->pBase[i] = pArray->pBase[i-1];
		}
		// 在index处插入元素
		pArray->pBase[index] = value;
		// 插入后 count 加 1
		pArray->count++;
	}
}

int MyCount(PARRAY pArray)
{
	if (NULL == pArray)
	{
		return -1;
	}
	printf("count = %d \n", pArray->count);
	return pArray->count;
}

int MyLength(PARRAY pArray)
{
	if (NULL == pArray)
	{
		return -1;
	}
	printf("length = %d \n", pArray->length);
	return pArray->length;
}