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
	std::string NamTag() { return book_name; }
	std::string NumTag() { return book_number; }
	Linear_Library(const Linear_Library&);//�������캯��
	Status FixPrice(double);
	void Decrease_Num() { --len; };
}*Lib_conductor;
int Linear_Library::len = 0;

//ȡƽ��ֵ
float GetAverage(Lib_conductor L);

//����
void Inverse(Lib_conductor L);

//�����ͼ��
void MostExpensive(Lib_conductor L);

//��ϲ������
void FindBook(Lib_conductor L,int n);

//��λ��
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(Lib_conductor L,int num);

//����
/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(Lib_conductor L, int i);//iΪ���Ա�λ��

//ɾ��
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(Lib_conductor L, int i)
{
	int k;
	int length = L->GetLibrary_Len();
	if (length == 0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	if (i < length)                /* ���ɾ���������λ�� */
	{
		for (k = i; k < length; k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L[k - 1] = L[k];
	}
	L->Decrease_Num();
	return OK;
}

//ȥ��
void GetRid_Repeat(Lib_conductor L);

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
	int number;
	std::cin >> number;
	Lib_conductor conductor = new Linear_Library[MAXSIZE];
	for (int i = 0; i < number; i++)
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
	Max = L[0].PriceTag();//�������λ���
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
	int count=0;//��¼������
	int length = L->GetLibrary_Len();
	std::string* my_book=new std::string[n];

	int *flag=new int[length];//��¼ԭ�����±�

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
				flag[k] = j;//��¼�±�
				++k;
			}
		}
		if (0==count)
		{
			std::cout << "Sorry��there is no your favourite!" << std::endl;
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
			std::cout << "Sorry��the book on the best position doesn't exist!" << std::endl;
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
	if (length == MAXSIZE)  /* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>length + 1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i <=length)        /* ����������λ�ò��ڱ�β */
	{
		for (k = length - 1; k >= i - 1; k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */ //��ʱk��Ӧ���������±�
			L[k + 1] = L[k];
	}
	std::string Book_name;
	std::string Book_number;
	double Book_price;
	std::cin >> Book_number;
	std::cin >> Book_name >> Book_price;//TODO::����˳�����
	L[i - 1].Library_Insert(Book_name, Book_number, Book_price);

	return OK;
}

void GetRid_Repeat(Lib_conductor L)
{
	int length = L->GetLibrary_Len();
	//MergeSort(L);

	int* pos=new int[length - 1];
	int sum = 0;//�ظ�������
	for (int i = 0; i < length-1; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (L[i].NumTag()==L[j].NumTag())
			{
				++sum;
				pos[sum - 1] = j;//��¼�ظ�λ��
			}
		}
	}
	//ɾ��Ԫ��
	for (int i = 0; i < sum; i++)
	{
		ListDelete(L, pos[i]);
	}

	delete[]pos;
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