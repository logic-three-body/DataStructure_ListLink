#include<iostream>
#include<string>
#include<iomanip>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
typedef int Status;
typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */

//����ͼ��ݽṹ
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
	Linear_Library(const Linear_Library&);//�������캯��
	Status FixPrice(double);
}*Lib_conductor;
int Linear_Library::len = 0;

float GetAverage(Lib_conductor L);

//sorting
void Merge(Lib_conductor SR, Lib_conductor TR, int i, int m, int n);
void MergePass(Lib_conductor SR, Lib_conductor TR, int s, int n);
void MergeSort(Lib_conductor L);

/* ����L������r���±�Ϊi��j��ֵ */
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
		std::cin >> Book_name >> Book_price;//TODO::����˳�����
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
	for (j = m + 1, k = i; i <= m && j <= n; k++)	/* ��SR�м�¼��С����ز���TR */
	{
		if (SR[i].PriceTag() >= SR[j].PriceTag())
			TR[k] = SR[i++];//TODO ������������
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];		/* ��ʣ���SR[i..m]���Ƶ�TR */
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];		/* ��ʣ���SR[j..n]���Ƶ�TR */
	}
}

/* �ǵݹ鷨 */
/* ��SR[]�����ڳ���Ϊs�������������鲢��TR[] */
void MergePass(Lib_conductor SR, Lib_conductor TR, int s, int n)
{
	int i = 0;
	int j;
	while (i <= n - 2 * s + 1)
	{/* �����鲢 */
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1) /* �鲢����������� */
		Merge(SR, TR, i, i + s - 1, n);
	else /* �����ֻʣ�µ��������� */
		for (j = i; j <= n; j++)
			TR[j] = SR[j];
}

/* ��˳���L���鲢�ǵݹ����� */
void MergeSort(Lib_conductor L)
{
	Lib_conductor TR = new Linear_Library[L->GetLibrary_Len()];/* �������ռ� */ //Soulution :"L->GetLibrary_Len()"->"L->GetLibrary_Len()+1"
	int k = 1;
	while (k < L->GetLibrary_Len())
	{
		MergePass(L, TR, k, L->GetLibrary_Len() - 1);
		k = 2 * k;/* �����г��ȼӱ� */
		MergePass(TR, L, k, L->GetLibrary_Len() - 1);
		k = 2 * k;/* �����г��ȼӱ� */
	}
}

void swap(Linear_Library& a, Linear_Library&b)
{
	Linear_Library temp = a;
	a = b;
	b = temp;
}

/* ��˳���L���Ľ�ð���㷨 */
void BubbleSort(Lib_conductor L)
{
	int i, j;
	int length = L->GetLibrary_Len();
	Status flag = TRUE;			/* flag������Ϊ��� */
	for (i = 0; i < length && flag; i++) /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
	{
		flag = FALSE;				/* ��ʼΪFalse */
		for (j = length - 1; j >= i; j--)
		{
			if (L[j].PriceTag() < L[j + 1].PriceTag())
			{
				swap(L[j], L[j + 1]);	/* ����L->r[j]��L->r[j+1]��ֵ */
				flag = TRUE;		/* ��������ݽ�������flagΪtrue */
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
				swap(L[j], L[j+1]);/* ����L->r[i]��L->r[j]��ֵ */
			}
		}
	}
}

Status Linear_Library::Library_Insert(const std::string &nam, const std::string&num, const double&pric)
{
	book_name = nam;
	book_number = num;
	book_price = pric;
	++len;//���ȼ�һ
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
