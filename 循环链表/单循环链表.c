#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}LinkList, *PNODE, NODE;

PNODE rear = NULL;

/*
 * @function    : create
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:19
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 创建一个单循环链表，返回链表的头结点
 */
LinkList *create()
{
	PNODE head = (PNODE)malloc(sizeof(NODE));
	PNODE curr;
	if (NULL == head) {
		exit(-1);
	}
	int value = 0;
	rear = head;//
	head->next = rear;
	rear->next = head;
	scanf("%d", &value);
	while (value != -1) {
		curr = (PNODE)malloc(sizeof(NODE));
		if (NULL == curr) {
			exit(-1);
		}
		curr->data = value;
		rear->next = curr;
		curr->next = head;
		rear = curr;
		scanf("%d", &value);
	}
	return head;
}

/*
 * @function    : getRearHead
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:18
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 输出单循环链表的最后结点和开始结点（非头结点）
 */
void getRearHead(NODE *p)
{
	printf("%d\n", p->data);				//最后结点
	printf("%d\n", p->next->next->data);	//开始结点
}

/*
 * @function    : traverse
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:18
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 遍历单循环链表
 */
void traverse(LinkList *pHead)
{
	if (pHead == NULL) {
		return;
	}
	PNODE cur = pHead->next;
	while (cur != pHead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
/*
 * @function    : length
 * @author   	: ZhangLe
 * @date     	: 2015/8/25 10:13
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 求循环链表中结点的个数，不包含头结点
 */
int size(LinkList *pHead)
{
	if (NULL == pHead) {
		return 0;
	}
	int count = 0;
	PNODE first = pHead->next;
	if (NULL == first) {
		return 0;
	}
	while (pHead != first) {
		count ++;
		first = first->next;
	}
	return count;
}

int main()
{
	rear = (PNODE)malloc(sizeof(NODE));
	LinkList *pHead = create();
	getRearHead(rear);
	traverse(pHead);
	printf("size = %d", size(pHead));
	return 0;
}
