#include <algorithm>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
//vector<int> G[MAXN];
int head[MAXN], to[MAXN << 1], nex[MAXN << 1], totedge;
int n, p[MAXN], m, ans, jkl[MAXN], siz[MAXN];
priority_queue<ll> Q;

void dfs(int u, int fa)
{
    siz[u] = 1;
    for (int i = head[u]; i;i = nex[i])
    {
        int v = to[i];
        if (v != fa)
        {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
    ll tem = (ll)siz[u] * (ll)(n - siz[u]);
    if (tem)
        Q.push(tem);
}
inline void addedge(ll x, ll y)
{
    totedge++;
    to[totedge] = y;
    nex[totedge] = head[x];
    head[x] = totedge;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            siz[i] = 0,head[i] = 0;
        totedge = 0;
        ans = 0;
        for (int i = 1; i <= n - 1;i++)
        {
            int x , y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m;i++)
            scanf("%d", &p[i]);
        sort(p + 1, p + m + 1, greater<int>());
        if (n - 1 >= m)
        {
            for (int i = m + 1; i <= n - 1; i++)
                p[i] = 1;
            m = n - 1;
        }
        else
        {
            int cnt = 1;
            jkl[1] = 1;
            for (int i = 1; i <= m - n + 2;i++)
                jkl[1] = 1ll * jkl[1] * p[i] % MOD;
            for (int i = m - n + 3; i <= m;i++)
                jkl[++cnt] = p[i];
            m = n - 1;
            for (int i = 1; i <= m;i++)
                p[i] = jkl[i];
        }
        dfs(1, 0);
        for (int i = 1; i <= m;i++)
        {
            ll x = Q.top() % MOD;
            Q.pop();
            ans = (ans + 1ll * p[i] * x % MOD) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
