#include <stdio.h>
#include<stdlib.h>
#include<iostream>
// 第一种插入方式， 先把s的pos以后的字符串链接到t上，然后在将t插入到s的pos位置
void insert(char *s, char *t, int pos)
{
	char *p = s, *q = t;
	int i = 0, lent = 0;
	if (pos < 1)
	{
		printf("位置不合理\n");
		exit(0);
	}
	while (*p&&i < pos - 1)
	{
		p++;
		i++;
	}
	if (*p == '\0')
	{
		printf("位置不合理\n");
		exit(0);
	}

	p = s + pos - 1;
	while (*q != '\0')  //q指向t的最后
	{
		q++;
	}
	while (*p != '\0')  //把s的pos之后链接到t后面
	{
		*(q++) = *(p++);
	}
	*q = '\0';
	p = s + pos - 1;  //p重新指回来

	while (*t != '\0')   //把后面的那一大截接到pos后面
	{
		*(p++) = *(t++);
	}
	*p = '\0';
	puts(s);
}

// 第二种插入方式  直接在pos位置插入t
void insertss(char *s, char *t, int pos)
{
	char *p = s, r[5];//r为暂存插入位之后的字符串
	int i = 0, lent = 0;
	if (pos < 1)
	{
		printf("位置不合理\n");
		exit(0);
	}
	while (*p&&i < pos - 1)
	{
		p++;
		i++;
	}
	if ((*p == '\0') && (*(--p) == '\0'))
	{
		printf("位置不合理\n");
		exit(0);
	}

	p = s + pos - 1;
	i = 0;
	while (*p != '\0')   //把pos后面的字符存到r[]数组中
	{
		r[i++] = *p++;
	}
	r[i] = '\0';  //字符串结束标志
	p = s + pos - 1;
	while (*t != '\0')
	{
		*(p++) = *(t++);   //强行将t插在pos后面
		lent++;   //记录t长度
	}
	i = 0;
	p = s + pos - 1 + lent ;  //p指向t后面

	while (r[i] != '\0')
	{
		*(p++) = r[i++];    //把p后面接上原先的pos后面的字符，即r[]
	}
	s[i + pos - 1 + lent] = '\0';
	puts(s);

}
int main(int argc, char const *argv[])
{
	char s[20], t[10];
	int pos;
	printf("输入字符串s\n");
	gets_s(s);
	printf("输入字符串t\n");
	gets_s(t);
	printf("输入你想插入的位置\n");
	std::cin >> pos;
	printf("结果为：\n");
	//insert(s, t, pos);
	insertss(s, t, pos);
	return 0;
}