#include <stdio.h>
#include <stdlib.h>

typedef enum _bool
{
	false = 0,
	true = 1
}bool;

// 定义结构体
struct Array
{
	int * pBase;
	int length;
	int count;		// 有效元素的个数
};

// 声明函数
void init(struct Array *pArray, int length);
void print(struct Array *pArray);
void append(struct Array *pArray, int value);
void insert(struct Array *pArray, int index, int value);//position指定待插入元素的索引，元素插入成功后，index对应的元素以后的元素依此后移一位
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
    *  @brief    : init 初始化数组
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:15
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void init(struct Array *pArray, int length)
{
	//动态分配内存
	pArray->pBase = (int *)malloc(sizeof(int)*length);
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
bool isEmpty(struct Array *pArray)
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
bool isFull(struct Array *pArray)
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
    *  @brief    : append 为数组追加元素
    *  @author   : Zhangle
    *  @date     : 2014/10/18 16:16
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void append(struct Array *pArray, int value)
{
	//追加元素前先判断count与length的大小
	if (isFull(pArray))
	{
		//数组已满，请为它分配新的内存
	} 
	else //追加元素
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
	*  @inparam  : index 指定待插入元素的索引，元素插入成功后，index对应元素后的元素依次后移一位
	*  @inparam  : value 待插入的值
    *  @outparam :  
*****************************************************************************/
void insert(struct Array *pArray, int index, int value)
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