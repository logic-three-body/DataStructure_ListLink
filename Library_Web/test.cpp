#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define OK 1


#define Maxsize 100
#define OVERFLOW -1


using namespace std;
typedef int Status;                 //��������int����ΪStatus
typedef struct
{
	char no[20];                     //ͼ��ISBN
	char name[50];                   //ͼ������
	float price;                     //ͼ��۸�
}Book;
typedef struct
{
	Book  *elem;//ָ������Ԫ�صĻ���ַ
	int length;//���Ա�ĵ�ǰ����
}SqList;       //����˳��洢�ṹ����ΪSqList
int main()
{
	Status InitList(SqList &L);  //��������
	Status PrintList_Sq(SqList &L); //��������
	Status CreationList_Sq(SqList &L, char *no, char *name, float &price);//��������
	SqList L;                       //����LΪSqList
	InitList(L);                    //��ʼ��L
	char no[20], name[50];           //����no��nameΪchar����
	float price;                    //����priceΪfloat
	int i = 0;
	while (1)     //����no��name��price
	{
		cin >> no >> name >> price;
		if (*no == '0'&&*name == '0'&&price == 0) { break; }
		CreationList_Sq(L, no, name, price);//��������Ϣ
		++i;
	}
	PrintList_Sq(L);
	return 0;
}
Status InitList(SqList &L)
{
	L.elem = new Book[Maxsize];   //Ϊ˳������洢�ռ�
	if (!L.elem) exit(OVERFLOW);   //�洢����ʧ��
	L.length = 0;         //�ձ���Ϊ0
	return OK;
}
Status CreationList_Sq(SqList &L, char *no, char *name, float &price)
{
	Book B;                     //����BΪBook
	strcpy(B.no, no);            //�������
	strcpy(B.name, name);
	B.price = price;
	L.elem[L.length] = B;         //l��elem����洢�����Ϣ
	L.length++;                 //ÿ���һ���飬�������Լ�1,l.length=l.length+1.��Ŀ����
	return OK;                      //OK=1��������
}
Status PrintList_Sq(SqList &L)
{
	int n = L.length;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			if (L.elem[j].price < L.elem[j + 1].price)
			{
				Book B = L.elem[j];   //����BΪBook���ͣ�������ʱ����۸�С�������Ϣ
				L.elem[j] = L.elem[j + 1];//��ܵ׵��ں���
				L.elem[j + 1] = B;      //��������B��ȡ�����С����Ϣ
			}
		}
	}
	for (int i = 0; i < L.length; i++)     //˳�����ÿ�������Ϣ
	{
		cout << L.elem[i].no << " " << L.elem[i].name << " ";//ÿ������Ϣ
		printf("%.2f\n", L.elem[i].price);//������λ����
	}
	return OK;                      //OK=1��������
}
