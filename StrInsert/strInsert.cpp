#include<iostream>
#include<string>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */


typedef char ElemType;        /* ElemType���͸���ʵ������������������Ϊchar */


Status visit(ElemType c)
{
	printf("%c", c);
	return OK;
}

typedef struct
{
	ElemType data[MAXSIZE];        /* ���飬�洢����Ԫ�� */
	int length;                                /* ���Ա�ǰ���� */
}SqList;

/* ��ʼ��˳�����Ա� */
Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(SqList L)
{
	return L.length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			break;
	}
	if (i >= L.length)
		return 0;

	return i + 1;
}


/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList *L, int i, ElemType e)//iΪ���Ա�λ��
{
	int k;
	if (L->length == MAXSIZE)  /* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L->length + 1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i <= L->length)        /* ����������λ�ò��ڱ�β */
	{
		for (k = L->length - 1; k >= i - 1; k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */ //��ʱk��Ӧ���������±�
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          /* ����Ԫ�ز��� */
	L->length++;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)                /* ���ɾ���������λ�� */
	{
		for (k = i; k < L->length; k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (i == L.length - 1)
		{
			std::cout << L.data[i];
		}
		else
		{
			visit(L.data[i]);
		}
	}

	printf("\n");
	return OK;
}

int main()
{
	SqList str;
	std::string insert_str;
	while (true)
	{
		int pos = 0;//����λ��
		int num = 0;
		InitList(&str);
		std::cin >> pos;
		if (!pos)
		{
			break;
		}
		std::cin >> str.data;
		for (int i = 0;str.data[i] !='\0'; i++)
		{
			++num;
		}
		//TODO length
		str.length = num;
		std::cin >> insert_str;
		int len = insert_str.length();
		for (int i=0;i<len;i++,pos++)
		{
			ListInsert(&str,pos,insert_str[i]);
		}
		ListTraverse(str);
	}
	return 0;
}