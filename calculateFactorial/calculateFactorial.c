//  [10/26/2014 Happy]
/************************************************************************/
/* ����׳�                                                                     */
/************************************************************************/
#include <stdio.h>

//��������
//���õݹ����׳�
long calculateFactorialbyRecursion(long n);
//����ѭ������׳�
long calculateFactorialbyLoop(long n);

int main(void)
{
	printf("%d \n", calculateFactorialbyLoop(3));
	printf("%d \n", calculateFactorialbyRecursion(4));
}

//���庯��
/*****************************************************************************
    *  @brief    : calculateFactorialbyRecursion ���õݹ����n�Ľ׳�
    *  @author   : Zhangle
    *  @date     : 2014/10/26 15:02
    *  @version  : ver 1.0
    *  @inparam  : n
    *  @outparam : n�Ľ׳� 
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
    *  @brief    : calculateFactorialbyLoop ����ѭ������n�Ľ׳�
    *  @author   : Zhangle
    *  @date     : 2014/10/26 15:03
    *  @version  : ver 1.0
    *  @inparam  : n
    *  @outparam : n�Ľ׳� 
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
