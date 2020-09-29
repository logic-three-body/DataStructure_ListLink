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
}*Lib_conductor;
int Linear_Library::len=0;


int main()
{
	Lib_conductor conductor = new Linear_Library[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
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
	std::cout << conductor->GetLibrary_Len() << std::endl;
	for (int i = 0; i<conductor->GetLibrary_Len(); i++)
	{
		conductor[i].Library_OutPut();
	}

	system("pause");
	return 0;
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
