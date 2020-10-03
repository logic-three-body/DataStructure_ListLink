#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
#define FAIL -1
typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */

const int succeed = 0;//���ֳɹ�
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
	for (i = 0; i < num; ++i)
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
	for (int i = 0; i < n; ++i)
	{
		std::cin >> L[i];
	}
	return OK;
}

void swap(int&a, int&b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int Partition(ElemType *L, int& low, int& high)
{
	int pivotkey;

	pivotkey = L[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while (low < high) /*  �ӱ�����˽�������м�ɨ�� */
	{
		while (low < high&&L[high] >= pivotkey)
			high--;
		swap(L[low], L[high]);/* ���������¼С�ļ�¼�������Ͷ� */
		while (low < high&&L[low] <= pivotkey)
			low++;
		swap(L[low], L[high]);/* ���������¼��ļ�¼�������߶� */
	}
	return low; /* ������������λ�� */
}

Status DivArray_QS(ElemType*a, int length, ElemType*A1, ElemType*A2)
{
	if (!a&&length <= 0)
	{
		return ERROR;
	}

	int low = 0, high = length - 1;//���½�
	int low_new = 0, high_new = length - 1;//�±����½�
	int sum1 = 0, sum2 = 0;//A1,A2Ԫ�غ�
	int flag = OK;//�����Ƿ�ɹ�
	int mid = length / 2;//���м�λ��
	while (flag)
	{
		low = Partition(a,low,high);//TODO:IF CORRECT?

		if (low == mid - 1)//���ֳɹ�
		{
			flag = succeed;
		}
		else
		{
			if (low < mid - 1)
			{
				low_new = ++low;
				high = high_new;
			}
			else
			{
				high_new = --high;
				low = low_new;
			}
		}
	}
	A1 = new ElemType[mid];
	for (int i = 0; i < mid; i++)
	{
		A1[i] = a[i];

	}
	ListTraverse(A1, mid);
	A2 = new ElemType[length - mid];
	for (int i = mid, k = 0; i < length; ++i, ++k)
	{
		A2[k] = a[i];
	}
	ListTraverse(A2, length - mid);
	return OK;
}

//TODO:AC����һ��partion����
//Help:���ݽṹϰ��P43 QucikSort
//�ǵݹ鷨�������򣨵�����
Status DivArray(ElemType*a, int length,ElemType*A1,ElemType*A2)
{
	if (!a&&length<=0)
	{
		return ERROR;
	}
	int low = 0, high = length - 1;//���½�
	int low_new = 0, high_new = length - 1;//�±����½�
	int sum1 = 0, sum2 = 0;//A1,A2Ԫ�غ�
	int flag = OK;//�����Ƿ�ɹ�
	int mid = length / 2;//���м�λ��
	while (flag)
	{
		int pivot_key = a[low];//ѡ����Ŧ

		
		while (low < high)//�����˽�������м�ɨ��
		{
			while (low < high&&a[high] >= pivot_key)
			{
				--high;//����������������
			}
			if (low != high)
			{
				a[low] = a[high];//��ŦС�ļ�¼���Ͷ�
			}
			while (low < high&&a[low] <= pivot_key)
			{
				++low;
			}
			if (low != high)
			{
				a[high] = a[low];//��Ŧ��ļ�¼���߶�
			}
		}
		a[low] = pivot_key;//��¼��Ŧ
		if (low==mid-1)//���ֳɹ�
		{
			flag =succeed;
		}
		else
		{
			if (low<mid-1)
			{
				low_new = ++low;
				high = high_new;
			}
			else
			{
				high_new = --high;
				low = low_new;
			}
		}

	}// end of while (low<high)
	A1 = new ElemType[mid];
	for (int i = 0; i < mid; i++)
	{
		A1[i] = a[i];
		
	}
	ListTraverse(A1, mid);
	A2 = new ElemType[length - mid];
	for (int i = mid,k=0; i < length; ++i,++k)
	{
		A2[k] = a[i];
	}
	ListTraverse(A2, length - mid);
	return OK;
}

int main()
{
	ElemType* List = nullptr;
	ElemType *a1=nullptr, *a2=nullptr;
	int num = 0;
	std::cin >> num;
	while (num)
	{
		List = new ElemType[num];
		CreateList(List, num);
		//DivArray(List, num,a1,a2);
		DivArray_QS(List, num, a1, a2);
		ListTraverse(List, num);
		std::cin >> num;
	}
	return 0;
}

