#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  生成新结点 */
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

void DelRange(LinkList &L)
{
	int a1, a2;
	LinkList pre = L->next->next, p = L->next;
	cin >> a1 >> a2;
	while (p->data < a1)
	{
		if (p->next->data >= a1)
			break;
		p = p->next;
	}
	if (p->data >= a1)
	{
		p = L;
	}
	while (pre->data <= a2)
	{
		pre = pre->next;
		if (pre->data > a2)
		{
			p->next = pre;
			break;
		}
		else if (pre->next == NULL)
		{
			p->next = NULL;
			break;
		}
	}
	ListTraverse(L);
}
int main()
{
	int num;
	cin >> num;
	while (num != 0)
	{
		LinkList list;
		InitList(list);
		CreateListTail(&list, num);
		DelRange(list);
		cin >> num;
	}
	return 0;
}