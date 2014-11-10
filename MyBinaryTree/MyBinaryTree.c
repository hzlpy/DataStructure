#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BTNode
{
	char data;
	struct BTNode *pLeftChild;
	struct BTNode *pRightChild;
}BTNODE, *PBTNODE;
/*��������*/
//����һ���򵥵ض�����
PBTNODE createSimpleBinaryTree();
//����һ��������
PBTNODE createBinaryTree();
//�������������
void preTraverseBinaryTree(PBTNODE pRoot);
//�������
void inTraverseBinaryTree(PBTNODE pRoot);
//�������
void postTraverseBinaryTree(PBTNODE pRoot);
//�������
void levelTraverseBinaryTree(PBTNODE pRoot);
//��������нڵ�ĸ���
int getNodeNum(PBTNODE pRoot);
//������������
int getDepth(PBTNODE pRoot);
//��������е�k��ڵ�ĸ���
int getKthLevelNodeNum(PBTNODE pRoot, int k);
//���������Ҷ�ӽڵ�ĸ���
int getLeafNodeNum(PBTNODE pRoot);
/*****************************************************************************
    *  @function	: main
    *  @author		: ZhangLe
    *  @date		: 2014/11/7 21:53
    *  @version		: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
int main(void)
{
	//PBTNODE pTree = createSimpleBinaryTree();
	PBTNODE pTree;
	printf("Please input values for tree node..\n");
	pTree = createBinaryTree();
	printf("preTraverseBinaryTree�� \n"); 
	preTraverseBinaryTree(pTree);
	printf("\n");
	printf("inTraverseBinaryTree�� \n");
	inTraverseBinaryTree(pTree);
	printf("\n");
	printf("postTraverseBinaryTree�� \n");
	postTraverseBinaryTree(pTree);
	printf("\n");
	printf("The number of nodes in binary tree is %d.\n",getNodeNum(pTree));
	printf("The depth of binary tree is %d.\n",getDepth(pTree));
	printf("The nodes' number of the kth level is %d.\n",getKthLevelNodeNum(pTree,3));
	printf("The leaf nodes' number is %d.\n",getLeafNodeNum(pTree));
	return 0;
}

/*****************************************************************************
    *  @function	: createSimpleBinaryTree ����һ����ʽ������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:53
    *  @version  	: ver 1.0
    *  @inparam  	: void
    *  @outparam 	: pRoot ���ĸ��ڵ��ַ
	*  @description :
*****************************************************************************/
PBTNODE createSimpleBinaryTree()
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
    *  @function    : createBinaryTree ����������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/9 19:52
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
PBTNODE createBinaryTree()
{
	char value;
	PBTNODE pRoot;
	scanf("%c",&value);
	if ((value == '#') || (value == '\n'))
	{
		pRoot = NULL;
	} 
	else
	{
		pRoot = (PBTNODE)malloc(sizeof(BTNODE));
		if (NULL == pRoot)
		{
			printf("�ڴ����ʧ�ܣ������˳�..");
			exit(-1);
		}
		pRoot->data = value;
		pRoot->pLeftChild = createBinaryTree();
		pRoot->pRightChild = createBinaryTree();
	}
	return pRoot;
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
		printf("%c ",pRoot->data);
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
		printf("%c ",pRoot->data);
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
		printf("%c ",pRoot->data);
	}
}

void levelTraverseBinaryTree(PBTNODE pRoot)
{
// 	if (NULL == pRoot)
// 	{
// 		return;
// 	}
// 	queue<PBTNODE> q;
}

/*****************************************************************************
    *  @function    : getNodeNum ��������ڵ�ĸ���
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/8 20:54
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
int getNodeNum(PBTNODE pRoot)
{
	if (NULL == pRoot)
	{
		return 0;
	}
	return getNodeNum(pRoot->pLeftChild) + getNodeNum(pRoot->pRightChild) + 1;
}
/*****************************************************************************
    *  @function    : getDepth ������������
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/9 19:50
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
int getDepth(PBTNODE pRoot)
{
	int depthLeft = 0;
	int depthRight = 0;
	if (NULL == pRoot)
	{
		return 0;
	}
	depthLeft = getDepth(pRoot->pLeftChild);
	depthRight = getDepth(pRoot->pRightChild);
	return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
}

/*****************************************************************************
    *  @function    : getKthLevelNodeNum ��������е�k��ڵ�ĸ���
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/10 20:35
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
int getKthLevelNodeNum(PBTNODE pRoot, int k)
{
	int kLeftNum = 0; //��������������k��ڵ����
	int kRightNum = 0;//��������������k��ڵ����
	if (k < 1) //����С��1
	{
		return 0;
	}
	if (NULL == pRoot)
	{
		return 0;
	}
	if (1 == k)//����Ϊ1
	{
		return k;
	}
	kLeftNum = getKthLevelNodeNum(pRoot->pLeftChild,k-1);//
	kRightNum = getKthLevelNodeNum(pRoot->pRightChild,k-1);
	return kLeftNum + kRightNum;
}

/*****************************************************************************
    *  @function    : getLeafNodeNum ���������Ҷ�ӽڵ�ĸ���
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/10 20:54
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description : ��Ϊ0�Ľڵ㱻��ΪҶ�ӽڵ�
*****************************************************************************/
int getLeafNodeNum(PBTNODE pRoot)
{
	int leftLeafNodeNum = 0;   //���Ҷ�ӽڵ����
	int rightLeafNodeNum = 0;  //�ұ�Ҷ�ӽڵ����
	if (NULL == pRoot)
	{
		return 0;
	}
	if(NULL == pRoot->pLeftChild && NULL == pRoot->pRightChild)
	{
		return 1;
	}
	leftLeafNodeNum = getLeafNodeNum(pRoot->pLeftChild);	//��������Ҷ�ӽڵ�ĸ���
	rightLeafNodeNum = getLeafNodeNum(pRoot->pRightChild);	//��������Ҷ�ӽڵ�ĸ���
	return leftLeafNodeNum + rightLeafNodeNum;
}