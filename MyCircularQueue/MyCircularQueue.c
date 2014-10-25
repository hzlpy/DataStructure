//  [10/25/2014 Happy]

//MyCircularQueue

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LENGTH 5 //队列的长度

typedef int DataType;

/************************************************************************/
/* 定义结构体                                                                     */
/************************************************************************/
typedef struct CircularQueue{
	DataType *pBase;
	int front;
	int rear;
} QUEUE, *PQUEUE;



typedef enum{
	false,true
}bool;


/************************************************************************/
/* 声明函数                                                                     */
/************************************************************************/
void init(PQUEUE pQueue);
bool enQueue(PQUEUE pQueue, DataType value);
bool outQueue(PQUEUE pQueue, DataType *value);
bool isFull(PQUEUE pQueue);
bool isEmpty(PQUEUE pQueue);
void traverse(PQUEUE pQueue);

int main(void)
{
	int data;
	QUEUE circularQueue;
	init(&circularQueue);
	enQueue(&circularQueue,0);
	enQueue(&circularQueue,1);
	enQueue(&circularQueue,2);
	enQueue(&circularQueue,3);
	enQueue(&circularQueue,4);
	traverse(&circularQueue);

	outQueue(&circularQueue,&data);
	traverse(&circularQueue);
	return 0;
}

/*****************************************************************************
    *  @brief    : init 循环队列初始化
    *  @author   : Zhangle
    *  @date     : 2014/10/25 21:23
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void init(PQUEUE pQueue)
{
	pQueue->pBase = (DataType*)malloc(sizeof(DataType) * LENGTH);//
	pQueue->front = pQueue->rear = 0;
}
/*****************************************************************************
    *  @brief    : enQueue 入队
    *  @author   : Zhangle
    *  @date     : 2014/10/25 21:29
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool enQueue(PQUEUE pQueue, int value)
{
	if (isFull(pQueue))
	{
		return false;
	} 
	else
	{
		pQueue->pBase[pQueue->rear] = value;
		pQueue->rear = pQueue->rear + 1;
		printf("%d 入队\n",value);
		return true;
	}
}
/*****************************************************************************
    *  @brief    : outQueue 出队
    *  @author   : Zhangle
    *  @date     : 2014/10/25 21:53
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool outQueue(PQUEUE pQueue, DataType *value)
{
	if (isEmpty(pQueue))
	{
		return false;
	} 
	else
	{
		*value = pQueue->pBase[pQueue->front];//把front出的值转存
		pQueue->front = (pQueue->front + 1) % LENGTH;//front加1
		printf("%d 出队\n",*value);
		return true;
	}
}

/*****************************************************************************
    *  @brief    : isFull 队列是否已满
    *  @author   : Zhangle
    *  @date     : 2014/10/25 21:29
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isFull(PQUEUE pQueue)
{
	//判断队列是否已满
	if ((pQueue->rear+1) % LENGTH == pQueue->front)
	{
		return true;
	}
	return false;
}
/*****************************************************************************
    *  @brief    : isEmpty 判断队列是否为空
    *  @author   : Zhangle
    *  @date     : 2014/10/25 21:31
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
bool isEmpty(PQUEUE pQueue)
{
	//判断队列是否为空
	if (pQueue->front == pQueue->rear)
	{
		return true;
	}
	return false;
}
/*****************************************************************************
    *  @brief    : traverse 遍历队列
    *  @author   : Zhangle
    *  @date     : 2014/10/25 21:35
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void traverse(PQUEUE pQueue)
{
	int i = pQueue->front;
	printf("遍历队列：");
	while (i != pQueue->rear)
	{
		printf("%d ",pQueue->pBase[i]);
		i = (i + 1) % LENGTH;
	}
	printf("\n");
}