#include <stdio.h>
#include<stdlib.h>
#include<iostream>
// ��һ�ֲ��뷽ʽ�� �Ȱ�s��pos�Ժ���ַ������ӵ�t�ϣ�Ȼ���ڽ�t���뵽s��posλ��
void insert(char *s, char *t, int pos)
{
	char *p = s, *q = t;
	int i = 0, lent = 0;
	if (pos < 1)
	{
		printf("λ�ò�����\n");
		exit(0);
	}
	while (*p&&i < pos - 1)
	{
		p++;
		i++;
	}
	if (*p == '\0')
	{
		printf("λ�ò�����\n");
		exit(0);
	}

	p = s + pos - 1;
	while (*q != '\0')  //qָ��t�����
	{
		q++;
	}
	while (*p != '\0')  //��s��pos֮�����ӵ�t����
	{
		*(q++) = *(p++);
	}
	*q = '\0';
	p = s + pos - 1;  //p����ָ����

	while (*t != '\0')   //�Ѻ������һ��ؽӵ�pos����
	{
		*(p++) = *(t++);
	}
	*p = '\0';
	puts(s);
}

// �ڶ��ֲ��뷽ʽ  ֱ����posλ�ò���t
void insertss(char *s, char *t, int pos)
{
	char *p = s, r[5];//rΪ�ݴ����λ֮����ַ���
	int i = 0, lent = 0;
	if (pos < 1)
	{
		printf("λ�ò�����\n");
		exit(0);
	}
	while (*p&&i < pos - 1)
	{
		p++;
		i++;
	}
	if ((*p == '\0') && (*(--p) == '\0'))
	{
		printf("λ�ò�����\n");
		exit(0);
	}

	p = s + pos - 1;
	i = 0;
	while (*p != '\0')   //��pos������ַ��浽r[]������
	{
		r[i++] = *p++;
	}
	r[i] = '\0';  //�ַ���������־
	p = s + pos - 1;
	while (*t != '\0')
	{
		*(p++) = *(t++);   //ǿ�н�t����pos����
		lent++;   //��¼t����
	}
	i = 0;
	p = s + pos - 1 + lent ;  //pָ��t����

	while (r[i] != '\0')
	{
		*(p++) = r[i++];    //��p�������ԭ�ȵ�pos������ַ�����r[]
	}
	s[i + pos - 1 + lent] = '\0';
	puts(s);

}
int main(int argc, char const *argv[])
{
	char s[20], t[10];
	int pos;
	printf("�����ַ���s\n");
	gets_s(s);
	printf("�����ַ���t\n");
	gets_s(t);
	printf("������������λ��\n");
	std::cin >> pos;
	printf("���Ϊ��\n");
	//insert(s, t, pos);
	insertss(s, t, pos);
	return 0;
}