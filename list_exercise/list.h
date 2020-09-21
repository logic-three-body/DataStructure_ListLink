#pragma once
//linear
#include"global.h"
typedef struct
{
	ElemType data[MAXSIZE];        /* ���飬�洢����Ԫ�� */
	int length;                                /* ���Ա�ǰ���� */
}SqList;

class list
{
public:
	/* ��ʼ��˳�����Ա� */
	list();

	/* ���첢��ʼ��˳�����Ա� */
    list(int num);//numΪ�����ʱ���Ԫ������
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	Status ListEmpty();
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
	Status ClearList();
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
	int ListLength();
	/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
	ElemType * GetElem( int i);
	/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
	int LocateElem(ElemType e);
	/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
	Status ListInsert(int i, ElemType e);//iΪ���Ա�λ��
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
	Status ListDelete( int i);
	/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
	Status ListTraverse();

	//�ϲ�����
	void unionL(list&);
private:
	SqList linear_list;
	ElemType elem;
	Status status;
};

