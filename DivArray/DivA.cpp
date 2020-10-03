#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
#define FAIL -1
typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

const int succeed = 0;//划分成功
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
	for (i = 0; i < num; ++i)
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
	for (int i = 0; i < n; ++i)
	{
		std::cin >> L[i];
	}
	return OK;
}

void swap(int&a, int&b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

/* 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
int Partition(ElemType *L, int& low, int& high)
{
	int pivotkey;

	pivotkey = L[low]; /* 用子表的第一个记录作枢轴记录 */
	while (low < high) /*  从表的两端交替地向中间扫描 */
	{
		while (low < high&&L[high] >= pivotkey)
			high--;
		swap(L[low], L[high]);/* 将比枢轴记录小的记录交换到低端 */
		while (low < high&&L[low] <= pivotkey)
			low++;
		swap(L[low], L[high]);/* 将比枢轴记录大的记录交换到高端 */
	}
	return low; /* 返回枢轴所在位置 */
}

Status DivArray_QS(ElemType*a, int length, ElemType*A1, ElemType*A2)
{
	if (!a&&length <= 0)
	{
		return ERROR;
	}

	int low = 0, high = length - 1;//上下界
	int low_new = 0, high_new = length - 1;//新表上下界
	int sum1 = 0, sum2 = 0;//A1,A2元素和
	int flag = OK;//划分是否成功
	int mid = length / 2;//表中间位置
	while (flag)
	{
		low = Partition(a,low,high);//TODO:IF CORRECT?

		if (low == mid - 1)//划分成功
		{
			flag = succeed;
		}
		else
		{
			if (low < mid - 1)
			{
				low_new = ++low;
				high = high_new;
			}
			else
			{
				high_new = --high;
				low = low_new;
			}
		}
	}
	A1 = new ElemType[mid];
	for (int i = 0; i < mid; i++)
	{
		A1[i] = a[i];

	}
	ListTraverse(A1, mid);
	A2 = new ElemType[length - mid];
	for (int i = mid, k = 0; i < length; ++i, ++k)
	{
		A2[k] = a[i];
	}
	ListTraverse(A2, length - mid);
	return OK;
}

//TODO:AC后尝试一下partion函数
//Help:数据结构习题P43 QucikSort
//非递归法快速排序（迭代）
Status DivArray(ElemType*a, int length,ElemType*A1,ElemType*A2)
{
	if (!a&&length<=0)
	{
		return ERROR;
	}
	int low = 0, high = length - 1;//上下界
	int low_new = 0, high_new = length - 1;//新表上下界
	int sum1 = 0, sum2 = 0;//A1,A2元素和
	int flag = OK;//划分是否成功
	int mid = length / 2;//表中间位置
	while (flag)
	{
		int pivot_key = a[low];//选择枢纽

		
		while (low < high)//从两端交替地向中间扫描
		{
			while (low < high&&a[high] >= pivot_key)
			{
				--high;//从右向左依次搜索
			}
			if (low != high)
			{
				a[low] = a[high];//枢纽小的记录到低端
			}
			while (low < high&&a[low] <= pivot_key)
			{
				++low;
			}
			if (low != high)
			{
				a[high] = a[low];//枢纽大的记录到高端
			}
		}
		a[low] = pivot_key;//纪录枢纽
		if (low==mid-1)//划分成功
		{
			flag =succeed;
		}
		else
		{
			if (low<mid-1)
			{
				low_new = ++low;
				high = high_new;
			}
			else
			{
				high_new = --high;
				low = low_new;
			}
		}

	}// end of while (low<high)
	A1 = new ElemType[mid];
	for (int i = 0; i < mid; i++)
	{
		A1[i] = a[i];
		
	}
	ListTraverse(A1, mid);
	A2 = new ElemType[length - mid];
	for (int i = mid,k=0; i < length; ++i,++k)
	{
		A2[k] = a[i];
	}
	ListTraverse(A2, length - mid);
	return OK;
}

int main()
{
	ElemType* List = nullptr;
	ElemType *a1=nullptr, *a2=nullptr;
	int num = 0;
	std::cin >> num;
	while (num)
	{
		List = new ElemType[num];
		CreateList(List, num);
		//DivArray(List, num,a1,a2);
		DivArray_QS(List, num, a1, a2);
		ListTraverse(List, num);
		std::cin >> num;
	}
	return 0;
}

