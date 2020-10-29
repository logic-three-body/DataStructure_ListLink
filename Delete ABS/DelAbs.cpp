#include <iostream>//Delete ABS Node
#include<cmath>
#include<string.h>//For metset
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

const int FIND = 1;

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

Status DeleEquaAbs(LinkList& L,int num)
{
	if (!L&&!L->next)
	{
		return ERROR;
	}
	int *t =new int[num + 1];//����0�ŵ�Ԫ
	memset(t,0,num+1);//������0
	LinkList p = L->next;
	LinkList pre = L;
	LinkList tmp = nullptr;
	while (p)
	{
		if (FIND==t[abs(p->data)])//�ѳ��ֹ�
		{
			pre->next = p->next;
			tmp = p;
			p = p->next;
			delete tmp;
		}
		else
		{
			t[abs(p->data)] = FIND;
			pre = p;
			p = p->next;
		}
	}
	return OK;

}

int main()
{
	LinkList la;
	InitList(la);
	int num;
	std::cin >> num;
	while (num)
	{
		CreateListTail(&la, num);
		DeleEquaAbs(la,num);
		ListTraverse(la);
		std::cin >> num;
	}
	return 0;
}
