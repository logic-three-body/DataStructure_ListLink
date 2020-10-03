#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊchar */


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
int ListLength(const LinkList& L)
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

void MergeList(LinkList &La, LinkList &Lb)
{
	LinkList p = La;
	while (p->next)
	{
		p = p->next;
	}
	p->next = Lb->next;
}

//�������������ֱ��
void DivEven_Odd(LinkList &L)
{
	LinkList pnow = L->next->next;
	LinkList pre = L->next;
	LinkList b;
	LinkList c;
	InitList(&b);
	InitList(&c);
	b->next = pre;
	c->next = pnow;
	int len = ListLength(L);
	if (len % 2 == 1)
	{
		while (pnow)//p
		{
			pre->next = pnow->next;
			pre = pnow->next;
			pnow->next = pre->next;//if p,p=null,q=null,p->next=null->next;
			pnow = pre->next;
			//if(!p->next && q->next) q->next=NULL;
		}
	}
	else if (len % 2 == 0)
		while (pnow->next)//p
		{
			pre->next = pnow->next;
			pre = pnow->next;
			pnow->next = pre->next;//if p,p=null,q=null,p->next=null->next;
			pnow = pre->next;
			if (!pnow->next && pre->next) pre->next = NULL;
		}
	//Show(b);
	//Show(c);
	MergeList(b, c);
	ListTraverse(b);
}


void main()
{
	int num;
	std::cin >> num;
	while (num != 0)
	{
		LinkList List;
		InitList(&List);
		CreateListTail(&List, num);
		//Show(A);
		DivEven_Odd(List);
		std::cin >> num;//key
	}
}