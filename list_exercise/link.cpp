#include "link.h"

link::link()
{
	LinkList = new Node;
	LinkList->next = nullptr;
}

Status link::ListEmpty()
{
	if (LinkList->next)
		return FALSE;
	else
		return TRUE;
}

Status link::ClearList()
{
	Node *p, *q;
	p = LinkList->next;           /*  pָ���һ����� */
	while (p)                /*  û����β */
	{
		q = p->next;
		delete p;
		p = q;
	}
	LinkList->next = nullptr;        /* ͷ���ָ����Ϊ�� */
	return OK;
}

int link::ListLength()
{
	int i = 0;
	Node* p = LinkList->next; /* pָ���һ����� */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

ElemType * link::GetElem(int i)
{
	ElemType * e=new ElemType(0);
	int j;
	Node* p;		/* ����һ���p */
	p = LinkList->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j < i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if (!p || j > i)
		return ERROR;  /*  ��i��Ԫ�ز����� */
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return e;
}

int link::LocateElem(ElemType e)
{
	int i = 0;
	Node* p = LinkList->next;
	while (p)
	{
		i++;
		if (p->data == e) /* �ҵ�����������Ԫ�� */
			return i;
		p = p->next;
	}

	return 0;
}

Status link::ListInsert(int i, ElemType e)
{
	int j;
	Node* p, *s;
	p = LinkList;
	j = 1;
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* ��i��Ԫ�ز����� */
	s = new Node;  /*  �����½��(C++���Ա�׼����) */
	s->data = e;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return OK;
}

Status link::ListDelete(int i, ElemType * e)
{
	int j;
	Node* p, *q;
	p = LinkList;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	delete q;                 /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
}

Status link::ListTraverse()
{
	Node* p = LinkList->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

void link::CreateListHead(int n)
{
	Node* p;
	int i;
	srand(time(0));                         /* ��ʼ����������� */
	LinkList = new Node({ 0,nullptr });
	//(LinkList)->next = nullptr;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i = 0; i < n; i++)
	{
		p = new Node({ 0,nullptr }); /*  �����½�� */
		p->data = rand() % 100 + 1;             /*  �������100���ڵ����� */
		p->next = LinkList->next;
		LinkList->next = p;						/*  ���뵽��ͷ */
	}
}

void link::CreateListTail(int n)
{
	Node* p, *r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	LinkList = new Node({ 0,nullptr }); /* LΪ�������Ա� */
	r = LinkList;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = new Node({0,nullptr}); /*  �����½�� */
		p->data = rand() % 100 + 1;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = nullptr;                       /* ��ʾ��ǰ������� */
}
