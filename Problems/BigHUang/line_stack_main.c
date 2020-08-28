/*  File: line_stack_main.c
    顺序存储的栈操作程序主控文件  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define M       1000
#define MAX     M-1                 /* 栈容量              */
#define MIN     0                   /* 栈底指针值          */

char *infile = "./stack_in.txt"; //"C:\\stack_in.txt";      /* 输入文件名          */
char *opfile = "./stack_op.txt"; //"C:\\stack_op.txt";      /* 操作文件名          */

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
