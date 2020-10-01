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
struct Data
{
	std::string book_name;
	std::string book_number;
	float book_price;
};
typedef struct List_Lib
{
private:
	Data Books;
	static int len;
	Data GetBook(int);
public:

	List_Lib *next;

	List_Lib();
	List_Lib(const Data&);
	Status ListInsert(int i, const Data&);
	Status ListInsert(const Data&);
	void Create_Tail_List(int);
	void Create_Head_List(int);
	void HeadListInsert(const Data&);
	void Lib_OutPut();
	Status GetLibrary_Len() { return len; };
	void sort();
	float GetAver();
	void FixPrice();
	void FindExpen();
}*Lib_Conductor;
int List_Lib::len = 0;


int main()
{
	Lib_Conductor conductor = new List_Lib;
	int num;
	std::cin >> num;
	conductor->Create_Tail_List(num);
	//conductor->Lib_OutPut();
	conductor->FindExpen();
	return 0;
}






List_Lib::List_Lib():next(nullptr)
{
	
}

List_Lib::List_Lib(const Data &book):next(nullptr)
{
	Books.book_number = book.book_number;
	Books.book_name = book.book_name;
	Books.book_price = book.book_price;
}

Status List_Lib::ListInsert(int i,const Data&b)
{
	int j;
	Lib_Conductor p, s;
	p = this;
	j = 1;
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p||j>i)//Ԫ�ز����ڣ�i=0��
	{
		return ERROR;
	}
	s = new List_Lib(b);
	p->next = s;
	return OK;

}

Status List_Lib::ListInsert(const Data &b)
{
	++len;
	ListInsert(len,b);
	return OK;
}

void List_Lib::Create_Tail_List(int n)
{
	Data book;
	for (int i = 0; i < n; i++)
	{
		std::cin >> book.book_number >> book.book_name >> book.book_price;
		ListInsert(book);
	}
}

void List_Lib::Create_Head_List(int n)
{
	Data book;
	for (int i = 0; i < n; i++)
	{
		std::cin >> book.book_number >> book.book_name >> book.book_price;
		HeadListInsert(book);
	}
}

void List_Lib::HeadListInsert(const Data &b)
{
	++len;
	Lib_Conductor p=new List_Lib(b);
	p->next = this->next;
	this->next = p;
}

void List_Lib::Lib_OutPut()
{
	Lib_Conductor p = this->next;
	while (p)
	{
		std::cout << std::fixed << std::setprecision(2) << p->Books.book_number << " " << p->Books.book_name << " " << p->Books.book_price << std::endl;
		p = p->next;
	}
}




void  List_Lib::sort()
{

	int n = this->len;
	int i; //��i��¼�Ѿ��Ⱥã�����ĩβ��Ԫ�� 
	int j;//��j��¼�ѱȽϵ��ִ� 
	Lib_Conductor p=nullptr;
	for (i = 0; i < n - 1; i++)//n��Ԫ��Ҫ�Ƚ�n-1�� 
	{
		p = this->next;
		j = 0;//�Ƚ���һ�ֺ�j���� 
		while (p&&j < n - 1 - i)//��2��forѭ���ı���һ�� 
		{
			if (p->Books.book_price < p->next->Books.book_price)
			{
				Data tmp = p->Books;
				p->Books = p->next->Books;
				p->next->Books = tmp;
			}
			p = p->next;
			j++;
		}
	}

}

float List_Lib::GetAver()
{
	int len = this->len;
	float sum = 0;
	if (!len)
	{
		return ERROR;
	}
	Lib_Conductor p = this->next;
	while (p)
	{
		sum += p->Books.book_price;
		p = p->next;
	}
	return sum/len;
}

void List_Lib::FixPrice()
{
	float average = this->GetAver();
	Lib_Conductor p = this->next;
	while (p)
	{
		if (p->Books.book_price<average)
		{
			p->Books.book_price *= 1.2;			
		}
		else
		{
			p->Books.book_price *= 1.1;
		}
		p = p->next;
	}
}

void List_Lib::FindExpen()
{
	int Expen_num = 0;
	int length = GetLibrary_Len();
	float Max = 0;
	sort();
	Max = this->next->Books.book_price;
	Lib_Conductor p = this->next;
	while (p)
	{
		if (Max>p->Books.book_price)
		{
			break;
		}
		else
		{
			++Expen_num;
		}
		p = p->next;
	}
	std::cout << Expen_num << std::endl;
	p = this->next;
	for (int i = 0; i < Expen_num; i++,p = p->next)
	{
		std::cout << std::fixed << std::setprecision(2) << p->Books.book_number << " " << p->Books.book_name << " " << p->Books.book_price << std::endl;		
	}

}

Data List_Lib::GetBook(int i)
{
	int j;
	Lib_Conductor p;		/* ����һ���p */
	p = this->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j < i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	Data book = p->Books;   /*  ȡ��i��Ԫ�ص����� */
	return book;
}
