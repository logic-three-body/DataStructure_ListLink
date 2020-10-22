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






/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	(*L)->data = n;                     /*ͷ�ڵ��¼Ԫ�س���*/
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

//��������Ϊ����
Status SortedListInsert(LinkList&L)//�����µ�Ԫ��
{

	if (!L && !L->next)
	{
		return ERROR;
	}

	//������Ԫ�ظ�ֵ
	ElemType elem;
	std::cin >> elem;
	LinkList NewNode = new Node;
	NewNode->next = nullptr;
	NewNode->data = elem;

	//TODO : ����Sorted:
	LinkList pNow = L->next;
	LinkList pre = L;
	while (pNow)
	{
		if (NewNode->data <= pNow->data&&pre->data <= NewNode->data)//������� ����������ĳ������֮��
		{
			NewNode->next = pNow;
			pre->next = NewNode;
			break;
		}
		else if (!pNow->next)//�Ѿ������һλ��ֱ�Ӳ���
		{
			pNow->next = NewNode;
			break;
		}
		else
		{
			//����:
			pre = pre->next;
			pNow = pNow->next;
		}
	}


	++L->data;//����������

	return OK;

}

Status FrontBackSplit(LinkList&LA,LinkList&LB)//�в��ֽ�����
{
	if (!LA && !LA->next)
	{
		return ERROR;
	}

	int length = LA->data;//��ȡ������
	LinkList flag = LA->next;
	LinkList pre = LA;
	for (int i = 0; i < length/2; i++)//��ȡ���нڵ��ַ
	{
		flag = flag->next;
		pre = pre->next;
	}

	//�ָ�
	LB->next = flag;
	LB->data = (length % 2 == 0) ? (length / 2) : ((length + 1) / 2);
	LA->data = length / 2;
	pre->next = nullptr;
	return OK;
}

int main()
{
	while (true)
	{
		LinkList List;
		InitList(&List);
		int Elem_num;//Ԫ�ظ���
		std::cin >> Elem_num;
		if (!Elem_num)
		{
			break;
		}
		CreateListTail(&List, Elem_num);//β�巨��������
		//��ʼ����Ԫ��
		SortedListInsert(List);
		ListTraverse(List);
		//��ʼ�ָ�����
		LinkList ListB;
		InitList(&ListB);
		FrontBackSplit(List, ListB);
		ListTraverse(List);
		ListTraverse(ListB);
		std::cout << "ԭ���� :" << List->data << std::endl;
		std::cout <<"B���� :" << ListB->data << std::endl;		
	}

	return 0;
}