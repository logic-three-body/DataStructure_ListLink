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

void Reverse_Iteration(LinkList*L) //采用迭代头插法逆转链表
{
	if (!(*L)->next)//若原链表为空
	{
		return;
	}
	LinkList tmp = nullptr;//中间临时变量，用于存放链表节点
	LinkList header;//指向链表第一个节点
	header = (*L)->next;
	(*L)->next = nullptr;//置空初始化原链表
	while (header)//如果此节点存在
	{
		tmp = header->next;
		header->next = (*L)->next;//头插法
		(*L)->next = header;//头插法
		header = tmp;
	}
}



int main()
{
	LinkList link;
	int num;//链表数量
	std::cin >> num;

	while (num != 0)
	{
		//尾插法创建链表
		CreateListTail(&link, num);
		//迭代头插法反转
		Reverse_Iteration(&link);
		ListTraverse(link);
		std::cin >> num;
	}



	return 0;
}