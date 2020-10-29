#include<iostream>//List Find Same Str Suffix Back Name 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType;/* ElemType类型根据实际情况而定，这里假设为char */


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

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}



/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(const LinkList& L)
{
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
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

//help:数据结构习题P40
LinkList SameSuffix(LinkList& str1, LinkList&str2)
{
	LinkList long_str = nullptr;
	LinkList short_str = nullptr;
	int diff = 0;//表长差
	int len1= ListLength(str1);
	int len2 = ListLength(str2);

	//找出较长的str，然后让长的ptr先动，直到和短str有相同起点
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

	//较长表先遍历
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
	return nullptr;//无共享后缀
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