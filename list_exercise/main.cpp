#include"list.h"
#include"link.h"
#include<string>
int main()
{
	using namespace std;
/*
	list test1(5),test2(3);
	//std::cout<<test1.ListEmpty();
	//std::cout << test1.ClearList();
	test1.ListTraverse();
	test1.ListDelete(2);
	test1.ListTraverse();
	test1.ListInsert(1, 2);
	test1.ListTraverse();
	test1.unionL(test2);
	test1.ListTraverse();

	//此处留意一下，关于是否要delete
	cout << *(test1.GetElem(2));//OK
	//delete test1.GetElem(2);

*/

	//list test1;
	//cout << *(test1.GetElem(2));//OK
	/*
	int*p = nullptr;
	char*q = nullptr;
	string*s = nullptr;
	int*r = NULL;
	int*u = 0;
	int*a = (int*)1;
	double b = long(2);
	//double*b = (double*)2;
	//cout << *p << *q << *s;
	cout << p << "\t";
	cout <<(int*) q << "\t";
	cout <<(char) r << "\t"; 
	cout << long(a) << "\t";
	cout << char(s) << "\t";
	//cout << *r << "\t";
	//cout << *u << "\t";
	//cout << *a;		
	*/

	link test3,test4;
	test3.CreateListTail(3);
	test4.CreateListHead(3);
	test3.ListTraverse();
	test4.ListTraverse();
	
	


	return 0;
}