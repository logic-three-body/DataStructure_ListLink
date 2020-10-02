#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */


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

//Help:数据结构习题P35
Status RangeDelete(LinkList &L, int min, int max)
{
	if (!L&&!L->next)
	{
		return ERROR;
	}
	LinkList p = L->next;
	LinkList pre = nullptr;
	while (p&&p->data<min)//寻找下界
	{
		pre = p;
		p = p->next;
	}
	while (p&&p->data<=max)//寻找上界
	{
		p = p->next;
	}

	LinkList q = pre->next;//下界节点
	//修改待删除节点的指针，孤立其区间
	pre->next = p;
	LinkList s = nullptr;
	while (q!=p)//自下而上删除节点
	{
		s = q->next;
		delete q;
		q = s;
	}
	return OK;
}
int main()
{
	LinkList la;
	InitList(&la);
	
	int num;
	std::cin >> num;
	while (num)
	{
		CreateListTail(&la, num);
		
		int min, max;
		std::cin >> min >> max;

		RangeDelete(la, min, max);

		ListTraverse(la);
		
		std::cin >> num;
	}
	return 0;
}