#include "link.h"

link::link()
{
	LinkList = new Node;
	LinkList->next = nullptr;
}

Status link::ListEmpty()
{
	if (LinkList->next)
		return FALSE;
	else
		return TRUE;
}

Status link::ClearList()
{
	Node *p, *q;
	p = LinkList->next;           /*  p指向第一个结点 */
	while (p)                /*  没到表尾 */
	{
		q = p->next;
		delete p;
		p = q;
	}
	LinkList->next = nullptr;        /* 头结点指针域为空 */
	return OK;
}

int link::ListLength()
{
	int i = 0;
	Node* p = LinkList->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

ElemType * link::GetElem(int i)
{
	ElemType * e=new ElemType(0);
	int j;
	Node* p;		/* 声明一结点p */
	p = LinkList->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j < i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if (!p || j > i)
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return e;
}

int link::LocateElem(ElemType e)
{
	int i = 0;
	Node* p = LinkList->next;
	while (p)
	{
		i++;
		if (p->data == e) /* 找到这样的数据元素 */
			return i;
		p = p->next;
	}

	return 0;
}

Status link::ListInsert(int i, ElemType e)
{
	int j;
	Node* p, *s;
	p = LinkList;
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* 第i个元素不存在 */
	s = new Node;  /*  生成新结点(C++语言标准函数) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

Status link::ListDelete(int i, ElemType * e)
{
	int j;
	Node* p, *q;
	p = LinkList;
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
	*e = q->data;               /* 将q结点中的数据给e */
	delete q;                 /* 让系统回收此结点，释放内存 */
	return OK;
}

Status link::ListTraverse()
{
	Node* p = LinkList->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

void link::CreateListHead(int n)
{
	Node* p;
	int i;
	srand(time(0));                         /* 初始化随机数种子 */
	LinkList = new Node({ 0,nullptr });
	//(LinkList)->next = nullptr;                      /*  先建立一个带头结点的单链表 */
	for (i = 0; i < n; i++)
	{
		p = new Node({ 0,nullptr }); /*  生成新结点 */
		p->data = rand() % 100 + 1;             /*  随机生成100以内的数字 */
		p->next = LinkList->next;
		LinkList->next = p;						/*  插入到表头 */
	}
}

void link::CreateListTail(int n)
{
	Node* p, *r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	LinkList = new Node({ 0,nullptr }); /* L为整个线性表 */
	r = LinkList;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = new Node({0,nullptr}); /*  生成新结点 */
		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = nullptr;                       /* 表示当前链表结束 */
}
