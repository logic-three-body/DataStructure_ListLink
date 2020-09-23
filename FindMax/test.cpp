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

/*  ��������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  �����½�� */
		std::cin >> p->data;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
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