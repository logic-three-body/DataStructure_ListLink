#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */


typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */


Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}


/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(ElemType* L,int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (i == num - 1)
		{
			std::cout << L[i];
		}
		else
		{
			visit(L[i]);
		}
	}

	printf("\n");
	return OK;
}

Status CreateList(ElemType *L, int n)
{
	if (n <= 0)
	{
		return ERROR;
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> L[i];
	}
	return OK;
}

//Help:���ݽṹϰ��P39
ElemType FindMid(ElemType*a, ElemType*b, int n)
{
	int start1 = 0, end1 = n-1;
	int start2 = 0, end2 = n-1;
	int mid1 = 0, mid2 = 0;
	while (start1!=end1||start2!=end2)
	{
		mid1 = (start1 + end1) / 2;
		mid2 = (start2 + end2) / 2;
		if (a[mid1]==b[mid2])//��λ�����
		{
			return a[mid1];
		}
		//������ż
		else if (a[mid1]<b[mid2])
		{
			if ((start1+end1)%2==0)//ż��������Aǰ������B��
			{
				start1 = mid1;
				end2 = mid2;
			}
			else
			{
				start1 = mid1 + 1;
				end2 = mid2;
			}
		}
		else
		{
			if ((start1 + end1) % 2 == 0)//ż��������Aǰ������B��
			{
				end1 = mid1;
				start2 = mid2;
			}
			else
			{
				end1 = mid1 ;
				start2 = mid2+1;
			}
		}
	}
	return a[start1] < b[start2] ? a[start1] : b[start2];
}

int main()
{
	ElemType* List1=nullptr,*List2=nullptr;
	int num = 0;
	std::cin >> num;
	while (num)
	{
		List1 = new ElemType[num];
		List2 = new ElemType[num];
		CreateList(List1, num);
		CreateList(List2, num);
		int mid = FindMid(List1,List2,num);
		std::cout << mid << std::endl;
		std::cin >> num;
	}
	return 0;
}