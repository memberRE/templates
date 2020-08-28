#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 1e5 + 20;
struct ppp{
    int next,to;
}edge[MAX<<1];
int head[MAX],st[20][MAX << 1],eu[MAX<<1],dp[MAX],pos[MAX],num=0,nnum=0,gen,n,m,q,t;
int has_n[MAX],stk[MAX],topp,now_node,ans;
vector<int> leaf[MAX];
void addedge(int x,int y)
{
    nnum++;
    edge[nnum].to=y;
    edge[nnum].next=head[x];
    head[x]=nnum;
}
int getmin(int x,int y)
{
    return dp[x]>dp[y]?y:x;
}
void dfs(int fa,int u,int deep)
{
    num++;
    if (u == n)
        has_n[u] = 1;
    if(!pos[u])	
        pos[u]=num;
    eu[num]=u;
    dp[u]=deep;
    for(int i=head[u];i/*!=-1*/;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v == n)
            has_n[u] = 1;
        if(v==fa) 
            continue;
        dfs(u,v,deep+1);
        eu[++num]=u;
        has_n[u] = max(has_n[u], has_n[v]);
    }
}
void dfs2(int u,int fa,int step)
{
    if (step == 0)
        now_node = u;
    if (u == n)
        return;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if (has_n[v] == 1 and v != fa)
        {
            if (step <= 0)
                stk[topp++] = v;
            return dfs2(v, u, step - 1);
        }
    }
}
void dfs3(int u,int x,int fa)
{
    int son = 0;
    for(int i=head[u];i;i=edge[i].next)
    {
        son++;
        int v=edge[i].to;
        if (has_n[v] == 1 || v == fa)
            continue;
        dfs3(v, x, u);
    }
    if (son == 0)
        leaf[stk[x]].push_back(u);
}
void ST(int k)
{
    for(int i=1;i<=k;i++)
        st[0][i]=eu[i];
    for(int j=1;(1<<j)<=k;j++)
        for(int i=1;i+(1<<j) - 1<=k;i++)
            st[j][i]=getmin(st[j-1][i],st[j-1][i+(1<<j-1)]);
}
inline int rmq(int l,int r)
{
    int k=trunc(log2(r-l+1));
    return getmin(st[k][l],st[k][r-(1<<k)+1]);
}
inline int lca(int u,int v)
{
    if(pos[u]>pos[v])	swap(u,v);
    return rmq(pos[u],pos[v]);
}
inline int get_dis(int u,int v)
{
    return dp[u] + dp[v] - 2 * dp[lca(u, v)];
}
int main()
{
    cin>>n>>t;
    // memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(-1,1,0);
    ST(2*n-1);
    int dis = dp[1] + dp[n] - 2 * dp[lca(1, n)];
    if (t >= dis)
        cout << 0 << endl;
    else
    {
        dfs2(1, -1, t);
        int dis_n_t = dis - t;
        ans = dis_n_t / 2 + dis_n_t % 2;
        for (int i = 0; i < topp;i++)
            dfs3(stk[i],i, i == 0 ? -1 : stk[i - 1]);
        for (int i = 0; i <= topp;i++)
        {
            for (int j = 0; j < leaf[stk[i]].size();j++)
            {
                int endd = leaf[stk[i]][j];
                if (i == 0)
                {
                    int dis3 = get_dis(endd, now_node);
                    if (dis3 >= dis_n_t - 1)
                        ans = max(ans, dis_n_t);
                    else 
                    {
                        int tem = dis3;
                        int tem2 = dis3 + dis_n_t - 2 * dis3;
                        tem += tem2 / 2 + tem2 % 2;
                        ans = max(ans, tem);
                    }
                }
                else
                {
                    if (i + 2*i >= dis_n_t)
                        continue;
                    int dis_n_t2 = dis_n_t - 3 * i;
                    int dis3 = get_dis(endd, stk[i]);
                    if (dis3 >= dis_n_t2 - 1)
                        ans = max(ans, dis_n_t2);
                    else 
                    {
                        int tem = dis3;
                        int tem2 = dis3 + dis_n_t2 - 2 * dis3;
                        tem += tem2 / 2 + tem2 % 2;
                        ans = max(ans, tem);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}