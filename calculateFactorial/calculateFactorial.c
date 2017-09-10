//  [10/26/2014 Happy]
/************************************************************************/
/* 计算阶乘                                                                     */
/************************************************************************/
#include <stdio.h>

//声明函数
//利用递归计算阶乘
long calculateFactorialbyRecursion(long n);
//利用循环计算阶乘
long calculateFactorialbyLoop(long n);

int main(void)
{
	printf("%d \n", calculateFactorialbyLoop(3));
	printf("%d \n", calculateFactorialbyRecursion(4));
}

//定义函数
/*****************************************************************************
    *  @brief    : calculateFactorialbyRecursion 利用递归计算n的阶乘
    *  @author   : Zhangle
    *  @date     : 2014/10/26 15:02
    *  @version  : ver 1.0
    *  @inparam  : n
    *  @outparam : n的阶乘 
*****************************************************************************/
long calculateFactorialbyRecursion(long n)
{
	if (1 == n)
	{
		return 1;
	}
	return calculateFactorialbyRecursion(n-1) * n;
}

/*****************************************************************************
    *  @brief    : calculateFactorialbyLoop 利用循环计算n的阶乘
    *  @author   : Zhangle
    *  @date     : 2014/10/26 15:03
    *  @version  : ver 1.0
    *  @inparam  : n
    *  @outparam : n的阶乘 
*****************************************************************************/
long calculateFactorialbyLoop(long n)
{
	int i = 1;
	int factorial = 1;
	for (i = 1; i <= n; ++i)
	{
		factorial = factorial * i;
	}
	return factorial;
}
