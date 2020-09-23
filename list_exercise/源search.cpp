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

Status Search(LinkList&L,int flag)
{
	int counter = 0;
	LinkList p, q;
	p = q = L->next;
	while (p)
	{
		if (counter<flag)
		{
			++counter;
		}
		else
		{
			q = q->next;
		}
		p = p->next;
	}
	if (counter == flag)
	{
		std::cout << q->data << std::endl;
		return OK;
	}
	else
	{
		return ERROR;
	}

}

int main()
{
	LinkList list;
	int num,which;
	std::cin >> num;
	while (num)
	{
		CreateListTail(&list,num);
		std::cin >> which;
		Search(list, which);
		std::cin >> num;
	}
	system("pause");
	return 0;
}