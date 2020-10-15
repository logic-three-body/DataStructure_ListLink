#include<iostream>
typedef int ElemType;
const int N = 5;
void swap(ElemType& num1,ElemType& num2)
{
	ElemType tmp =num1;
	num1 = num2;
	num2 = tmp;
}

void Partion(ElemType *Array,int len)
{
	int low = 0, high = len-1;
	while (low<high)
	{
		while (low<high&&0!=Array[low]%2)//ÆæÊý Óöµ½Å¼ÊýÍ£Ö¹
		{
			++low;
		}
		while (low < high && 0 == Array[high] % 2)//Å¼Êý Óöµ½ÆæÊýÍ£Ö¹
		{
			--high;
		}
		// swap
		if (low<high)
		{
			swap(Array[low],Array[high]);
			++low;
			--high;
		}
	}
}

int main()
{
	ElemType A[N] = { 1 ,2 ,3 ,4, 5 };
	Partion(A, N);
	system("pause");
	return 0;
}