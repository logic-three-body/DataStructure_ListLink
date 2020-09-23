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