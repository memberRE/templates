#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
 
const int maxn=2e6+5;
bool isprime[maxn];
int sq[maxn];
 
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    if(!b) {x=1; y=0; return a;}
    LL r=ex_gcd(b,a%b,x,y),t=x;
    x=y,y=t-a/b*y;
    return r;
}
 
bool cal(LL a,LL b,LL c,LL &x,LL &y)
{
    if(c%__gcd(a,b)!=0) return 0;
    LL q=ex_gcd(a,b,x,y);
    LL v=c/q;
    x*=v; y*=v; y*=-1;
    return 1;
}
 
int main()
{
    REP(i,2,2000000) isprime[i]=1;
    REP(i,2,20000) if(isprime[i]) for(int j=i*i;j<=2000000;j+=i) isprime[j]=0;
    for(int i=1;i<=20000;i++) if(i*i<=2000000) sq[i*i]=i;
    REP(i,1,2000000) if(!sq[i]) sq[i]=sq[i-1];
    int T=read();
    while(T--)
    {
        LL a=read(),b=read();
        if(b==1) puts("-1 -1 -1 -1");
        else if(a%b==0)
        {
            int x=a/b;
            printf("%d 1 %d 1\n",x+1,1);
        }
        else if(isprime[b])
        {
            puts("-1 -1 -1 -1");
        }
        else
        {
            int flag=0;
            for(LL l=2,r=sq[b]+2;l<=r+1;l++,r--)
            {
                if(l>=2 && l<b && b%l==0)
                {
                    LL x=l,y=b/x,c,e;
                    if(cal(y,x,a,c,e))
                    {
                        if(e<=0 || c<=0)
                        {
                            if(c<=0 && e<=0) printf("%lld %lld %lld %lld\n",-e+y,y,-c+x,x);
                            else if(e<=0)
                            {
                                LL q=(-e)/y+2;
                                printf("%lld %lld %lld %lld\n",c+x*q,x,e+y*q,y);
                            }
                        }
                        else printf("%lld %lld %lld %lld\n",c,x,e,y);
                        flag=1;
                        break;
                    }
                }
                if(r>=2 && r<b && b%r==0)
                {
                    LL x=r,y=b/x,c,e;
                    if(cal(y,x,a,c,e))
                    {
                        if(e<=0 || c<=0)
                        {
                            if(c<=0 && e<=0) printf("%lld %lld %lld %lld\n",-e+y,y,-c+x,x);
                            else if(e<=0)
                            {
                                LL q=(-e)/y+2;
                                printf("%lld %lld %lld %lld\n",c+x*q,x,e+y*q,y);
                            }
                        }
                        else printf("%lld %lld %lld %lld\n",c,x,e,y);
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag) puts("-1 -1 -1 -1");
        }
    }
 
    return 0;
}