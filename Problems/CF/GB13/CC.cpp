#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define DEBUG
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const int maxn=5005;
int s[maxn];

int main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        REP(i,1,n) s[i]=read();
        LL ans=0;
        REP(i,1,n)
        {
            if(s[i]==1) continue;
            if(s[i]>n-i) ans+=s[i]-(n-i),s[i]=n-i;
            ans+=s[i]-1;
            while(s[i]>1)
            {
                int p=i;
                while(p<=n)
                {
                    int pp=p+s[p];
                    if(s[p]>1) s[p]--;
                    p=pp;
                }
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}