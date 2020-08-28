/*  File: line_stack.c
    ???›¥???????????????   */

#define _CRT_SECURE_NO_WARNINGS
#include "line_stack.h"

void push(int key)
{
    if (Top >= MAX || Top < MIN - 1)
        error();
    Stack[++Top] = key;
}
int pop(void)
{
    if (Top<MIN || Top>MAX)
        error();
    return(Stack[Top--]);
}

void stack(FILE *fp_op, int *a, int n)
{
    char ch='0';
    int i = 0;
    while (ch != EOF)
    {
        printf("\nDEBUG#####\n");
        if(fscanf(fp_op, "%c", &ch) == EOF)
            break;
        if (ch == 'P')
        {
            push(a[i]);
            i++;
        }
        if (ch == 'O')
        {
            printf("%hd ", pop());
        }
        if ((ch != 'P' && ch != 'O')||i>n)
            ;
           //error();
    }
}
