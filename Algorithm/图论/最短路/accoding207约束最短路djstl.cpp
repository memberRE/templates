#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long LL;

int read()
{
    int x=0,flag=1;
    char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const int maxn=2005;
const LL inf=1e16;
struct P
{
    LL w;
    int bian,u;
    P(LL w,int bian,int u):w(w),bian(bian),u(u) {}
    bool operator < (const P x) const
    {
        if(w==x.w) return u>x.u;
        return w>x.w;
    }
};
struct edge {int to; LL cost;};
vector<edge> G[maxn];
int n,m,s,t,q,qu[1000005],bian[maxn],tot;
LL d[maxn][maxn],ans[300005],can[maxn];

void Djkstra(int s)
{
    REP(i,1,n) REP(j,1,n) d[i][j]=inf;
    d[s][0]=0;
    priority_queue<P> que;
    que.push(P(0,0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        if(p.bian>=n-1 || d[p.u][p.bian]<p.w) continue;
        REP(i,0,G[p.u].size()-1)
        {
            int v=G[p.u][i].to;
            LL w=G[p.u][i].cost;
            if(p.w+w<d[v][p.bian+1])
            {
                d[v][p.bian+1]=p.w+w;
                que.push(P(p.w+w,p.bian+1,v));
            }
        }
    }
}

int main()
{
    int TT=read();
    while(TT--)
    {
        tot=0;
        mem(ans,0);
        n=read(),m=read(),q=read();
        REP(i,1,n) G[i].clear();
        while(m--)
        {
            int u=read(),v=read(),c=read();
            G[u].push_back((edge){v,c});
        }
        s=read(),t=read();
        Djkstra(s);
        REP(i,1,n-1) if(d[t][i]!=inf) can[tot]=d[t][i],bian[tot++]=i;
        //REP(i,0,tot-1) cout<<can[i]<<' '<<bian[i]<<endl;
        REP(i,1,q) qu[i]=read();
        REP(i,1,q)
        {
            if(ans[qu[i]]) printf("%lld\n",ans[qu[i]]);
            else
            {
                LL minx=inf;
                REP(j,0,tot-1) minx=min(minx,can[j]+1ll*qu[i]*bian[j]);
                ans[qu[i]]=minx;
                printf("%lld\n",minx);
            }
        }
    }
    return 0;
}


