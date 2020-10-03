#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为char */


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
int ListLength(const LinkList& L)
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

void MergeList(LinkList &La, LinkList &Lb)
{
	LinkList p = La;
	while (p->next)
	{
		p = p->next;
	}
	p->next = Lb->next;
}

//定义两个链表，分别存
void DivEven_Odd(LinkList &L)
{
	LinkList pnow = L->next->next;
	LinkList pre = L->next;
	LinkList b;
	LinkList c;
	InitList(&b);
	InitList(&c);
	b->next = pre;
	c->next = pnow;
	int len = ListLength(L);
	if (len % 2 == 1)
	{
		while (pnow)//p
		{
			pre->next = pnow->next;
			pre = pnow->next;
			pnow->next = pre->next;//if p,p=null,q=null,p->next=null->next;
			pnow = pre->next;
			//if(!p->next && q->next) q->next=NULL;
		}
	}
	else if (len % 2 == 0)
		while (pnow->next)//p
		{
			pre->next = pnow->next;
			pre = pnow->next;
			pnow->next = pre->next;//if p,p=null,q=null,p->next=null->next;
			pnow = pre->next;
			if (!pnow->next && pre->next) pre->next = NULL;
		}
	//Show(b);
	//Show(c);
	MergeList(b, c);
	ListTraverse(b);
}


void main()
{
	int num;
	std::cin >> num;
	while (num != 0)
	{
		LinkList List;
		InitList(&List);
		CreateListTail(&List, num);
		//Show(A);
		DivEven_Odd(List);
		std::cin >> num;//key
	}
}