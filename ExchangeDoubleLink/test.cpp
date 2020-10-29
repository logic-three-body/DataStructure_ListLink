#include<iostream>//Exchange DoubleLinkList Elem

#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct DLNode
{
	ElemType data;
	DLNode *next;
	DLNode *pre;
}DLNode, *DLinkList;

void  CreateNoneCircu_DoubleLink(DLinkList& head) {
	head = (DLinkList)malloc(sizeof(DLNode));//���������һ����㣨��Ԫ��㣩
	head->pre = NULL;
	head->next = NULL;
	head->data = 1;
	DLinkList * list = &head;
	for (int i = 2; i <= 3; i++) {
		//��������ʼ��һ���½��
		DLNode * body = (DLNode*)malloc(sizeof(DLNode));
		body->pre = NULL;
		body->next = NULL;
		body->data = i;

		(*list)->next = body;//ֱ��ǰ������nextָ��ָ���½��
		body->pre = *list;//�½��ָ��ֱ��ǰ�����
		*list = (*list)->next;
	}

}

void CreateCircu_DoubleLink(DLinkList&head, int num)
{
	head = (DLinkList)malloc(sizeof(DLNode));
	DLinkList s, r;
	r = head;
	for (int i = 0; i < num; i++)
	{
		s = (DLinkList)malloc(sizeof(DLNode));
		std::cin>>s->data;
		r->next = s;
		s->pre = r;
		r = s;
	}
	r->next = head;

}
void CreateListTail(DLinkList *L, int n)
{
	DLinkList p, r;
	int i;
	*L = (DLinkList)malloc(sizeof(DLNode)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (DLNode *)malloc(sizeof(DLNode)); /*  �����½�� */
		std::cin >> p->data;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

void ToExchange(DLinkList&L,int num)
{
	if (num==0||num==1)
	{
		return;
	}
	DLinkList now=L->next;
	int i = 0;
	now = L;
	while (now)
	{
		now = now->next;
		i++;
		if (i == num)break;
	}
	DLinkList q = now->pre;
	q->pre->next = now;
	now->pre = q->pre;
	q->next = now->next;
	q->pre = now;
	now->next->pre = q;
	now->next = q;
}

void Output(DLinkList& L, int n)
{
	DLinkList p;
	p = L->next;
	int flag = 1;
	while (n--)
	{
		if (flag)
		{
			flag = 0;
			std::cout << p->data;
		}
		else
			std::cout << " " << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}
int main()
{
	DLinkList test;
	int num,flag;
	std::cin >> num;
	while (num!=0)
	{
	CreateCircu_DoubleLink(test,num);
	std::cin >> flag;
	ToExchange(test,flag);
	Output(test,num);
	std::cin >> num;
	}

	system("pause");
	return 0;
}