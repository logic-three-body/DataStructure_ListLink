#include "list.h"

list::list()
{
	linear_list.length = 0;
	linear_list.data[MAXSIZE] =0 ;
}

list::list(int num)
{
	std::cout << "Input your "<<num<< " elements" << std::endl;
	linear_list.length = num;
	for (int i = 0; i < num ; i++)//Ԫ��
		std::cin >> linear_list.data[i];

	//for (int i = 0; i < num ; i++)
	//	visit(linear_list.data[i]);
}

Status list::ListEmpty()
{
	if (linear_list.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status list::ClearList()
{
	linear_list.length = 0;
	return OK;
}

int list::ListLength()
{
	return linear_list.length;
}

ElemType * list::GetElem( int i)
{
	
	if (linear_list.length == 0 || i<1 || i>linear_list.length)
		return ERROR;
	ElemType *e = new ElemType(linear_list.data[i - 1]);
	//*e = linear_list.data[i - 1];
	//delete e;
	//return OK;
	//delete e;
	return e;
}

int list::LocateElem( ElemType e)
{
	int i;
	if (linear_list.length == 0)
		return 0;
	for (i = 0; i < linear_list.length; i++)
	{
		if (linear_list.data[i] == e)
			break;
	}
	if (i >= linear_list.length)
		return 0;

	return i + 1;
}

Status list::ListInsert(int i, ElemType e)
{
	int k;
	if (linear_list.length == MAXSIZE)  /* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>linear_list.length + 1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i <= linear_list.length)        /* ����������λ�ò��ڱ�β */
	{
		for (k = linear_list.length - 1; k >= i - 1; k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */ //��ʱk��Ӧ���������±�
			linear_list.data[k + 1] = linear_list.data[k];
	}
	linear_list.data[i - 1] = e;          /* ����Ԫ�ز��� */
	linear_list.length++;

	return OK;
}

Status list::ListDelete( int i )
{
	//ElemType * e=nullptr;
	//ElemType * e = (ElemType *) (1);
	
	int k;
	if (linear_list.length == 0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>linear_list.length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	ElemType * e = new ElemType(0);
	*e = linear_list.data[i - 1];
	if (i < linear_list.length)                /* ���ɾ���������λ�� */
	{
		for (k = i; k < linear_list.length; k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			linear_list.data[k - 1] = linear_list.data[k];
	}
	linear_list.length--;
	delete e;
	return OK;
}

Status list::ListTraverse()
{
	int i;
	for (i = 0; i < linear_list.length; i++)
		visit(linear_list.data[i]);
	printf("\n");
	return OK;
}

void list::unionL(list&b)
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength();
	Lb_len = b.ListLength();
	for (i = 1; i <= Lb_len; i++)
	{
		e=*(b.GetElem(i));
		if (!LocateElem(e))
			ListInsert( ++La_len, e);

	}
}
