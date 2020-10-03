#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}


/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(ElemType* L, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (i == num - 1)
		{
			std::cout << L[i];
		}
		else
		{
			visit(L[i]);
		}
	}

	printf("\n");
	return OK;
}

Status CreateList(ElemType *L, int n)
{
	if (n <= 0)
	{
		return ERROR;
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> L[i];
	}
	return OK;
}
