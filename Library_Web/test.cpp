#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define OK 1


#define Maxsize 100
#define OVERFLOW -1


using namespace std;
typedef int Status;                 //声明类型int类型为Status
typedef struct
{
	char no[20];                     //图书ISBN
	char name[50];                   //图书名字
	float price;                     //图书价格
}Book;
typedef struct
{
	Book  *elem;//指向数据元素的基地址
	int length;//线性表的当前长度
}SqList;       //他的顺序存储结构类型为SqList
int main()
{
	Status InitList(SqList &L);  //声明函数
	Status PrintList_Sq(SqList &L); //声明函数
	Status CreationList_Sq(SqList &L, char *no, char *name, float &price);//声明函数
	SqList L;                       //定义L为SqList
	InitList(L);                    //初始化L
	char no[20], name[50];           //定义no，name为char数组
	float price;                    //定义price为float
	int i = 0;
	while (1)     //输入no、name、price
	{
		cin >> no >> name >> price;
		if (*no == '0'&&*name == '0'&&price == 0) { break; }
		CreationList_Sq(L, no, name, price);//存入书信息
		++i;
	}
	PrintList_Sq(L);
	return 0;
}
Status InitList(SqList &L)
{
	L.elem = new Book[Maxsize];   //为顺序表分配存储空间
	if (!L.elem) exit(OVERFLOW);   //存储分配失败
	L.length = 0;         //空表长度为0
	return OK;
}
Status CreationList_Sq(SqList &L, char *no, char *name, float &price)
{
	Book B;                     //定义B为Book
	strcpy(B.no, no);            //复制书号
	strcpy(B.name, name);
	B.price = price;
	L.elem[L.length] = B;         //l的elem数组存储书的信息
	L.length++;                 //每存好一本书，书总量自加1,l.length=l.length+1.单目运算
	return OK;                      //OK=1，返回真
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
				Book B = L.elem[j];   //定义B为Book类型，用于暂时存书价格小的书的信息
				L.elem[j] = L.elem[j + 1];//书架底的在后面
				L.elem[j + 1] = B;      //后面的书从B里取回书价小的信息
			}
		}
	}
	for (int i = 0; i < L.length; i++)     //顺序输出每本书的信息
	{
		cout << L.elem[i].no << " " << L.elem[i].name << " ";//每本书信息
		printf("%.2f\n", L.elem[i].price);//保留两位消暑
	}
	return OK;                      //OK=1，返回真
}
