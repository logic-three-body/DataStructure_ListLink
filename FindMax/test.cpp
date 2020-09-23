#include<iostream>

#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode, *LinkList;

/*  建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  生成新结点 */
		std::cin >> p->data;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

Status ListTraverse(LinkList& L)
{
	LinkList p = L->next;
	ElemType Max;
	Max = p->data;
	while (p)
	{
		//if (p->data >= p->next->data)
		//{
		//	Max = p->data;
		//}
		//else
		//{
		//	Max = p->next->data;
		//}
		Max = Max >= p->data ? Max : p->data;
		p = p->next;
	}
	std::cout << Max << std::endl;

	return OK;
}

int main()
{
	LinkList link;
	int num;
	std::cin >> num;
	while (num != 0)
	{
		CreateListTail(&link, num);
		ListTraverse(link);
		std::cin >> num;
	}
	return 0;
}