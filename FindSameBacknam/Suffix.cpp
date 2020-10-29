#include<iostream>//List Find Same Str Suffix Back Name 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char ElemType;/* ElemType���͸���ʵ������������������Ϊchar */


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
int ListLength(const LinkList& L)
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

//help:���ݽṹϰ��P40
LinkList SameSuffix(LinkList& str1, LinkList&str2)
{
	LinkList long_str = nullptr;
	LinkList short_str = nullptr;
	int diff = 0;//����
	int len1= ListLength(str1);
	int len2 = ListLength(str2);

	//�ҳ��ϳ���str��Ȼ���ó���ptr�ȶ���ֱ���Ͷ�str����ͬ���
	if (len1>len2)
	{
		long_str = str1->next;
		short_str = str2->next;
		diff = len1-len2;
	}
	else
	{
		long_str = str2->next;
		short_str = str1->next;
		diff = len2 - len1;
	}

	//�ϳ����ȱ���
	while (diff--)
	{
		long_str = long_str->next;
	}
	while (long_str)
	{
		if (long_str->data==short_str->data)
		{
			return long_str;
		}
		else
		{
			long_str = long_str->next;
			short_str = short_str->next;
		}
	}
	return nullptr;//�޹����׺
}

int main()
{
	LinkList la, lb;
	InitList(&la);
	InitList(&lb);
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1&&num2)
	{

		CreateListTail(&la, num1);
		CreateListTail(&lb, num2);
		LinkList suffix=SameSuffix(la, lb);
		//ListTraverse(la);
		//std::cout << ListLength(la) << std::endl;
		if (suffix)
		{
			std::cout << suffix->data << std::endl;
		}
		else
		{
			std::cout << "No common suffix\a" << std::endl;
		}
		std::cin >> num1 >> num2;
	}
	return 0;
}