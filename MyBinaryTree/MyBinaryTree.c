#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
	char data;
	struct BTNode *pLeftChild;
	struct BTNode *pRightChild;
}BTNODE, *PBTNODE;

/*声明函数*/
//创建一个简单地二叉树
PBTNODE createSimpleBinaryTree();
//创建一个二叉树
PBTNODE createBinaryTree();
//先序遍历二叉树
void preTraverseBinaryTree(PBTNODE pRoot);
//中序遍历
void inTraverseBinaryTree(PBTNODE pRoot);
//后序遍历
void postTraverseBinaryTree(PBTNODE pRoot);
//层序遍历
void levelTraverseBinaryTree(PBTNODE pRoot);
//求二叉树中节点的个数
int getNodeNum(PBTNODE pRoot);
//求二叉树的深度
int getDepth(PBTNODE pRoot);
//求二叉树中第k层节点的个数
int getKthLevelNodeNum(PBTNODE pRoot, int k);
//求二叉树中叶子节点的个数
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
	printf("preTraverseBinaryTree： \n"); 
	preTraverseBinaryTree(pTree);
	printf("\n");
	printf("inTraverseBinaryTree： \n");
	inTraverseBinaryTree(pTree);
	printf("\n");
	printf("postTraverseBinaryTree： \n");
	postTraverseBinaryTree(pTree);
	printf("\n");

	printf("The number of nodes in binary tree is %d.\n",getNodeNum(pTree));
	printf("The depth of binary tree is %d.\n",getDepth(pTree));
	int k = 3;
	printf("The nodes' number of the %dth level is %d.\n",k, getKthLevelNodeNum(pTree, k));
	printf("The leaf nodes' number is %d.\n",getLeafNodeNum(pTree));
	return 0;
}

/*****************************************************************************
    *  @function	: createSimpleBinaryTree 创建一个链式二叉树
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/7 21:53
    *  @version  	: ver 1.0
    *  @inparam  	: void
    *  @outparam 	: pRoot 树的根节点地址
	*  @description :
*****************************************************************************/
PBTNODE createSimpleBinaryTree()
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
    *  @function    : createBinaryTree 创建二叉树
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/9 19:52
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description : 输入方式：AB##CD##EF##G##
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
			printf("内存分配失败，程序退出..");
			exit(-1);
		}
		pRoot->data = value;
		pRoot->pLeftChild = createBinaryTree();
		pRoot->pRightChild = createBinaryTree();
	}
	return pRoot;
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
    *  @function    : inTraverseBinaryTree 中序遍历
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
		//打印根节点
		printf("%c ",pRoot->data);
		if (NULL != pRoot->pRightChild)
		{
			inTraverseBinaryTree(pRoot->pRightChild);
		}
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
		//打印根节点
		printf("%c ",pRoot->data);
	}
}

/*****************************************************************************
    *  @function    : levelTraverseBinaryTree 层序遍历二叉树
    *  @author   	: happy.zhang
    *  @date     	: 2017/9/10 16:49
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
void levelTraverseBinaryTree(PBTNODE pRoot)
{
	
}

/*****************************************************************************
    *  @function    : getNodeNum 求二叉树节点的个数
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
    *  @function    : getDepth 求二叉树的深度
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
    *  @function    : getKthLevelNodeNum 求二叉树中第k层节点的个数
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/10 20:35
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description :
*****************************************************************************/
int getKthLevelNodeNum(PBTNODE pRoot, int k)
{
	int kLeftNum = 0; //二叉树左子树第k层节点个数
	int kRightNum = 0;//二叉树右子树第k层节点个数
	if (k < 1) //层数小于1
	{
		return 0;
	}
	if (NULL == pRoot)
	{
		return 0;
	}
	if (1 == k)//层数为1
	{
		return k;
	}
	kLeftNum = getKthLevelNodeNum(pRoot->pLeftChild,k-1);//
	kRightNum = getKthLevelNodeNum(pRoot->pRightChild,k-1);
	return kLeftNum + kRightNum;
}

/*****************************************************************************
    *  @function    : getLeafNodeNum 求二叉树中叶子节点的个数
    *  @author   	: ZhangLe
    *  @date     	: 2014/11/10 20:54
    *  @version  	: ver 1.0
    *  @inparam  	: 
    *  @outparam 	: 
	*  @description : 度为0的节点被称为叶子节点
*****************************************************************************/
int getLeafNodeNum(PBTNODE pRoot)
{
	int leftLeafNodeNum = 0;   //左边叶子节点个数
	int rightLeafNodeNum = 0;  //右边叶子节点个数
	if (NULL == pRoot)
	{
		return 0;
	}
	if(NULL == pRoot->pLeftChild && NULL == pRoot->pRightChild)
	{
		return 1;
	}
	leftLeafNodeNum = getLeafNodeNum(pRoot->pLeftChild);	//左子树中叶子节点的个数
	rightLeafNodeNum = getLeafNodeNum(pRoot->pRightChild);	//右子树中叶子节点的个数
	return leftLeafNodeNum + rightLeafNodeNum;
}