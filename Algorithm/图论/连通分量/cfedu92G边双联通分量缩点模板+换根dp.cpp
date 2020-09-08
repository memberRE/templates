#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '-')
        c = getchar();
    if (c == '-')
        flag = 0, c = getchar();
    while (c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
const int MAX = 3e5 + 20;
int n, m, k;
int initNodeVal[MAX], initEdgeVal[MAX], specNode[MAX];
int head[MAX], to[MAX << 1], val[MAX << 1], nex[MAX << 1], tot = 1;
ll aft_val[MAX], dp[MAX];
int flag[MAX], topp[MAX];
inline void addedge(int x, int y, int w)
{
    tot++;
    to[tot] = y;
    nex[tot] = head[x];
    head[x] = tot;
    val[tot] = w;
}
struct E_DCC //无重边版本的e-dcc
{
    int dfn[MAX], low[MAX], node2dcc[MAX];
    int num, tot_dcc;
    bool bridge[MAX << 1]; // 边是否为桥

    int dcc_head[MAX], dcc_nex[MAX << 1], dcc_to[MAX << 1], dcc_val[MAX << 1], dcc_edge_tot;

    void tarjan(int u, int in_edge)
    {
        dfn[u] = low[u] = ++num;
        for (int i = head[u]; i; i = nex[i])
        {
            int v = to[i];
            if (!dfn[v])
            {
                tarjan(v, i);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    bridge[i] = bridge[i ^ 1] = 1;
            }
            else if (i != (in_edge ^ 1))
                low[u] = min(low[u], dfn[v]);
        }
    }

    void dfs_dcc(int u)
    {
        node2dcc[u] = tot_dcc;
        for (int i = head[u]; i; i = nex[i])
        {
            int v = to[i];
            if (node2dcc[v] or bridge[i])
                continue;
            dfs_dcc(v);
        }
    }

    inline void shrink_point()
    {
        for (int i = 1; i <= n; i++)
            if (!node2dcc[i])
            {
                tot_dcc++;
                dfs_dcc(i);
            }
        build();
    }

    inline void add(int x, int y, int z)
    {
        dcc_edge_tot++;
        dcc_to[dcc_edge_tot] = y;
        dcc_val[dcc_edge_tot] = z;
        dcc_nex[dcc_edge_tot] = dcc_head[x];
        dcc_head[x] = dcc_edge_tot;
    }

    inline void build()
    {
        dcc_edge_tot = 1;
        for (int i = 2; i <= tot; i++)
        {
            int x = to[i ^ 1], y = to[i], z = val[i];
            if (node2dcc[x] == node2dcc[y])
                continue;
            add(node2dcc[x], node2dcc[y], z);
        }
    }

    inline void work()
    {
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i, 0);
        shrink_point();
    }
} E;

void dfs_sd1(int u, int fa)
{
    for (int i = E.dcc_head[u]; i; i = E.dcc_nex[i])
    {
        int v = E.dcc_to[i];
        if (v == fa)
            continue;
        dfs_sd1(v, u);
        flag[u] |= flag[v];
    }
}
void dfs_sd2(int u, int fa)
{
    topp[u] = flag[u] ? u : topp[fa];
    for (int i = E.dcc_head[u]; i; i = E.dcc_nex[i])
    {
        int v = E.dcc_to[i];
        if (v == fa)
            continue;
        dfs_sd2(v, u);
    }
}
void dfs_hg1(int u, int fa)
{
    dp[u] = aft_val[u];
    for (int i = E.dcc_head[u]; i; i = E.dcc_nex[i])
    {
        int v = E.dcc_to[i];
        int wei = E.dcc_val[i];
        if (v == fa || !flag[v])
            continue;
        dfs_hg1(v, u);
        dp[u] += max(0ll, dp[v] - wei);
    }
}

void dfs_hgdp(int u, int fa)
{
    for (int i = E.dcc_head[u]; i; i = E.dcc_nex[i])
    {
        int v = E.dcc_to[i];
        int wei = E.dcc_val[i];
        if (v == fa || !flag[v])
            continue;
        dp[v] += max(0ll, dp[u] - max(0ll, dp[v] - wei) - wei);
        dfs_hgdp(v, u);
    }
}
void DEBUG()
{
    for (int i = 1; i <= n; i++)
        cout << E.node2dcc[i] << " ";
}
int main()
{
    n = read();
    m = read();
    k = read();
    for (int i = 1; i <= k; i++)
        specNode[i] = read();
    for (int i = 1; i <= n; i++)
        initNodeVal[i] = read();
    for (int i = 1; i <= m; i++)
        initEdgeVal[i] = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        addedge(x, y, initEdgeVal[i]);
        addedge(y, x, initEdgeVal[i]);
    }
    E.work();
    for (int i = 1; i <= n; i++)
        aft_val[E.node2dcc[i]] += initNodeVal[i];
    for (int i = 1; i <= k; i++)
        flag[E.node2dcc[specNode[i]]] = 1;
    int root = E.node2dcc[specNode[1]];
    //---------------------------------
    dfs_sd1(root, 0);
    dfs_sd2(root, 0);
    for (int i = 1; i <= E.tot_dcc; i++)
        if (!flag[i])
            aft_val[topp[i]] += aft_val[i];
    for (int i = 1; i <= n; i++)
        E.node2dcc[i] = topp[E.node2dcc[i]];
    //-------------------------------------
    dfs_hg1(root, 0);
    dfs_hgdp(root, 0);
    for (int i = 1; i <= n; i++)
        printf("%lld ", dp[E.node2dcc[i]]);
    return 0;
}