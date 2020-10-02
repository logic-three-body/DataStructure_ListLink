#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */


Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

typedef struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node *LinkList; /* 定义LinkList */

/* 初始化顺序线性表 */
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L)) /* 存储分配失败 */
		return ERROR;
	(*L)->next = nullptr; /* 指针域为空 */

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}



/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*求差集，相等删除*/
Status Diff(LinkList& La, LinkList&Lb)
{
	if (!La&&!Lb&&!La->next&&!Lb->next)
	{
		return ERROR;
	}
	int count = 0;//元素个数
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pre = La;
	LinkList tmp = nullptr;
	while (pa&&pb)
	{
		//谁小谁后移
		if (pa->data<pb->data)
		{
			pre = pa;
			pa = pa->next;
		}
		else if (pa->data>pb->data)
		{
			pb = pb->next;
		}
		else
		{
			pre->next = pa->next;
			tmp = pa;
			pa = pa->next;
			delete tmp;
		}
	}
	return count;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		std::cin >> p->data;
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = nullptr;                       /* 表示当前链表结束 */
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList& L)
{
	LinkList p = L->next;
	std::cout << (p->data);
	p = p->next;
	while (p)
	{
		std::cout << " ";
		std::cout << p->data;
		p = p->next;
	}
	printf("\n");
	return OK;
}
int main()
{
	LinkList la, lb;
	InitList(&la);
	InitList(&lb);
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1&&num2)
	{

		CreateListTail(&la, num1);
		CreateListTail(&lb, num2);
		Diff(la, lb);
		ListTraverse(la);
		std::cout << ListLength(la) << std::endl;
		std::cin >> num1 >> num2;
	}
	return 0;
}







