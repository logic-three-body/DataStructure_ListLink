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
	double book_price;
	static int len;
public:
	Linear_Library() {};
	Linear_Library(const std::string &nam,
				   const std::string&num,
				   const double&pric):
									book_name(nam), 
									book_number(num), 
									book_price(pric){};
	Status Library_Insert(const std::string &nam, const std::string&num, const double&pric);
	Status Library_OutPut();
    Status GetLibrary_Len() { return len; };
	double PriceTag() { return book_price; }
	Linear_Library(const Linear_Library&);//拷贝构造函数
}*Lib_conductor;
int Linear_Library::len=0;

//sorting
void Merge(Lib_conductor SR, Lib_conductor TR, int i, int m, int n);
void MergePass(Lib_conductor SR, Lib_conductor TR, int s, int n);
void MergeSort(Lib_conductor L);
int main()
{
	Lib_conductor conductor = new Linear_Library[MAXSIZE];
	for (int i = 1; i < MAXSIZE; i++)
	{
		std::string Book_name;
		std::string Book_number;
		double Book_price;
		std::cin >> Book_number;
		std::cin>> Book_name >> Book_price;//TODO::输入顺序错误
		if (Book_name=="0"&&Book_number=="0"&&Book_price==0)
		{
			break;
		}
		else
		{
		conductor[i].Library_Insert(Book_name, Book_number, Book_price);
		}

	}
	MergeSort(conductor);

	for (int i = 1; i<=conductor->GetLibrary_Len(); i++)
	{
		conductor[i].Library_OutPut();
	}

	system("pause");
	return 0;
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
	int i = 1;
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
	Lib_conductor TR = new Linear_Library[L->GetLibrary_Len()+1];/* 申请额外空间 */ //Soulution :"L->GetLibrary_Len()"->"L->GetLibrary_Len()+1"
	int k = 1;
	while (k < L->GetLibrary_Len())
	{
		MergePass(L, TR, k, L->GetLibrary_Len());
		k = 2 * k;/* 子序列长度加倍 */
		MergePass(TR, L, k, L->GetLibrary_Len());
		k = 2 * k;/* 子序列长度加倍 */
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
	std::cout<<std::fixed <<std::setprecision(2) << book_number << " " << book_name << " " << book_price<<std::endl;
	return OK;
}

Linear_Library::Linear_Library(const Linear_Library &L)
{
	book_name = L.book_name;
	book_number = L.book_number;
	book_price = L.book_price;
}
