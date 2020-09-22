#include<iostream>

#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct LNode
{
	ElemType data;
	LNode *next;
};

/*  ��������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LNode *L, int n)
{
	LNode* p, *r;
	int i;                 
	L = (LNode*)malloc(sizeof(LNode)); /* LΪ�������Ա� */
	r = L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  �����½�� */
		std::cin >> p->data;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

void Reverse_Iteration(LNode*L) //���õ���ͷ�巨��ת����
{
	if (L->next)//��ԭ����Ϊ��
	{
		return;
	}
	LNode* tmp = nullptr;//�м���ʱ���������ڴ������ڵ�
	LNode* header;//ָ�������һ���ڵ�
	header = (L)->next;
	(L)->next = nullptr;//�ÿճ�ʼ��ԭ����
	while (header)//����˽ڵ����
	{
		tmp = header->next;
		header->next = (L)->next;//ͷ�巨
		(L)->next = header;//ͷ�巨
		header = tmp;
	}
}

LNode* Reverse_Recursion(LNode*L)//���õݹ�ͷ�巨��ת����
{
	if (!(L)->next)
	{
		return (L);
	}

	//�ݹ鷭ת���б�
	LNode* newList = Reverse_Recursion((L)->next);//ָ�����һ���ڵ㣬�ڵݹ鷵�ع�����һֱָ�����һ���ڵ�

	(L)->next->next = (L);//����ָ��ǰ�ڵ㣬��ʱ��ǰ�ڵ����ǰһ���ڵ��γɻ�·
	(L)->next = nullptr;//�Ͽ���·
	return newList;//��Ϊ�µ�ͷ�ڵ�
}

int main()
{
	LNode link;
	int num;//��������
	std::cin >> num;
	//β�巨��������
	CreateListTail(&link,num);
	//����ͷ�巨��ת
	Reverse_Iteration(&link);
    link=*Reverse_Recursion(&link);

	system("pause");
	return 0;
}