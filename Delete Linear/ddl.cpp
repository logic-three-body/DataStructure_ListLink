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

typedef struct
{
	ElemType data[MAXSIZE];        /* 数组，存储数据元素 */
	int length;                                /* 线性表当前长度 */
}SqList;

/* 初始化顺序线性表 */
Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];

	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			break;
	}
	if (i >= L.length)
		return 0;

	return i + 1;
}

Status CreateList(SqList *L,int n)
{
	if (n<=0)
	{
		return ERROR;
	}
	L->length = n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> L->data[i];
	}
	return OK;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L, int i, ElemType e)//i为线性表位置
{
	int k;
	if (L->length == MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L->length + 1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i <= L->length)        /* 若插入数据位置不在表尾 */
	{
		for (k = L->length - 1; k >= i - 1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */ //此时k对应的是数组下标
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          /* 将新元素插入 */
	L->length++;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L, int i)
{
	int k;
	if (L->length == 0)               /* 线性表为空 */
		return ERROR;
	if (i<1 || i>L->length)         /* 删除位置不正确 */
		return ERROR;
	if (i < L->length)                /* 如果删除不是最后位置 */
	{
		for (k = i; k < L->length; k++)/* 将删除位置后继元素前移 */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

Status ListDeleteElem(SqList &L, ElemType e)
{
	if (L.length<=0)
	{
		return ERROR;
	}
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i]==e)
		{
			ListDelete(&L, i + 1);
			--i;//删除后数组前移i应先减才能见到下一个元素
		}
	}
	return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (i==L.length-1)
		{
			std::cout << L.data[i];
		}
		else
		{
			visit(L.data[i]);
		}
	}
		
	printf("\n");
	return OK;
}


void Del_item(SqList &L)
{
	int item; int i; int j; int flag[100];
	std::cin >> item;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == item)
		{
			flag[L.data[i]] = 1;
		}
	int s = L.length; int k = 0;
	for (i = 0; i < s; i++)
		if (flag[L.data[i]] != 1)
		{
			//for(j=i;j<L.num-1;j++)//不必要的循环 
			L.data[k] = L.data[i];
			k++;
			//L.num--;
			//key
		}
	L.length = k;
}


int main()
{
	SqList List;
	InitList(&List);
	int num = 0;
	std::cin >> num;
	while (num)
	{
		CreateList(&List,num);
		int DeleteElem = 0;
		std::cin >> DeleteElem;
		ListDeleteElem(List, DeleteElem);
		ListTraverse(List);
		std::cin >> num;
	}
	return 0;
}