#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;                 //声明类型int类型为Status
#define MAXSIZE 10000               //图书表可能达到的最大长度 
typedef struct tagBook              //图书信息定义
{
	char book_number[20];                     //图书ISBN
	char book_name[50];                   //图书名字
	float book_price;                     //图书价格
}Book;
typedef struct tagSqList            //声明类型tagSqList结构为SqList
{
	Book *elem;                      //存储空间的基地址 
	int length;                      //图书表中当前图书个数 
}SqList;                            //图书表的顺序存储结构类型为SqList
int main()
{
	char number[20], name[50];           //定义no，name为char数组
	float price;                    //定义price为float
	Status InitList_Sq(SqList &L);  //声明函数
	SqList l;                       //定义l为SqList
	InitList_Sq(l);                 //初始化l
	while (cin >> number >> name >> price)     //输入no、name、price
	{
		if (!strcmp(number, "0") && !strcmp(name, "0") && price == 0.0)
			break;                  //0 0 0 时结束
		Book B;                     //定义B为Book
		strcpy(B.book_number, number);            //复制书号
		strcpy(B.book_name, name);
		B.book_price = price;
		l.elem[l.length] = B;         //l的elem数组存储书的信息
		l.length++;                 //每存好一本书，书总量自加1,l.length=l.length+1.单目运算
	}
	int n = l.length;                 //定义n为整数，书本总数l.length赋值给n
	for (int i = 1; i <= n - 1; i++)         //趟数为书本总数减1
	{
		for (int j = 0; j <= n - i; j++)     //交换次数为书本总数减趟数
		{
			if (l.elem[j].book_price < l.elem[j + 1].book_price)//比较大小
			{
				Book B = l.elem[j];   //定义B为Book类型，用于暂时存书价格小的书的信息
				l.elem[j] = l.elem[j + 1];//书价高的放前面
				l.elem[j + 1] = B;      //后面的书从B里取回书价小的信息
			}
		}
	}
	for (int i = 0; i < l.length; i++)     //顺序输出每本书的信息
	{
		cout << l.elem[i].book_number << " " << l.elem[i].book_name << " ";//每本书信息
		printf("%.2f\n", l.elem[i].book_price);//保留两位消暑
	}
	return 0;                       //0：表示无错误退出。1：表示异常退出。
}
Status InitList_Sq(SqList &L)       //构造一个空的顺序表L
{
	L.elem = new Book[MAXSIZE];       //为顺序表分配空间
	if (!L.elem) exit(OVERFLOW);     //存储分配失败
	L.length = 0;                     //空表长度为0
	return OK;                      //OK=1，返回真
}