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
	std::cout << (p->data);
	p = p->next;
	while (p)
	{
		std::cout << " ";
		std::cout << (p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//Help ： 数据结构习题P30
void Merge(LinkList& LA, LinkList& LB, LinkList& LC)
{
	LinkList pa = LA->next, pb = LB->next,pc;
	LC = pc = LA;
	while (pa&&pb)
	{
		if (pa->data<pb->data)//谁大谁后移
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else  //相等删除某一方节点
		{
			LinkList tmp=nullptr;
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			tmp = pb->next;
			delete pb;
			pb = tmp;
		}		
	}
	pc->next = pa ? pa : pb;//若某一方为空（数量不够）直接把非空链表接在LC上
	delete LB;
}

int main()
{
	LinkList listA = nullptr, listB = nullptr, listC = nullptr;
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1 != 0 && num2 != 0)
	{
		CreateListTail(&listA, num1);
		CreateListTail(&listB, num2);
		Merge(listA, listB, listC);
		ListTraverse(listC);
		std::cin >> num1 >> num2;
	}
	system("pause");
	return 0;
}