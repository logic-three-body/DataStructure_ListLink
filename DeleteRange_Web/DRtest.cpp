#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return;
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  �����½�� */
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

void DelRange(LinkList &L)
{
	int a1, a2;
	LinkList pre = L->next->next, p = L->next;
	cin >> a1 >> a2;
	while (p->data < a1)
	{
		if (p->next->data >= a1)
			break;
		p = p->next;
	}
	if (p->data >= a1)
	{
		p = L;
	}
	while (pre->data <= a2)
	{
		pre = pre->next;
		if (pre->data > a2)
		{
			p->next = pre;
			break;
		}
		else if (pre->next == NULL)
		{
			p->next = NULL;
			break;
		}
	}
	ListTraverse(L);
}
int main()
{
	int num;
	cin >> num;
	while (num != 0)
	{
		LinkList list;
		InitList(list);
		CreateListTail(&list, num);
		DelRange(list);
		cin >> num;
	}
	return 0;
}