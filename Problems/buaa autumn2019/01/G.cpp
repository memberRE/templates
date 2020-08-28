#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=2e5+20;
const double PI=acos(-1,0);
struct complex{
    double x,y;
    complex (double xx=0,double yy=0){x=xx,y=yy;}
}a[MAXN],b[MAXN];
complex operator + (complex a,complex b){
    return complex(a.x+b.x,a.y+b.y);
}
complex operator - (complex a,complex b){
    return complex(a.x-b.x,a.y-b.y);
}
complex operator * (complex a,complex b){
    return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
int n,x;
int pic[MAX],sum[MAX];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&pic[i]);
        pic[i]=pic[i]<x?1:0;
        sum[i]=sum[i-1]+pic[i];
        a[sum[i]].x++;
        b[n-sum[i]].x++;
    }
    int len=1;
    while(len<2*n+1)
}