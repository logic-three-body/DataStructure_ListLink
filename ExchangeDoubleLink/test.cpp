#include<iostream>//Exchange DoubleLinkList Elem

#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct DLNode
{
	ElemType data;
	DLNode *next;
	DLNode *pre;
}DLNode, *DLinkList;

void  CreateNoneCircu_DoubleLink(DLinkList& head) {
	head = (DLinkList)malloc(sizeof(DLNode));//创建链表第一个结点（首元结点）
	head->pre = NULL;
	head->next = NULL;
	head->data = 1;
	DLinkList * list = &head;
	for (int i = 2; i <= 3; i++) {
		//创建并初始化一个新结点
		DLNode * body = (DLNode*)malloc(sizeof(DLNode));
		body->pre = NULL;
		body->next = NULL;
		body->data = i;

		(*list)->next = body;//直接前趋结点的next指针指向新结点
		body->pre = *list;//新结点指向直接前趋结点
		*list = (*list)->next;
	}

}

void CreateCircu_DoubleLink(DLinkList&head, int num)
{
	head = (DLinkList)malloc(sizeof(DLNode));
	DLinkList s, r;
	r = head;
	for (int i = 0; i < num; i++)
	{
		s = (DLinkList)malloc(sizeof(DLNode));
		std::cin>>s->data;
		r->next = s;
		s->pre = r;
		r = s;
	}
	r->next = head;

}
void CreateListTail(DLinkList *L, int n)
{
	DLinkList p, r;
	int i;
	*L = (DLinkList)malloc(sizeof(DLNode)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (DLNode *)malloc(sizeof(DLNode)); /*  生成新结点 */
		std::cin >> p->data;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

void ToExchange(DLinkList&L,int num)
{
	if (num==0||num==1)
	{
		return;
	}
	DLinkList now=L->next;
	int i = 0;
	now = L;
	while (now)
	{
		now = now->next;
		i++;
		if (i == num)break;
	}
	DLinkList q = now->pre;
	q->pre->next = now;
	now->pre = q->pre;
	q->next = now->next;
	q->pre = now;
	now->next->pre = q;
	now->next = q;
}

void Output(DLinkList& L, int n)
{
	DLinkList p;
	p = L->next;
	int flag = 1;
	while (n--)
	{
		if (flag)
		{
			flag = 0;
			std::cout << p->data;
		}
		else
			std::cout << " " << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}
int main()
{
	DLinkList test;
	int num,flag;
	std::cin >> num;
	while (num!=0)
	{
	CreateCircu_DoubleLink(test,num);
	std::cin >> flag;
	ToExchange(test,flag);
	Output(test,num);
	std::cin >> num;
	}

	system("pause");
	return 0;
}