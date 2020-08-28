/*  File: line_stack.h
    顺序存储的栈操作程序头文件   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define M       1000
#define MAX     M-1             /* 栈容量                  */
#define MIN     0               /* 栈底指针值              */

int Stack[M];                   /* 用数组存放栈            */
int Top = MIN - 1;              /* 栈顶指针，初始为空栈     */

void error();
void prt(int *, int);
