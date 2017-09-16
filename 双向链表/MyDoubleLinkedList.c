#include <stdio.h>
#include <stdlib.h>

// 定义双向链表结构
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}LinkedList, *PLinkedList, *PNODE, NODE;

/*
 * @function    : create
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:45
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 创建一个双向链表
 */
PLinkedList create()
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead) {
		exit(-1);
	}
	PNODE pRear = pHead;
	pRear->next = NULL;
	//要添加 count 个结点
	int count = 0;
	int i, value;
	printf("请输入要求添加的结点的个数: ");
	scanf("%d", &count);
	for (i=1; i <= count; i++) {
		//添加新结点
		//为新结点申请内存
		PNODE newNode = (PNODE)malloc(sizeof(NODE));
		printf("为第 %d 个新结点赋值: ",i);
		scanf("%d", &value);
		newNode->data = value;
		pRear->next = newNode;
		newNode->prev = pRear;
		pRear = newNode;
		pRear->next = NULL;
	}
	return pHead;
}

/*
 * @function    : traverse
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:45
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 遍历链表
 */
void traverse(PLinkedList pHead)
{
	if (NULL == pHead) {
		return;
	}
	PNODE temp = pHead;
	while (NULL != temp->next) {
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");
}

/*
 * @function    : reverseTra
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:50
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 从尾部结点开始遍历
 */
void reverseTra(PLinkedList pHead)
{
	if (NULL == pHead) {
		return;
	}
	PNODE rear, first, temp;
	temp = rear = pHead;

	// 先找到尾部结点
	while (NULL != temp->next) {
		temp= temp->next;
		rear = rear->next;
	}
	while (pHead != rear) {
		printf("%d ", rear->data);
		rear = rear->prev;
	}
	printf("\n");
}

int main()
{
	PLinkedList list = create();
	traverse(list);
	reverseTra(list);
	return 0;
}
