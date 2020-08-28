#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
ll n, q, root, MOD;
ll pic[MAX], head[MAX], to[MAX << 1], nex[MAX << 1], tot;
ll deep[MAX], fa[MAX], size[MAX], hson[MAX], top[MAX], id[MAX], rk[MAX], cnt;
ll sum[MAX << 2], lazy[MAX << 2]; /*  */
inline void add(ll x, ll y)
{
    tot++;
    to[tot] = y;
    nex[tot] = head[x];
    head[x] = tot;
}
inline void dfs1(ll u, ll f, ll dp)
{
    deep[u] = dp;   //标记每个点的深度 
    fa[u] = f;      //标记每个点的父亲 
    size[u] = 1;    //标记每个非叶子节点的子树大小 
    for (ll i = head[u]; i; i = nex[i])
    {
        ll v = to[i];
        if (v == f)
            continue;
        dfs1(v, u, dp + 1);
        size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;       //标记每个非叶子节点的重儿子编号 
    }
}
inline void dfs2(ll u, ll t)    //u当前节点，t当前链的最顶端的节点 
{
    top[u] = t;
    id[u] = ++cnt;  //标记每个点的新编号 
    rk[cnt] = u;    //反向映射
    if (!hson[u])
        return;
    dfs2(hson[u], t);   //先遍历重儿子，使得重链dfs序连续，便于线段树
    for (ll i = head[u]; i; i = nex[i])
    {
        ll v = to[i];
        if (v != hson[u] and v != fa[u])
            dfs2(v, v);
    }
}
inline void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        sum[node] = pic[rk[l]] % MOD;
        return;
    }
    ll mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build((node << 1) | 1, mid + 1, r);
    sum[node] = (sum[node << 1] + sum[(node << 1) | 1]) % MOD;
}
inline void pushdow(ll node, ll l, ll r)
{
    lazy[node << 1] += lazy[node];
    lazy[node << 1] %= MOD;
    lazy[(node << 1) | 1] += lazy[node];
    lazy[(node << 1) | 1] %= MOD;
    sum[node << 1] += lazy[node] * (((l + r) >> 1) - l + 1);
    sum[(node << 1) | 1] += lazy[node] * (r - ((l + r) >> 1));
    sum[node << 1] %= MOD;
    sum[(node << 1) | 1] %= MOD;
    lazy[node] = 0;
}
inline void update(ll node, ll l, ll r, ll L, ll R, ll k)
{
    if (l == L and R == r)
    {
        sum[node] += k * (R - L + 1); //maybe error
        sum[node] %= MOD;
        lazy[node] += k;
        lazy[node] %= MOD;
        return;
    }
    else
    {
        if (lazy[node])
            pushdow(node, L, R);
        int mid = (L + R) >> 1;
        if (r <= mid)
            update(node << 1, l, r, L, mid, k); //maybe error
        else if (l >= mid + 1)
            update((node << 1) | 1, l, r, mid + 1, R, k); //maybe error
        else
        {
            update(node << 1, l, mid, L, mid, k);
            update((node << 1) | 1, mid + 1, r, mid + 1, R, k);
        }
        sum[node] = (sum[node << 1] + sum[(node << 1) | 1]) % MOD;
    }
}
inline void rangadd(ll x, ll y, ll k) //deep[x]>deep[y]
{
    k %= MOD;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        update(1, id[top[x]], id[x], 1, n, k);
        x = fa[top[x]];
    }
    //if(deep[x]<deep[y])	swap(x,y);
    if (id[x] > id[y])
        swap(x, y);
    update(1, id[x], id[y], 1, n, k);
}
inline ll qurry(int node, int l, int r, int L, int R)
{
    if (l == L and r == R)
        return sum[node] % MOD;
    else
    {
        if (lazy[node])
            pushdow(node, L, R);
        ll mid = (L + R) >> 1;
        if (r <= mid)
            return qurry(node << 1, l, r, L, mid);
        else if (l >= mid + 1)
            return qurry((node << 1) | 1, l, r, mid + 1, R);
        else
            return (qurry(node << 1, l, mid, L, mid) + qurry((node << 1) | 1, mid + 1, r, mid + 1, R)) % MOD;
    }
}
inline ll qurryrang(ll x, ll y)
{
    ll ans = 0;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        ans += qurry(1, id[top[x]], id[x], 1, n);
        ans %= MOD;
        x = fa[top[x]];
    }
    if (id[x] > id[y])
        swap(x, y);
    ans += qurry(1, id[x], id[y], 1, n);
    return ans % MOD;
}
inline void addsontree(ll x, ll k)
{
    update(1, id[x], id[x] + size[x] - 1, 1, n, k % MOD);
}
inline ll qurrysontree(ll x)
{
    return qurry(1, id[x], id[x] + size[x] - 1, 1, n); //子树区间右端点为id[x]+siz[x]-1
}
signed main()
{
    scanf("%lld%lld%lld%lld", &n, &q, &root, &MOD);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &pic[i]);
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs1(root, 0, 1);
    dfs2(root, root);
    build(1, 1, n);
    for (ll i = 1; i <= q; i++)
    {
        ll op;
        scanf("%lld", &op);
        if (op == 1)
        {
            ll x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            rangadd(x, y, z);
        }
        if (op == 2)
        {
            ll x, y;
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", qurryrang(x, y) % MOD);
        }
        if (op == 3)
        {
            ll x, z;
            scanf("%lld%lld", &x, &z);
            addsontree(x, z);
        }
        if (op == 4)
        {
            ll x;
            scanf("%lld", &x);
            printf("%lld\n", qurrysontree(x) % MOD);
        }
    }
    return 0;
}