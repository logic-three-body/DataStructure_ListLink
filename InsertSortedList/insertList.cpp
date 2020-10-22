#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为char */


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
typedef struct Node *LinkList; /* 定义LinkList */

/* 初始化顺序线性表 */
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L)) /* 存储分配失败 */
		return ERROR;
	(*L)->next = nullptr; /* 指针域为空 */

	return OK;
}






/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	(*L)->data = n;                     /*头节点记录元素长度*/
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		std::cin >> p->data;
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = nullptr;                       /* 表示当前链表结束 */
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
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

//假设链表为升序
Status SortedListInsert(LinkList&L)//插入新的元素
{

	if (!L && !L->next)
	{
		return ERROR;
	}

	//待插入元素赋值
	ElemType elem;
	std::cin >> elem;
	LinkList NewNode = new Node;
	NewNode->next = nullptr;
	NewNode->data = elem;

	//TODO : 完善Sorted:
	LinkList pNow = L->next;
	LinkList pre = L;
	while (pNow)
	{
		if (NewNode->data <= pNow->data&&pre->data <= NewNode->data)//插入操作 此数必须在某两个数之间
		{
			NewNode->next = pNow;
			pre->next = NewNode;
			break;
		}
		else if (!pNow->next)//已经到最后一位，直接插入
		{
			pNow->next = NewNode;
			break;
		}
		else
		{
			//遍历:
			pre = pre->next;
			pNow = pNow->next;
		}
	}


	++L->data;//更新链表长度

	return OK;

}

Status FrontBackSplit(LinkList&LA,LinkList&LB)//中部分解链表
{
	if (!LA && !LA->next)
	{
		return ERROR;
	}

	int length = LA->data;//获取链表长度
	LinkList flag = LA->next;
	LinkList pre = LA;
	for (int i = 0; i < length/2; i++)//获取居中节点地址
	{
		flag = flag->next;
		pre = pre->next;
	}

	//分割
	LB->next = flag;
	LB->data = (length % 2 == 0) ? (length / 2) : ((length + 1) / 2);
	LA->data = length / 2;
	pre->next = nullptr;
	return OK;
}

int main()
{
	while (true)
	{
		LinkList List;
		InitList(&List);
		int Elem_num;//元素个数
		std::cin >> Elem_num;
		if (!Elem_num)
		{
			break;
		}
		CreateListTail(&List, Elem_num);//尾插法构建链表
		//开始插入元素
		SortedListInsert(List);
		ListTraverse(List);
		//开始分割链表
		LinkList ListB;
		InitList(&ListB);
		FrontBackSplit(List, ListB);
		ListTraverse(List);
		ListTraverse(ListB);
		std::cout << "原表长度 :" << List->data << std::endl;
		std::cout <<"B表长度 :" << ListB->data << std::endl;		
	}

	return 0;
}