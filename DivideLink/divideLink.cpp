#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */


Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

typedef struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node *LinkList; /* ����LinkList */

/* ��ʼ��˳�����Ա� */
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!(*L)) /* �洢����ʧ�� */
		return ERROR;
	(*L)->next = nullptr; /* ָ����Ϊ�� */

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}



/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* pָ���һ����� */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		std::cin >> p->data;
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = nullptr;                       /* ��ʾ��ǰ������� */
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
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

Status Div(LinkList&la, LinkList&lb)
{
	if (!la&&!la->next)
	{
		return ERROR;
	}
	LinkList lc = la;
	LinkList pc = lc;
	LinkList pb = lb;
	LinkList pa = la->next;
	//LinkList tmp = nullptr;
	while (pa)
	{
		if (pa->data>0)
		{
			pb->next = pa;
			pb = pa;
			pa = pa->next;
		}
		else if (pa->data<0)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else//pa->data=0
		{
			pa = pa->next;
		}
	}
	pb->next = nullptr;
	pc->next = nullptr;
	return OK;

}

int main()
{
	LinkList la, lb;
	InitList(&la);
	InitList(&lb);
	int num;
	std::cin >> num ;
	while (num)
	{
		CreateListTail(&la, num);
		Div(la, lb);
		ListTraverse(la);
		ListTraverse(lb);
		std::cin >> num;
	}
	return 0;
}