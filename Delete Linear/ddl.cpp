#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */


typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */


Status visit(ElemType c)
{
	printf("%d ", c);
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

Status CreateList(SqList *L,int n)
{
	if (n<=0)
	{
		return ERROR;
	}
	L->length = n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> L->data[i];
	}
	return OK;
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
Status ListDelete(SqList *L, int i)
{
	int k;
	if (L->length == 0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	if (i < L->length)                /* ���ɾ���������λ�� */
	{
		for (k = i; k < L->length; k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

Status ListDeleteElem(SqList &L, ElemType e)
{
	if (L.length<=0)
	{
		return ERROR;
	}
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i]==e)
		{
			ListDelete(&L, i + 1);
			--i;//ɾ��������ǰ��iӦ�ȼ����ܼ�����һ��Ԫ��
		}
	}
	return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (i==L.length-1)
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


void Del_item(SqList &L)
{
	int item; int i; int j; int flag[100];
	std::cin >> item;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == item)
		{
			flag[L.data[i]] = 1;
		}
	int s = L.length; int k = 0;
	for (i = 0; i < s; i++)
		if (flag[L.data[i]] != 1)
		{
			//for(j=i;j<L.num-1;j++)//����Ҫ��ѭ�� 
			L.data[k] = L.data[i];
			k++;
			//L.num--;
			//key
		}
	L.length = k;
}


int main()
{
	SqList List;
	InitList(&List);
	int num = 0;
	std::cin >> num;
	while (num)
	{
		CreateList(&List,num);
		int DeleteElem = 0;
		std::cin >> DeleteElem;
		ListDeleteElem(List, DeleteElem);
		ListTraverse(List);
		std::cin >> num;
	}
	return 0;
}