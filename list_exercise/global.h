#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<ctime>
constexpr int OK = 1;
constexpr int ERROR = 0;
constexpr int TRUE = 1;
constexpr int FALSE = 0;

constexpr int MAXSIZE = 20; /* 存储空间初始分配量 */

typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

Status visit(ElemType);