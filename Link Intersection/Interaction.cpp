#include<iostream>//List Base Exercise
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








/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L, int i)
{
	int j;
	LinkList p, q;
	p = *L;
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
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
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

Status ListDeleteElem(LinkList &L, ElemType e)
{
	if (!L || !L->next)
	{
		return ERROR;
	}
	LinkList p = L->next;
	LinkList q = L;//ǰ��ɾ��
	while (p&&q)
	{
		if (p->data == e)
		{
			LinkList tmp = nullptr;
			tmp = q->next = p->next;
			delete p;
			p = tmp;
		}
		else
		{
			p = p->next;
			q = q->next;
		}

	}
	return OK;
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

Status InterSection(LinkList& La, LinkList&Lb, LinkList&Lc)
{
	if (!La&&!Lb)
	{
		return ERROR;
	}
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc = Lc = La;
	LinkList tmp=nullptr;
	while (pa&&pb)
	{
		if (pa->data==pb->data)//����
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;

			tmp = pb;
			pb = pb->next;
			delete tmp;
		}
		else if(pa->data<pb->data)//ɾ��С
		{
			tmp = pa;
			pa = pa->next;
			delete tmp;
		}
		else
		{
			tmp = pb;
			pb = pb->next;
			delete tmp;
		}
	}
	//ɾ������
	while (pa)
	{
		tmp = pa;
		pa = pa->next;
		delete tmp;
	}
	while (pb)
	{
		tmp = pb;
		pb = pb->next;
		delete tmp;
	}
	//����LC
	pc->next = nullptr;
	delete Lb;
	return OK;
}

int main()
{
	LinkList la, lb, lc;
	InitList(&la);
	InitList(&lb);
	InitList(&lc);
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1&&num2)
	{
		CreateListTail(&la, num1);
		CreateListTail(&lb, num2);
		if (InterSection(la, lb, lc))
		{
			ListTraverse(la);
		}
		std::cin >> num1 >> num2;
	}
	return 0;
}