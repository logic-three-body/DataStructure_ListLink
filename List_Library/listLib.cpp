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
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p||j>i)//元素不存在（i=0）
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
	//头节点存长度
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
	std::cout<< conductor->GetLibrary_Len() << std::endl;
	conductor->Lib_OutPut();
	return 0;
}