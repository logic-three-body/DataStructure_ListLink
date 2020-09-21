#include<iostream>

#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode,*LinkList;

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

void Reverse_Iteration(LinkList*L) //���õ���ͷ�巨��ת����
{
	if (!(*L)->next)//��ԭ����Ϊ��
	{
		return;
	}
	LinkList tmp = nullptr;//�м���ʱ���������ڴ������ڵ�
	LinkList header;//ָ�������һ���ڵ�
	header = (*L)->next;
	(*L)->next = nullptr;//�ÿճ�ʼ��ԭ����
	while (header)//����˽ڵ����
	{
		tmp = header->next;
		header->next = (*L)->next;//ͷ�巨
		(*L)->next = header;//ͷ�巨
		header = tmp;
	}
}

LNode*Reverse_Recursion()//���õݹ�ͷ�巨��ת����
{

}

int main()
{
	LinkList link;
	int num;//��������
	std::cin >> num;
	//β�巨��������
	CreateListTail(&link,num);
	//����ͷ�巨��ת
	Reverse_Iteration(&link);

	system("pause");
	return 0;
}