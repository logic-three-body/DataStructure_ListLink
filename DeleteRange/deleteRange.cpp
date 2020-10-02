#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */


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

//Help:���ݽṹϰ��P35
Status RangeDelete(LinkList &L, int min, int max)
{
	if (!L&&!L->next)
	{
		return ERROR;
	}
	LinkList p = L->next;
	LinkList pre = nullptr;
	while (p&&p->data<min)//Ѱ���½�
	{
		pre = p;
		p = p->next;
	}
	while (p&&p->data<=max)//Ѱ���Ͻ�
	{
		p = p->next;
	}

	LinkList q = pre->next;//�½�ڵ�
	//�޸Ĵ�ɾ���ڵ��ָ�룬����������
	pre->next = p;
	LinkList s = nullptr;
	while (q!=p)//���¶���ɾ���ڵ�
	{
		s = q->next;
		delete q;
		q = s;
	}
	return OK;
}
int main()
{
	LinkList la;
	InitList(&la);
	
	int num;
	std::cin >> num;
	while (num)
	{
		CreateListTail(&la, num);
		
		int min, max;
		std::cin >> min >> max;

		RangeDelete(la, min, max);

		ListTraverse(la);
		
		std::cin >> num;
	}
	return 0;
}