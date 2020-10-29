#include <iostream>//Delete ABS Node
#include<cmath>
#include<string.h>//For metset
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

const int FIND = 1;

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  生成新结点 */
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

Status DeleEquaAbs(LinkList& L,int num)
{
	if (!L&&!L->next)
	{
		return ERROR;
	}
	int *t =new int[num + 1];//不用0号单元
	memset(t,0,num+1);//数组清0
	LinkList p = L->next;
	LinkList pre = L;
	LinkList tmp = nullptr;
	while (p)
	{
		if (FIND==t[abs(p->data)])//已出现过
		{
			pre->next = p->next;
			tmp = p;
			p = p->next;
			delete tmp;
		}
		else
		{
			t[abs(p->data)] = FIND;
			pre = p;
			p = p->next;
		}
	}
	return OK;

}

int main()
{
	LinkList la;
	InitList(la);
	int num;
	std::cin >> num;
	while (num)
	{
		CreateListTail(&la, num);
		DeleEquaAbs(la,num);
		ListTraverse(la);
		std::cin >> num;
	}
	return 0;
}
