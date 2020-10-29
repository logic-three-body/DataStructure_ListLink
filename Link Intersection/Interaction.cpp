#include<iostream>//List Base Exercise
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








/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
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

Status ListDeleteElem(LinkList &L, ElemType e)
{
	if (!L || !L->next)
	{
		return ERROR;
	}
	LinkList p = L->next;
	LinkList q = L;//前驱删除
	while (p&&q)
	{
		if (p->data == e)
		{
			LinkList tmp = nullptr;
			tmp = q->next = p->next;
			delete p;
			p = tmp;
		}
		else
		{
			p = p->next;
			q = q->next;
		}

	}
	return OK;
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

Status InterSection(LinkList& La, LinkList&Lb, LinkList&Lc)
{
	if (!La&&!Lb)
	{
		return ERROR;
	}
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc = Lc = La;
	LinkList tmp=nullptr;
	while (pa&&pb)
	{
		if (pa->data==pb->data)//交集
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;

			tmp = pb;
			pb = pb->next;
			delete tmp;
		}
		else if(pa->data<pb->data)//删除小
		{
			tmp = pa;
			pa = pa->next;
			delete tmp;
		}
		else
		{
			tmp = pb;
			pb = pb->next;
			delete tmp;
		}
	}
	//删除多余
	while (pa)
	{
		tmp = pa;
		pa = pa->next;
		delete tmp;
	}
	while (pb)
	{
		tmp = pb;
		pb = pb->next;
		delete tmp;
	}
	//完善LC
	pc->next = nullptr;
	delete Lb;
	return OK;
}

int main()
{
	LinkList la, lb, lc;
	InitList(&la);
	InitList(&lb);
	InitList(&lc);
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1&&num2)
	{
		CreateListTail(&la, num1);
		CreateListTail(&lb, num2);
		if (InterSection(la, lb, lc))
		{
			ListTraverse(la);
		}
		std::cin >> num1 >> num2;
	}
	return 0;
}