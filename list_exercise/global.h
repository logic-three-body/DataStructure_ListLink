#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<ctime>
constexpr int OK = 1;
constexpr int ERROR = 0;
constexpr int TRUE = 1;
constexpr int FALSE = 0;

constexpr int MAXSIZE = 20; /* �洢�ռ��ʼ������ */

typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */

Status visit(ElemType);