#include<iostream>//Linear List Library System
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
	std::string NamTag() { return book_name; }
	std::string NumTag() { return book_number; }
	Linear_Library(const Linear_Library&);//拷贝构造函数
	Status FixPrice(double);
	void Decrease_Num() { --len; };
}*Lib_conductor;
int Linear_Library::len = 0;

//取平均值
float GetAverage(Lib_conductor L);

//逆序
void Inverse(Lib_conductor L);

//找最贵图书
void MostExpensive(Lib_conductor L);

//找喜爱的书
void FindBook(Lib_conductor L,int n);

//找位置
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(Lib_conductor L,int num);

//插入
/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(Lib_conductor L, int i);//i为线性表位置

//删除
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(Lib_conductor L, int i)
{
	int k;
	int length = L->GetLibrary_Len();
	if (length == 0)               /* 线性表为空 */
		return ERROR;
	if (i<1 || i>length)         /* 删除位置不正确 */
		return ERROR;
	if (i < length)                /* 如果删除不是最后位置 */
	{
		for (k = i; k < length; k++)/* 将删除位置后继元素前移 */
			L[k - 1] = L[k];
	}
	L->Decrease_Num();
	return OK;
}

//去重
void GetRid_Repeat(Lib_conductor L);

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
	int number;
	std::cin >> number;
	Lib_conductor conductor = new Linear_Library[MAXSIZE];
	for (int i = 0; i < number; i++)
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

	GetRid_Repeat(conductor);


	std::cout << conductor->GetLibrary_Len() << std::endl;
	for (int i = 0; i < conductor->GetLibrary_Len(); i++)
	{
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

void Inverse(Lib_conductor L)
{
	int length = L->GetLibrary_Len();
	for (int i = 0; i < (length+1)/2; i++)
	{
		Linear_Library Tmp;
		Tmp = L[i];
		L[i] = L[length - i - 1];
		L[length - i - 1] = Tmp;
	}
}

void MostExpensive(Lib_conductor L)
{
	int Expen_num = 0;
	int length = L->GetLibrary_Len();
	float Max = 0;
	MergeSort(L);
	Max = L[0].PriceTag();//排序后首位最大
	for (int i = 0; i < length; i++)
	{

		if (Max > L[i].PriceTag())
		{
			break;
		}
		else
		{
			++Expen_num;
		}
	}

	std::cout << Expen_num << std::endl;

	for (int i = 0; i < Expen_num; i++)
	{
		L[i].Library_OutPut();
	}

}

void FindBook(Lib_conductor L,int n)
{
	if (n==0)
	{
		return;
	}
	int count=0;//记录书数量
	int length = L->GetLibrary_Len();
	std::string* my_book=new std::string[n];

	int *flag=new int[length];//记录原数组下标

	for (int i = 0; i < n; i++)
	{
		std::cin >> my_book[i];
	}


	for (int i = 0, k = 0; i < n; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (L[j].NamTag() == my_book[i])
			{
				++count;
				flag[k] = j;//记录下标
				++k;
			}
		}
		if (0==count)
		{
			std::cout << "Sorry，there is no your favourite!" << std::endl;
		}
		else
		{
			std::cout << count << std::endl;
			for (int t = 0; t < count; t++)
			{
				L[flag[t]].Library_OutPut();
			}
		}
	}

	delete[] my_book;

	delete[] flag;
}

Status GetElem(Lib_conductor L, int num)
{
	int len = L->GetLibrary_Len();
	if (len==0)
	{
		return ERROR;
	}
	for (int t = 0; t < num; t++)
	{
		int search_index = 0;//
		std::cin >> search_index;
		if (search_index<1 || search_index>len)
		{
			std::cout << "Sorry，the book on the best position doesn't exist!" << std::endl;
		}
		else
		{
			L[search_index - 1].Library_OutPut();
		}
	}

	return OK;
}

Status ListInsert(Lib_conductor L, int i)
{
	int k;
	int length = L->GetLibrary_Len();
	if (length == MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>length + 1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i <=length)        /* 若插入数据位置不在表尾 */
	{
		for (k = length - 1; k >= i - 1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */ //此时k对应的是数组下标
			L[k + 1] = L[k];
	}
	std::string Book_name;
	std::string Book_number;
	double Book_price;
	std::cin >> Book_number;
	std::cin >> Book_name >> Book_price;//TODO::输入顺序错误
	L[i - 1].Library_Insert(Book_name, Book_number, Book_price);

	return OK;
}

void GetRid_Repeat(Lib_conductor L)
{
	int length = L->GetLibrary_Len();
	//MergeSort(L);

	int* pos=new int[length - 1];
	int sum = 0;//重复的数量
	for (int i = 0; i < length-1; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (L[i].NumTag()==L[j].NumTag())
			{
				++sum;
				pos[sum - 1] = j;//记录重复位置
			}
		}
	}
	//删除元素
	for (int i = 0; i < sum; i++)
	{
		ListDelete(L, pos[i]);
	}

	delete[]pos;
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
