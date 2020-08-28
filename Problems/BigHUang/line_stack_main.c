/*  File: line_stack_main.c
    ˳��洢��ջ�������������ļ�  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define M       1000
#define MAX     M-1                 /* ջ����              */
#define MIN     0                   /* ջ��ָ��ֵ          */

char *infile = "./stack_in.txt"; //"C:\\stack_in.txt";      /* �����ļ���          */
char *opfile = "./stack_op.txt"; //"C:\\stack_op.txt";      /* �����ļ���          */

void stack(FILE *, int *, int);

void error()
{
    printf("error in your program!\n");
    exit(0);
}

void prt(int *a, int n)
{
    int j;
    printf("%hd nodes in list.\n", n);
    for(j = 0; j < n; j++)
        printf("%hd%c", a[j], (j + 1) % 10 == 0 ? '\n' : ' ');
    printf("\n");
}

int main()
{
    int  a[M], n, j;
    FILE *fp_in, *fp_op;
    if(!(fp_in= fopen(infile, "r")))
        exit(0);
    if(!(fp_op= fopen(opfile, "r")))
        exit(0);
    fscanf(fp_in, "%d", &n);
    if(n > M-1 || n < 1)
        error();                    /* invalid   n          */
    for(j = 0; j < n; j++)
        fscanf(fp_in, "%d", &a[j]);
    prt(a, n);
    stack(fp_op, a, n);
    return 0;
}
