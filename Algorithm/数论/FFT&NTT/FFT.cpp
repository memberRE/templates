#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=1e7+20;
const double PI=acos(-1.0);
int n,m,l,rev[MAXN];
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
void fft(complex *p,int len,int op)
{
    for(int i=0;i<len;i++)
        if(i<rev[i])	swap(p[i],p[rev[i]]);
    for(int mid=1;mid<len;mid<<=1)
    {
        complex wn(cos(PI/mid),sin(PI/mid)*op);
        int stepp=mid<<1;
        for(int j=0;j<len;j+=stepp)
        {
            complex w(1,0);
            for(int k=0;k<mid;k++,w=w*wn)
            {
                complex x=p[j+k];
                complex y=w*p[j+k+mid];
                p[j+k]=x+y;
                p[j+k+mid]=x-y;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        scanf("%lf",&a[i].x);
    for(int i=0;i<=m;i++)
    {
        scanf("%lf",&b[i].x);
        a[i].y=b[i].x; 
    } 
    int len=1;
    while(len<n+1+m)	len<<=1,l++;//maybe error
    for(int i=0;i<len;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
    fft(a,len,1);
    for(int i=0;i<len;i++)
        a[i]=a[i]*a[i];
    fft(a,len,-1);
    for(int i=0;i<=n+m;i++)	
        printf("%d ",(int)(a[i].y/(len<<1)+0.5));
    return 0;
}
