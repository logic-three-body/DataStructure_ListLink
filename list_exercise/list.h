#pragma once
//linear
#include"global.h"
typedef struct
{
	ElemType data[MAXSIZE];        /* 数组，存储数据元素 */
	int length;                                /* 线性表当前长度 */
}SqList;

class list
{
public:
	/* 初始化顺序线性表 */
	list();

	/* 创造并初始化顺序线性表 */
    list(int num);//num为创造表时候的元素数量
	/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
	Status ListEmpty();
	/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
	Status ClearList();
	/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
	int ListLength();
	/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
	ElemType * GetElem( int i);
	/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
	int LocateElem(ElemType e);
	/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
	Status ListInsert(int i, ElemType e);//i为线性表位置
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
	Status ListDelete( int i);
	/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
	Status ListTraverse();

	//合并链表
	void unionL(list&);
private:
	SqList linear_list;
	ElemType elem;
	Status status;
};

