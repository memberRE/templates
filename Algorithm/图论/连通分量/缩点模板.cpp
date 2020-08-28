#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
struct ppp{
    vector<int>w,v;
}pic[100001];
int dfn[100001],low[100001],scc_cnt,sccno[100001],id=1,n,m,ans=9999999;
int v[100001],value[100001],dp[100001];
bool vztd[100001];
stack<int> s;
void tarjan(int u)
{
    dfn[u]=low[u]=++id;
    s.push(u);
    for(int i=0;i<pic[u].w.size();i++)
    {
        int kk=pic[u].w[i];
        if(!dfn[kk])
        {
            tarjan(kk);
            low[u]=min(low[u],low[kk]);
        }
        else if(!sccno[kk]) low[u]=min(low[u],dfn[kk]);
    }
    if(dfn[u]==low[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=s.top();
            s.pop();
            sccno[x]=scc_cnt;
            v[scc_cnt]+=value[x];
            if(x==u)	break;
        }
    }
}
int mfs(int u)
{
    if(vztd[u])	return dp[u];
    vztd[u]=1;
    dp[u]=v[u];
    for(int i=0;i<pic[u].v.size();i++)
        dp[u]=max(dp[u],v[u]+mfs(pic[u].v[i]));
    return dp[u];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        pic[x].w.push_back(y);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    //--------------------------------------
    for(int u=1;u<=n;u++)
        for(int i=0;i<pic[u].w.size();i++)
        {
            int V=pic[u].w[i];
            if(sccno[V]!=sccno[u])
                pic[sccno[u]].v.push_back(sccno[V]);
        }
    //---------------------------------------
    int maxx=-1;
    for(int i=1;i<=scc_cnt;i++)
        maxx=max(maxx,mfs(i));
    cout<<maxx<<endl;
    return 0;
}