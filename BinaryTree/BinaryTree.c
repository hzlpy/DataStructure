#include <stdio.h>
#include <malloc.h>
typedef struct BTNode
{
	char data;
	struct BTNode *pLeftChild;
	struct BTNode *pRightChild;
}BTNODE, *PBTNODE;
/*声明函数*/
//创建一个链式二叉树
PBTNODE createLinkedBinaryTree();
//先序遍历二叉树
void preTraverseBinaryTree(PBTNODE pRoot);
//中序遍历
void inTraverseBinaryTree(PBTNODE pRoot);
//后序遍历
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
	return 0;
}

/*****************************************************************************
    *  @function    : createLinkedBinaryTree 创建一个链式二叉树
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:53
    *  @version  	: ver 1.0
    *  @inparam  	: void
    *  @outparam 	: pRoot 树的根节点地址
	*  @description :
*****************************************************************************/
PBTNODE createLinkedBinaryTree()
{
	//分配内存
	PBTNODE pA = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pB = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pC = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pD = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pE = (PBTNODE)malloc(sizeof(BTNODE));
	//赋值
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	//链接
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
    *  @function    : preTraverseBinaryTree 先序遍历二叉树
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:51
    *  @version  	: ver 1.0
    *  @inparam  	: pRoot 树的根节点地址
    *  @outparam 	: void
	*  @description : 先访问根节点，再先序访问左子树，再后序访问右子树
*****************************************************************************/
void preTraverseBinaryTree(PBTNODE pRoot)
{
	if (NULL != pRoot)
	{
		//打印根节点
		printf("%c \n",pRoot->data);
		preTraverseBinaryTree(pRoot->pLeftChild);
		preTraverseBinaryTree(pRoot->pRightChild);
	}
}
/*****************************************************************************
    *  @function    : postTraverseBinaryTree 后序遍历二叉树
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:57
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
void postTraverseBinaryTree(PBTNODE pRoot)
{
// 	if (NULL != pRoot)
// 	{
// 		//打印根节点
// 		printf("%c \n",pRoot->data);
// 		postTraverseBinaryTree(pRoot->pRightChild);
// 		postTraverseBinaryTree(pRoot->pLeftChild);
// 	}
}