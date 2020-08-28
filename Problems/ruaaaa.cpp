#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double A[10][10];
double X[10];
double b[10];
double Y[10];
double X0[10];

void f()
{
    int i,j;
    for (i=1;i<=3;i++)
    {
        printf("输入系数矩阵A的第%d行:\n",i);
        for (j=1;j<=3;j++)
        {
            scanf("%lf",&A[i-1][j-1]);
        }
    }
    printf("输入矩阵b:\n");
    for (i=1;i<=3;i++)
    {
        scanf("%lf",&b[i-1]);
    }
    printf("输入初始变量X0:\n");
     for (i=1;i<=3;i++)
    {
        scanf("%lf",&X0[i-1]);
    }
}

int main()
{
    int i,j;
    double sum;
    f();
    for(i=0; i<=3; i++)
    {
        X[i]=X0[i];
        Y[i]=X0[i];
    }
    printf("\n");
    printf("迭代过程:\n");
  for(;;)
    {
        int flag=0;
        for(i=0; i<3; i++)
        {
            sum=0;
            for(j=0; j<i; j++)
                sum+=A[i][j]*Y[j];
            for(j=i+1;j<3;j++)
                sum+=A[i][j]*X[j];
            double tem=(b[i]-sum)/A[i][i];
            if(abs(Y[i]-tem)>1e-3)
                flag=1;
            Y[i]=tem;
        }
        for(i=0; i<3; i++)
        {
            printf("%lf\t",Y[i]);
        }
        if(!flag)
            break;
    }
printf("\n");

    printf("解出方程组的解:\n");
    for(i=0; i<3; i++)
    {
        printf("%lf\t",Y[i]);
    }
}