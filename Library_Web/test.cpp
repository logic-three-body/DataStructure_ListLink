#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;                 //��������int����ΪStatus
#define MAXSIZE 10000               //ͼ�����ܴﵽ����󳤶� 
typedef struct tagBook              //ͼ����Ϣ����
{
	char book_number[20];                     //ͼ��ISBN
	char book_name[50];                   //ͼ������
	float book_price;                     //ͼ��۸�
}Book;
typedef struct tagSqList            //��������tagSqList�ṹΪSqList
{
	Book *elem;                      //�洢�ռ�Ļ���ַ 
	int length;                      //ͼ����е�ǰͼ����� 
}SqList;                            //ͼ����˳��洢�ṹ����ΪSqList
int main()
{
	char number[20], name[50];           //����no��nameΪchar����
	float price;                    //����priceΪfloat
	Status InitList_Sq(SqList &L);  //��������
	SqList l;                       //����lΪSqList
	InitList_Sq(l);                 //��ʼ��l
	while (cin >> number >> name >> price)     //����no��name��price
	{
		if (!strcmp(number, "0") && !strcmp(name, "0") && price == 0.0)
			break;                  //0 0 0 ʱ����
		Book B;                     //����BΪBook
		strcpy(B.book_number, number);            //�������
		strcpy(B.book_name, name);
		B.book_price = price;
		l.elem[l.length] = B;         //l��elem����洢�����Ϣ
		l.length++;                 //ÿ���һ���飬�������Լ�1,l.length=l.length+1.��Ŀ����
	}
	int n = l.length;                 //����nΪ�������鱾����l.length��ֵ��n
	for (int i = 1; i <= n - 1; i++)         //����Ϊ�鱾������1
	{
		for (int j = 0; j <= n - i; j++)     //��������Ϊ�鱾����������
		{
			if (l.elem[j].book_price < l.elem[j + 1].book_price)//�Ƚϴ�С
			{
				Book B = l.elem[j];   //����BΪBook���ͣ�������ʱ����۸�С�������Ϣ
				l.elem[j] = l.elem[j + 1];//��۸ߵķ�ǰ��
				l.elem[j + 1] = B;      //��������B��ȡ�����С����Ϣ
			}
		}
	}
	for (int i = 0; i < l.length; i++)     //˳�����ÿ�������Ϣ
	{
		cout << l.elem[i].book_number << " " << l.elem[i].book_name << " ";//ÿ������Ϣ
		printf("%.2f\n", l.elem[i].book_price);//������λ����
	}
	return 0;                       //0����ʾ�޴����˳���1����ʾ�쳣�˳���
}
Status InitList_Sq(SqList &L)       //����һ���յ�˳���L
{
	L.elem = new Book[MAXSIZE];       //Ϊ˳������ռ�
	if (!L.elem) exit(OVERFLOW);     //�洢����ʧ��
	L.length = 0;                     //�ձ���Ϊ0
	return OK;                      //OK=1��������
}