#include <stdio.h>
#include <malloc.h>
typedef struct BTNode
{
	char data;
	struct BTNode *pLeftChild;
	struct BTNode *pRightChild;
}BTNODE, *PBTNODE;
/*��������*/
//����һ����ʽ������
PBTNODE createLinkedBinaryTree();
//�������������
void preTraverseBinaryTree(PBTNODE pRoot);
//�������
void inTraverseBinaryTree(PBTNODE pRoot);
//�������
void postTraverseBinaryTree(PBTNODE pRoot);

/*****************************************************************************
    *  @function    : main
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:53
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
int main(void)
{
	PBTNODE pTree = createLinkedBinaryTree();
	preTraverseBinaryTree(pTree);
	inTraverseBinaryTree(pTree);
	postTraverseBinaryTree(pTree);
	return 0;
}

/*****************************************************************************
    *  @function    : createLinkedBinaryTree ����һ����ʽ������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:53
    *  @version  	: ver 1.0
    *  @inparam  	: void
    *  @outparam 	: pRoot ���ĸ��ڵ��ַ
	*  @description :
*****************************************************************************/
PBTNODE createLinkedBinaryTree()
{
	//�����ڴ�
	PBTNODE pA = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pB = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pC = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pD = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pE = (PBTNODE)malloc(sizeof(BTNODE));
	//��ֵ
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	//����
	pA->pLeftChild = pB;
	pA->pRightChild = pC;
	pB->pLeftChild = pB->pRightChild = NULL;
	pC->pLeftChild = pD;
	pC->pRightChild = NULL;
	pD->pLeftChild = NULL;
	pD->pRightChild = pE;
	pE->pLeftChild = pE->pRightChild = NULL;
	return pA;
}
/*****************************************************************************
    *  @function    : preTraverseBinaryTree �������������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:51
    *  @version  	: ver 1.0
    *  @inparam  	: pRoot ���ĸ��ڵ��ַ
    *  @outparam 	: void
	*  @description : �ȷ��ʸ��ڵ㣬������������������ٺ������������
*****************************************************************************/
void preTraverseBinaryTree(PBTNODE pRoot)
{
	if (NULL != pRoot)
	{
		//��ӡ���ڵ�
		printf("%c \n",pRoot->data);
		if (NULL != pRoot->pLeftChild)
		{
			preTraverseBinaryTree(pRoot->pLeftChild);
		}
		if (NULL != pRoot->pRightChild)
		{
			preTraverseBinaryTree(pRoot->pRightChild);
		}
	}
}

/*****************************************************************************
    *  @function    : inTraverseBinaryTree �������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/8 20:13
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
void inTraverseBinaryTree(PBTNODE pRoot)
{
	if (NULL != pRoot)
	{
		if (NULL != pRoot->pLeftChild)
		{
			inTraverseBinaryTree(pRoot->pLeftChild);
		}
		//��ӡ���ڵ�
		printf("%c \n",pRoot->data);
		if (NULL != pRoot->pRightChild)
		{
			inTraverseBinaryTree(pRoot->pRightChild);
		}
	}
}

/*****************************************************************************
    *  @function    : postTraverseBinaryTree �������������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:57
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
void postTraverseBinaryTree(PBTNODE pRoot)
{
	if (NULL != pRoot)
	{
		if (NULL != pRoot->pLeftChild)
		{
			postTraverseBinaryTree(pRoot->pLeftChild);
		}
		if (NULL != pRoot->pRightChild)
		{
			postTraverseBinaryTree(pRoot->pRightChild);
		}
		//��ӡ���ڵ�
		printf("%c \n",pRoot->data);
	}
}