/*  File: line_stack.h
    ˳��洢��ջ��������ͷ�ļ�   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define M       1000
#define MAX     M-1             /* ջ����                  */
#define MIN     0               /* ջ��ָ��ֵ              */

int Stack[M];                   /* ��������ջ            */
int Top = MIN - 1;              /* ջ��ָ�룬��ʼΪ��ջ     */

void error();
void prt(int *, int);
