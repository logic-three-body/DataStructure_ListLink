#define _CRT_SECURE_NO_WARNINGS //put in first line
#include "stdio.h"
#include "malloc.h"
#include "time.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct Node {
	ElemType data; //数据域
	struct Node *next; //指针域
} LinkList;

// 初始化线性表
LinkList* InitList(LinkList *L, int n) {

	LinkList *p, *r;

	if (n == 0)
	{
		return ERROR;
	}

	L = (LinkList*)malloc(sizeof(Node));
	srand(time(0)); //生成随机种子 作为初始的data
	L->data = rand() % 100;
	L->next = NULL; //头节点 Next域置空
	r = L;
	for (int i = 1; i <= n; i++)
	{
		p = (LinkList*)malloc(sizeof(Node)); //生成新节点
		p->data = i;
		r->next = p; //上一个节点的地址指向新节点
		r = p;
	}
	r->next = L->next;  //最后一个节点的地址指向头节点
	return L;
}


// 链表遍历到开始位置
LinkList* ListStart(LinkList *L, int n) {

	for (int i = 0; i < n; i++)
	{
		L = L->next; //通过不断地指向下一个节点找到开始节点的位置
	}
	return L;

}


//循环删除节点
Status ListDelete(LinkList *L, int n) {

	LinkList *q;

	do
	{
		for (int i = 1; i < n; i++) //固定步长
		{
			if (i > 1)
			{
				L = L->next;
			}

		}
		q = L->next;
		L->next = L->next->next;
		free(q); //释放节点
		// p=L->next;
		L = L->next;
	} while (L != L->next); //最后一个节点 停止循环

	printf("最后一个人是 %d", L->data);
	return OK;
}


int main() {

	int total, start, n;
	LinkList *L=NULL, *Head = NULL, *Circle;

	while (!Head)
	{
		printf("请输入总人数:");
		scanf("%d", &total);
		Head = InitList(L, total);
		if (!Head)
		{
			printf("程序出错！请重试！\n");
		}
	}

	do
	{
		printf("请输入开始位置编号:");
		scanf("%d", &start);
		if (start > total || start < 1)
		{
			printf("超过总人数%d，请重试！\n", total);
		}
	} while (start > total || start < 1);

	do
	{
		printf("请输入步长:");
		scanf("%d", &n);
		if (n > total || n < 1)
		{
			printf("输入有误！请重新输入！\n");
		}

	} while (n > total || n < 1);

	Circle = ListStart(Head, start);

	ListDelete(Circle, n);

	return 0;

}