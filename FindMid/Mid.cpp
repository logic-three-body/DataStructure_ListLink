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
Status ListTraverse(ElemType* L,int num)
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

//Help:数据结构习题P39
ElemType FindMid(ElemType*a, ElemType*b, int n)
{
	int start1 = 0, end1 = n-1;
	int start2 = 0, end2 = n-1;
	int mid1 = 0, mid2 = 0;
	while (start1!=end1||start2!=end2)
	{
		mid1 = (start1 + end1) / 2;
		mid2 = (start2 + end2) / 2;
		if (a[mid1]==b[mid2])//中位数相等
		{
			return a[mid1];
		}
		//考虑奇偶
		else if (a[mid1]<b[mid2])
		{
			if ((start1+end1)%2==0)//偶数，舍弃A前，舍弃B后
			{
				start1 = mid1;
				end2 = mid2;
			}
			else
			{
				start1 = mid1 + 1;
				end2 = mid2;
			}
		}
		else
		{
			if ((start1 + end1) % 2 == 0)//偶数，舍弃A前，舍弃B后
			{
				end1 = mid1;
				start2 = mid2;
			}
			else
			{
				end1 = mid1 ;
				start2 = mid2+1;
			}
		}
	}
	return a[start1] < b[start2] ? a[start1] : b[start2];
}

int main()
{
	ElemType* List1=nullptr,*List2=nullptr;
	int num = 0;
	std::cin >> num;
	while (num)
	{
		List1 = new ElemType[num];
		List2 = new ElemType[num];
		CreateList(List1, num);
		CreateList(List2, num);
		int mid = FindMid(List1,List2,num);
		std::cout << mid << std::endl;
		std::cin >> num;
	}
	return 0;
}