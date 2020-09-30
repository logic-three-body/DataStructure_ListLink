#include<iostream>
#include<string>
#include<iomanip>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;
typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

//定义图书馆结构
typedef struct Linear_Library
{
private:
	std::string book_name;
	std::string book_number;
	float book_price;
	static int len;
public:
	Linear_Library() {};
	Linear_Library(const std::string &nam,
		const std::string&num,
		const double&pric) :
		book_name(nam),
		book_number(num),
		book_price(pric) {};
	Status Library_Insert(const std::string &nam, const std::string&num, const double&pric);
	Status Library_OutPut();
	Status GetLibrary_Len() { return len; };
	double PriceTag() { return book_price; }
	Linear_Library(const Linear_Library&);//拷贝构造函数
	Status FixPrice(double);
}*Lib_conductor;
int Linear_Library::len = 0;

float GetAverage(Lib_conductor L);

//sorting
void Merge(Lib_conductor SR, Lib_conductor TR, int i, int m, int n);
void MergePass(Lib_conductor SR, Lib_conductor TR, int s, int n);
void MergeSort(Lib_conductor L);

/* 交换L中数组r的下标为i和j的值 */
void swap(Linear_Library& a, Linear_Library&b);
void BubbleSort(Lib_conductor L);
void BubbleSort0(Lib_conductor L);
int main()
{
	Lib_conductor conductor = new Linear_Library[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		std::string Book_name;
		std::string Book_number;
		double Book_price;
		std::cin >> Book_number;
		std::cin >> Book_name >> Book_price;//TODO::输入顺序错误
		if (Book_name == "0"&&Book_number == "0"&&Book_price == 0)
		{
			break;
		}
		else
		{
			conductor[i].Library_Insert(Book_name, Book_number, Book_price);
		}

	}
	//BubbleSort0(conductor);
	float averge=GetAverage(conductor);


	std::cout << std::fixed << std::setprecision(2) << averge<<std::endl;
	for (int i = 0; i < conductor->GetLibrary_Len(); i++)
	{
		conductor[i].FixPrice(averge);
		conductor[i].Library_OutPut();
	}

	//system("pause");
	return 0;
}

float GetAverage(Lib_conductor L)
{
	int length = L->GetLibrary_Len();
	float sum=0;
	for (int i = 0; i < length; i++)
	{
		sum += L[i].PriceTag();
	}
	return sum / length ;
}

void Merge(Lib_conductor SR, Lib_conductor TR, int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)	/* 将SR中记录由小到大地并入TR */
	{
		if (SR[i].PriceTag() >= SR[j].PriceTag())
			TR[k] = SR[i++];//TODO 拷贝函数靠谱
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];		/* 将剩余的SR[i..m]复制到TR */
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];		/* 将剩余的SR[j..n]复制到TR */
	}
}

/* 非递归法 */
/* 将SR[]中相邻长度为s的子序列两两归并到TR[] */
void MergePass(Lib_conductor SR, Lib_conductor TR, int s, int n)
{
	int i = 0;
	int j;
	while (i <= n - 2 * s + 1)
	{/* 两两归并 */
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1) /* 归并最后两个序列 */
		Merge(SR, TR, i, i + s - 1, n);
	else /* 若最后只剩下单个子序列 */
		for (j = i; j <= n; j++)
			TR[j] = SR[j];
}

/* 对顺序表L作归并非递归排序 */
void MergeSort(Lib_conductor L)
{
	Lib_conductor TR = new Linear_Library[L->GetLibrary_Len()];/* 申请额外空间 */ //Soulution :"L->GetLibrary_Len()"->"L->GetLibrary_Len()+1"
	int k = 1;
	while (k < L->GetLibrary_Len())
	{
		MergePass(L, TR, k, L->GetLibrary_Len() - 1);
		k = 2 * k;/* 子序列长度加倍 */
		MergePass(TR, L, k, L->GetLibrary_Len() - 1);
		k = 2 * k;/* 子序列长度加倍 */
	}
}

void swap(Linear_Library& a, Linear_Library&b)
{
	Linear_Library temp = a;
	a = b;
	b = temp;
}

/* 对顺序表L作改进冒泡算法 */
void BubbleSort(Lib_conductor L)
{
	int i, j;
	int length = L->GetLibrary_Len();
	Status flag = TRUE;			/* flag用来作为标记 */
	for (i = 0; i < length && flag; i++) /* 若flag为true说明有过数据交换，否则停止循环 */
	{
		flag = FALSE;				/* 初始为False */
		for (j = length - 1; j >= i; j--)
		{
			if (L[j].PriceTag() < L[j + 1].PriceTag())
			{
				swap(L[j], L[j + 1]);	/* 交换L->r[j]与L->r[j+1]的值 */
				flag = TRUE;		/* 如果有数据交换，则flag为true */
			}
		}
	}
}

void BubbleSort0(Lib_conductor L)
{
	int i, j;
	int length = L->GetLibrary_Len();
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length - 1; j++)
		{
			if (L[j].PriceTag() < L[j+1].PriceTag())
			{
				swap(L[j], L[j+1]);/* 交换L->r[i]与L->r[j]的值 */
			}
		}
	}
}

Status Linear_Library::Library_Insert(const std::string &nam, const std::string&num, const double&pric)
{
	book_name = nam;
	book_number = num;
	book_price = pric;
	++len;//长度加一
	return OK;
}

Status Linear_Library::Library_OutPut()
{
	std::cout << std::fixed << std::setprecision(2) << book_number << " " << book_name << " " << book_price << std::endl;
	return OK;
}

Linear_Library::Linear_Library(const Linear_Library &L)
{
	book_name = L.book_name;
	book_number = L.book_number;
	book_price = L.book_price;
}

Status Linear_Library::FixPrice(double aver)
{
	if (book_price<aver)
	{
		book_price *= 1.2;
	}
	else 
	{
		book_price *= 1.1;
	}
	return OK;
}
