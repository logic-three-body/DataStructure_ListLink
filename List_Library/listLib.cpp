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
	void Create_Head_List(int);
	void HeadListInsert(const Data&);
	void Lib_OutPut();
	Status GetLibrary_Len() { return len; };
	void sort();
	float GetAver();
	void FixPrice();
}*Lib_Conductor;
int List_Lib::len = 0;


int main()
{
	Lib_Conductor conductor = new List_Lib;
	int num;
	std::cin >> num;
	conductor->Create_Head_List(num);
	conductor->Lib_OutPut();
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
	int i; //用i记录已经比好，置于末尾的元素 
	int j;//用j记录已比较的轮次 
	Lib_Conductor p=nullptr;
	for (i = 0; i < n - 1; i++)//n个元素要比较n-1轮 
	{
		p = this->next;
		j = 0;//比较完一轮后，j归零 
		while (p&&j < n - 1 - i)//和2轮for循环的本质一样 
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
