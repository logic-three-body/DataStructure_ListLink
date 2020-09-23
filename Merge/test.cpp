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
	std::cout << (p->data) ;
	p = p->next;
	while (p)
	{
		std::cout<<" ";
		std::cout << (p->data) ;
		p = p->next;
	}
	printf("\n");
	return OK;
}

void Merge(LinkList& LA, LinkList& LB, LinkList& LC)
{
	LinkList ptrA, ptrB, ptrC,tmp;
	ptrA = LA->next;
	ptrB = LB->next;
	LC = ptrC = LA;
	LC->next = nullptr;

	while (ptrA||ptrB)
	{
		if (!ptrA)
		{
			tmp = ptrB;
			ptrB = ptrB->next;
		}
		else if (!ptrB)
		{
			tmp = ptrA;
			ptrA = ptrA->next;
		}
		else if (ptrA->data<=ptrB->data)
		{
			tmp = ptrA;
			ptrA = ptrA->next;
		}
		else
		{
			tmp = ptrB;
			ptrB = ptrB->next;
		}
		//ͷ�巨
		tmp->next = LC->next;
		LC->next = tmp;
	}
	free(LB);
}

//6 2 2 1 6 4 2 5 5 3
int main()
{
	LinkList listA = nullptr, listB = nullptr, listC = nullptr;
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1 != 0 && num2 != 0)
	{
		CreateListTail(&listA, num1);
		CreateListTail(&listB, num2);
		Merge(listA, listB, listC);
		ListTraverse(listC);
		std::cin >> num1 >> num2;
	}
	system("pause");
	return 0;
}