#pragma GCC optimize(2)
#include <bits/stdc++.h>
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

const int maxn=2e5+5;
vector<int> G[maxn];
int n,a[maxn],b[maxn],c[maxn],h[maxn][2];
LL ans;

void dfs(int u,int fa,int minx)
{
    minx=min(minx,a[u]);
    REP(i,0,G[u].size()-1) if(G[u][i]!=fa) dfs(G[u][i],u,minx);
    REP(i,0,G[u].size()-1)
    {
        int v=G[u][i];
        if(v==fa) continue;
        h[u][0]+=h[v][0]; h[u][1]+=h[v][1];
    }
    //if(u==1) cout<<g[u][0]<<' '<<g[u][1]<<endl;
    if(b[u]!=c[u]) h[u][c[u]]++;
    if(a[u]<=minx)
    {
        int x=min(h[u][0],h[u][1]);
        ans+=1ll*x*2*a[u];
        h[u][0]-=x; h[u][1]-=x;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    n=read();
    REP(i,1,n) a[i]=read(),b[i]=read(),c[i]=read();
    REP(i,1,n-1)
    {
        int u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,1e9+5);
    if(h[1][0]!=h[1][1]) puts("-1");
    else printf("%lld\n",ans);
    //cout<<h[1][0]<<' '<<h[1][1];
    //REP(i,1,n) cout<<h[i][0]<<' '<<h[i][1]<<endl;
    //REP(i,1,n) cout<<f[i]<<' '<<g[i][0]<<' '<<g[i][1]<<endl;

    return 0;
}
