#pragma once
#include"global.h"

typedef struct Node
{
	ElemType data;
	struct Node *next;
};
//typedef struct Node *LinkList; /* 定义LinkList */


class link
{
public:
	/* 初始化顺序线性表 */
	 link();
	/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
	Status ListEmpty();
	/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
	Status ClearList();
	/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
	int ListLength();

	/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
   /* 操作结果：用e返回L中第i个数据元素的值 */
	ElemType* GetElem(int i);

	/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
	int LocateElem(ElemType e);
	/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
	Status ListInsert(int i, ElemType e);
	/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
	Status ListDelete(int i, ElemType *e);
	/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
	Status ListTraverse();
	/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
	void CreateListHead( int n);
	/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
	void CreateListTail(int n);



private:
	Node *LinkList;
};

