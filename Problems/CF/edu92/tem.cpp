#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

#define repi(i, a, b) for (int i = a; i <= b; ++i)
#define ll long long
#define ce(i, r) i == r ? '\n' : ' '
using namespace std;

inline int qr()
{
    int f = 0, fu = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            fu = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        f = (f << 3) + (f << 1) + c - 48;
        c = getchar();
    }
    return f * fu;
}

const int N = 3e5 + 10, M = 3e5 + 10;
int head[N], ver[M << 1], Next[M << 1], edge[M << 1], tot = 1;
int hc[N], vc[M << 1], nc[M << 1], ec[M << 1], tc, dcc;
int n, m, k;

inline void add(int x, int y, int z)
{
    ver[++tot] = y;
    Next[tot] = head[x];
    edge[tot] = z;
    head[x] = tot;
}

struct E_DCC
{
    int dfn[N], low[N], c[N];
    int num;
    bool bridge[M << 1];

    void tarjan(int x, int in_edge)
    {
        dfn[x] = low[x] = ++num;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i];
            if (!dfn[y])
            {
                tarjan(y, i);
                low[x] = min(low[x], low[y]);
                if (low[y] > dfn[x])
                    bridge[i] = bridge[i ^ 1] = true;
            }
            else if (i != (in_edge ^ 1))
                low[x] = min(low[x], dfn[y]);
        }
    }

    inline void solve()
    {
        repi(i, 1, n) if (!dfn[i]) tarjan(i, 0);
        for (int i = 2; i <= tot; i++)
            cout << bridge[i] << " ";
        e_dcc(), build();
    }

    void dfs(int x)
    {
        c[x] = dcc;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i];
            if (c[y] || bridge[i])
                continue;
            dfs(y);
        }
    }

    inline void e_dcc()
    {
        dcc = 0;
        repi(i, 1, n) if (!c[i])++ dcc, dfs(i);
    }

    void add_c(int x, int y, int z)
    {
        vc[++tc] = y, nc[tc] = hc[x], ec[tc] = z, hc[x] = tc;
    }

    inline void build()
    {
        repi(i, 1, n) hc[i] = 0;
        tc = 1;
        repi(i, 2, tot)
        {
            int x = ver[i ^ 1], y = ver[i], z = edge[i];
            if (c[x] == c[y])
                continue;
            add_c(c[x], c[y], z);
        }
    }
} E;

int c[N], w[M], v[N], top[N];
ll val[N], f[N];
bool key[N];

void dfs1(int x, int fa)
{
    for (int i = hc[x]; i; i = nc[i])
    {
        int y = vc[i];
        if (y == fa)
            continue;
        dfs1(y, x), key[x] |= key[y];
    }
}

void dfs2(int x, int fa)
{
    top[x] = key[x] ? x : top[fa];
    for (int i = hc[x]; i; i = nc[i])
    {
        int y = vc[i];
        if (y == fa)
            continue;
        dfs2(y, x);
    }
}

void dfs3(int x, int fa)
{
    f[x] = val[x];
    for (int i = hc[x]; i; i = nc[i])
    {
        int y = vc[i], z = ec[i];
        if (y == fa || !key[y])
            continue;
        dfs3(y, x), f[x] += max(0ll, f[y] - z);
    }
}

void dfs4(int x, int fa)
{
    for (int i = hc[x]; i; i = nc[i])
    {
        int y = vc[i], z = ec[i];
        if (y == fa || !key[y])
            continue;
        f[y] += max(0ll, f[x] - max(0ll, f[y] - z) - z), dfs4(y, x);
    }
}

int main()
{
    n = qr(), m = qr(), k = qr();
    repi(i, 1, k) v[i] = qr();
    repi(i, 1, n) c[i] = qr();
    repi(i, 1, m) w[i] = qr();
    repi(i, 1, m)
    {
        int x = qr(), y = qr();
        add(x, y, w[i]), add(y, x, w[i]);
    }
    E.solve();
    for (int i = 1; i <= n; i++)
        cout << E.c[i] << " ";
    return 0;
    repi(i, 1, n) val[E.c[i]] += c[i];
    repi(i, 1, k) key[E.c[v[i]]] = true;
    int r = E.c[v[1]];

    dfs1(r, 0), dfs2(r, 0);
    repi(i, 1, dcc) if (!key[i]) val[top[i]] += val[i];
    repi(i, 1, n) E.c[i] = top[E.c[i]];

    dfs3(r, 0), dfs4(r, 0);
    repi(i, 1, n) printf("%lld%c", f[E.c[i]], ce(i, n));
    return 0;
}