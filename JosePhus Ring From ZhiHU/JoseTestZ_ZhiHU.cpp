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
	ElemType data; //������
	struct Node *next; //ָ����
} LinkList;

// ��ʼ�����Ա�
LinkList* InitList(LinkList *L, int n) {

	LinkList *p, *r;

	if (n == 0)
	{
		return ERROR;
	}

	L = (LinkList*)malloc(sizeof(Node));
	srand(time(0)); //����������� ��Ϊ��ʼ��data
	L->data = rand() % 100;
	L->next = NULL; //ͷ�ڵ� Next���ÿ�
	r = L;
	for (int i = 1; i <= n; i++)
	{
		p = (LinkList*)malloc(sizeof(Node)); //�����½ڵ�
		p->data = i;
		r->next = p; //��һ���ڵ�ĵ�ַָ���½ڵ�
		r = p;
	}
	r->next = L->next;  //���һ���ڵ�ĵ�ַָ��ͷ�ڵ�
	return L;
}


// �����������ʼλ��
LinkList* ListStart(LinkList *L, int n) {

	for (int i = 0; i < n; i++)
	{
		L = L->next; //ͨ�����ϵ�ָ����һ���ڵ��ҵ���ʼ�ڵ��λ��
	}
	return L;

}


//ѭ��ɾ���ڵ�
Status ListDelete(LinkList *L, int n) {

	LinkList *q;

	do
	{
		for (int i = 1; i < n; i++) //�̶�����
		{
			if (i > 1)
			{
				L = L->next;
			}

		}
		q = L->next;
		L->next = L->next->next;
		free(q); //�ͷŽڵ�
		// p=L->next;
		L = L->next;
	} while (L != L->next); //���һ���ڵ� ֹͣѭ��

	printf("���һ������ %d", L->data);
	return OK;
}


int main() {

	int total, start, n;
	LinkList *L=NULL, *Head = NULL, *Circle;

	while (!Head)
	{
		printf("������������:");
		scanf("%d", &total);
		Head = InitList(L, total);
		if (!Head)
		{
			printf("������������ԣ�\n");
		}
	}

	do
	{
		printf("�����뿪ʼλ�ñ��:");
		scanf("%d", &start);
		if (start > total || start < 1)
		{
			printf("����������%d�������ԣ�\n", total);
		}
	} while (start > total || start < 1);

	do
	{
		printf("�����벽��:");
		scanf("%d", &n);
		if (n > total || n < 1)
		{
			printf("�����������������룡\n");
		}

	} while (n > total || n < 1);

	Circle = ListStart(Head, start);

	ListDelete(Circle, n);

	return 0;

}