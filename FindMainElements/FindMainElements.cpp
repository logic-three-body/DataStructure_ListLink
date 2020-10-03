#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
#define FAIL -1
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

//Help:���ݽṹϰ��P41
Status MainElement(ElemType*a, int length)
{
	if (!a&&length<=0)
	{
		return ERROR;
	}
	int count = 1;//����
	int key = a[0];//��ѡ��Ԫ��
	for (int i = 0; i < length; ++i)
	{
		if (a[i]==key)
		{
			++count;
		}
		else
		{
			if (count>0)//�Ǻ�ѡ��Ԫ��
			{
				--count;
			}
			else//������ѡ��Ԫ�أ����¼���
			{
				key = a[i];
				count = 1;
			}
		}
	}
	if (count>0)
	{
		count = 0;
		for (int i = 0; i < length; ++i)//ͳ�ƺ�ѡ��Ԫ��ʵ�ʳ��ִ���
		{
			if (a[i]==key)
			{
				++count;
			}
		}
	}
	
	if (count>length/2)//ȷ����Ԫ��
	{
		return key;
	}
	else
	{
		return FAIL;
	}
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
		int main = MainElement(List, num);
		std::cout << main << std::endl;
		std::cin >> num;
	}
	return 0;
}
