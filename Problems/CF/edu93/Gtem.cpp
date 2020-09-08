#include <bits/stdc++.h>
#define N 1000009 
#define ll long long
#define setIO(s) freopen(s".in","r",stdin)
using namespace std;
int n,bu[N];    
const double pi=acos(-1); 
struct cp {
    double x,y; 
    cp(double i=0,double j=0){ x=i,y=j; }        
    cp operator+(const cp b) const { return cp(x+b.x,y+b.y); }
    cp operator-(const cp b) const { return cp(x-b.x,y-b.y); }
    cp operator*(const cp b) const { return cp(x*b.x-y*b.y,x*b.y+y*b.x); }
}A[N],B[N]; 
void FFT(cp *a,int len,int op) {
    for(int i=0,k=0;i<len;++i) {
        if(i>k) swap(a[i],a[k]);
        for(int j=len>>1;(k^=j)<j;j>>=1);   
    }
    for(int l=1;l<len;l<<=1) {
        cp wn(cos(pi/l),op*sin(pi/l)),x,y;   
        for(int i=0;i<len;i+=l<<1) {
            cp w(1,0);
            for(int j=0;j<l;++j) {
                x=a[i+j],y=w*a[i+j+l];
                a[i+j]=x+y;
                a[i+j+l]=x-y;
                w=w*wn;    
            }
        }
    }
    if(op==-1) {
        for(int i=0;i<len;++i) a[i].x/=len; 
    }
}
int main() {
    // setIO("input"); 
    int x,y,z,lim; 
    scanf("%d%d%d",&n,&x,&y);     
    for(int i=0;i<=n;++i) {  
        int tmp;
        scanf("%d",&tmp);
        A[tmp].x=1;            
        B[x-tmp].x=1;  
    }
    for(lim=1;lim<=(x<<1);lim<<=1);    
    FFT(A,lim,1),FFT(B,lim,1);
    for(int i=0;i<lim;++i) {
        A[i]=A[i]*B[i];
    }
    FFT(A,lim,-1);
    for(int i=1;i<=x;++i) {
        ll p=(ll)(A[i+x].x+0.5);    
        if(p) {  
            for(int j=2*(i+y);j<N;j+=2*(i+y)) {
                bu[j]=2*(i+y);  
            }
        }
    }
    for(int j=2*(x+y);j<N;j+=2*(x+y)) bu[j]=2*(x+y); 
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int l;
        scanf("%d",&l);
        printf("%d ",bu[l]?bu[l]:-1); 
    }
    return 0;
}