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
public:

	List_Lib *next;

	List_Lib();
	List_Lib(const Data&);
	Status ListInsert(int i, const Data&);
	Status ListInsert(const Data&);
	void Create_Tail_List(int);
	void Lib_OutPut();
	Status GetLibrary_Len() { return len; };
	void sort();
}*Lib_Conductor;
int List_Lib::len = 0;



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
	Lib_Conductor p, r;
	//ͷ�ڵ�泤��
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

int main()
{
	Lib_Conductor conductor = new List_Lib;
	Data book;
	std::cin >> book.book_number >> book.book_name >> book.book_price;
	while (book.book_number!="0"&&book.book_name!="0"&&book.book_price!=0)
	{
		conductor->ListInsert(book);
		std::cin >> book.book_number >> book.book_name >> book.book_price;
	}
	conductor->sort();
	conductor->Lib_OutPut();
	return 0;
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
