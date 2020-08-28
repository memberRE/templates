#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 1e5 + 20;
struct ppp{
    int next,to;
}edge[MAX<<1];
int head[MAX],st[20][MAX << 1],eu[MAX<<1],dp[MAX],pos[MAX],num=0,nnum=0,gen,n,m,q,t;
int has_n[MAX],now_node,ans;
int tim_A[MAX], tim_B[MAX],vztd[MAX];
queue<int> que;
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
    {
        now_node = u;
        return;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if (has_n[v] == 1 and v != fa)
        {
            /*if (step <= 0)
                stk[topp++] = v;*/
            dfs2(v, u, step - 1);
        }
    }
}
void bfs1()
{
    while(!que.empty())
        que.pop();
    memset(vztd, 0, sizeof(vztd));
    vztd[n] = 1;
    que.push(n);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if (!vztd[v])
            {
                vztd[v] = 1;
                //tim_B[v] = (tim_B[u] < 0) ? abs(tim_B[u]) : -(tim_B[u] + 1);
                tim_B[v] = tim_B[u] + 5;
                que.push(v);
            }
        }
    }

    while(!que.empty())
        que.pop();
    memset(vztd, 0, sizeof(vztd));
    vztd[now_node] = 1;
    que.push(now_node);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if (!vztd[v])
            {
                vztd[v] = 1;
                tim_A[v] = tim_A[u] + 10;
                que.push(v);
            }
        }
    }

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
        ans = 1;
		dfs2(1, -1, t);
        bfs1();
        for (int i = 1; i <= n;i++)
        {
            tim_B[i] = abs(tim_B[i]);
            if (tim_B[i] >= tim_A[i])
                ans = max(ans, (tim_B[i] + 5)/10);
        }
        cout << ans << endl;
    }
    return 0;
}
