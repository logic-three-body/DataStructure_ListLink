#include<iostream>//Linear List - Left Circulated Movement

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

void swap(int&a,int&b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//思路，分治法 ,分别逆置 ,产生循环左移效果
//Help:数据结构习题：P38
void Reverse(int* a,int left,int right)
{
	int i = left, j = right;//左右边界s
	while (i<j)
	{
		swap(a[i],a[j]);
		++i;//右移
		--j;//左移
	}
}

Status LeftShift(int*a, int len, int pos)
{
	if (!a&&len<=0&&pos<=0)
	{
		return ERROR;
	}
	if (pos>0&&pos<len)
	{
		Reverse(a, 0, len - 1);//逆置所有元素
		Reverse(a, 0, len - pos - 1);//逆置n-p元素(前一半)
		Reverse(a, len - pos, len - 1);//逆置p元素(后一半)
	}
	return OK;
}

int main()
{
	ElemType* List = nullptr;
	int num = 0;
	std::cin >> num;
	while (num)
	{
		List = new ElemType[num];
		CreateList(List, num);
		int pos = 0;
		std::cin >> pos;//输入左移数量
		LeftShift(List,num,pos);		
		ListTraverse(List,num);
		std::cin >> num;
	}
	return 0;
}