#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1e5 + 20;
int head[MAX], to[MAX << 1],nex[MAX],tot,father[MAX];   //for graph
int tot_Eu, eu[MAX << 1], depth[MAX], pos[MAX], st[20][MAX << 1];// for rmq
int vztd[MAX],pic[MAX];
//eu:欧拉序,pos[u]:u节点在欧拉序中第一次出现的位置，depth:节点深度;
int n, m, k;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
void add(int u,int v)
{
    tot++;
    to[tot] = v;
    nex[tot] = head[u];
    head[u] = tot;
}
void dfsget_eu_depth(int fa,int u,int deep)
{
    father[u] = fa;
    tot_Eu++;
    if(!pos[u])
        pos[u] = tot_Eu;
    eu[tot_Eu] = u;
    depth[u] = deep;
    for (int i = head[u]; i;i = nex[i])
    {
        int v = to[i];
        if(v == fa)
            continue;
        dfsget_eu_depth(u, v, deep + 1);
        eu[++tot_Eu] = u;
    }
}
inline int getmin(int tem[],int x,int y)
{
    return tem[x]>tem[y]?y:x;
}
void get_ST(int k)
{
    for(int i=1;i<=k;i++)
        st[0][i]=eu[i];
    for(int j=1;(1<<j)<=k;j++)
        for(int i=1;i+(1<<j)<=k;i++)
            st[j][i] = getmin(depth, st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int get_lca(int u,int v)
{
    if(pos[u] > pos[v])
        swap(u, v);
    int l = pos[u], r = pos[v];
    int k = trunc(log2(r - l + 1));
    return getmin(depth, st[k][l], st[k][r - (1 << k) + 1]);
}
void init()
{
    dfsget_eu_depth(0, 1, 1);
    get_ST((n << 1) - 1);
}
int mian()
{
    n = read();
    for (int i = 1; i < n;i++)
    {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    init();
    m = read();
    for (int i = 1; i <= m;i++)
    {
        k = read();
        for (int j = 1; j <= k;j++)
            pic[j] = read(), vztd[pic[j]] = 1;
        int flag = 0;
        for (int j = 1; j <= k;j++)
            if(vztd[pic[j]] == 1 and vztd[father[pic[j]]] == 1)
            {
                flag = 1;
                break;
            }
        build();
        if (!flag)
        {
            mfs(1);
            printf("%d\n", dp[1]);
        }
        else
            puts("-1");
        clear(1);
    }
}