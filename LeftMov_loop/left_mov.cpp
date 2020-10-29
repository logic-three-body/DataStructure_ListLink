#include<iostream>//Linear List - Left Circulated Movement

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
Status ListTraverse(ElemType* L, int num)
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

void swap(int&a,int&b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//˼·�����η� ,�ֱ����� ,����ѭ������Ч��
//Help:���ݽṹϰ�⣺P38
void Reverse(int* a,int left,int right)
{
	int i = left, j = right;//���ұ߽�s
	while (i<j)
	{
		swap(a[i],a[j]);
		++i;//����
		--j;//����
	}
}

Status LeftShift(int*a, int len, int pos)
{
	if (!a&&len<=0&&pos<=0)
	{
		return ERROR;
	}
	if (pos>0&&pos<len)
	{
		Reverse(a, 0, len - 1);//��������Ԫ��
		Reverse(a, 0, len - pos - 1);//����n-pԪ��(ǰһ��)
		Reverse(a, len - pos, len - 1);//����pԪ��(��һ��)
	}
	return OK;
}

int main()
{
	ElemType* List = nullptr;
	int num = 0;
	std::cin >> num;
	while (num)
	{
		List = new ElemType[num];
		CreateList(List, num);
		int pos = 0;
		std::cin >> pos;//������������
		LeftShift(List,num,pos);		
		ListTraverse(List,num);
		std::cin >> num;
	}
	return 0;
}