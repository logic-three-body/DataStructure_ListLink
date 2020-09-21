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
	for (int i = 0; i < num ; i++)//元素
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
	if (linear_list.length == MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>linear_list.length + 1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i <= linear_list.length)        /* 若插入数据位置不在表尾 */
	{
		for (k = linear_list.length - 1; k >= i - 1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */ //此时k对应的是数组下标
			linear_list.data[k + 1] = linear_list.data[k];
	}
	linear_list.data[i - 1] = e;          /* 将新元素插入 */
	linear_list.length++;

	return OK;
}

Status list::ListDelete( int i )
{
	//ElemType * e=nullptr;
	//ElemType * e = (ElemType *) (1);
	
	int k;
	if (linear_list.length == 0)               /* 线性表为空 */
		return ERROR;
	if (i<1 || i>linear_list.length)         /* 删除位置不正确 */
		return ERROR;
	ElemType * e = new ElemType(0);
	*e = linear_list.data[i - 1];
	if (i < linear_list.length)                /* 如果删除不是最后位置 */
	{
		for (k = i; k < linear_list.length; k++)/* 将删除位置后继元素前移 */
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
