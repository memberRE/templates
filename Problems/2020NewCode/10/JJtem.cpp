/*
 *  Author  : StelaYuri
 * Language : GNU G++ 14
 */

//#pragma comment(linker,"/STACK:1024000000,1024000000")
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#include<unordered_map>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
#define closeSync            \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define multiCase \
    int T;        \
    cin >> T;     \
    for (int t = 1; t <= T; t++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repp(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define perr(i, a, b) for (int i = a; i > b; i--)
#define pb push_back
#define eb emplace_back
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
const double PI = acos(-1.0);
const double angcst = PI / 180.0;
const ll mod = 998244353;
ll max_3(ll a, ll b, ll c)
{
    if (a > b && a > c)
        return a;
    if (b > c)
        return b;
    return c;
}
ll min_3(ll a, ll b, ll c)
{
    if (a < b && a < c)
        return a;
    if (b < c)
        return b;
    return c;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll qmul(ll a, ll b)
{
    ll r = 0;
    while (b)
    {
        if (b & 1)
            r = (r + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return r;
}
ll qpow(ll a, ll n)
{
    ll r = 1;
    while (n)
    {
        if (n & 1)
            r = (r * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return r;
}
ll qpow(ll a, ll n, ll p)
{
    ll r = 1;
    while (n)
    {
        if (n & 1)
            r = (r * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return r;
}

const int maxn = 1010, N = 510, maxm = 250000;
struct MCMF
{
    struct E
    {
        int from, to, cap, v;
        E() {}
        E(int f, int t, int cap, int v) : from(f), to(t), cap(cap), v(v) {}
    };
    int n, m, s, t;
    vector<E> edges;
    vector<int> G[maxn];
    bool inq[maxn];
    int dis[maxn], pre[maxn], a[maxn];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i <= n; i++)
            G[i].clear();
        edges.clear();
        m = 0;
    }
    void addedge(int from, int to, int cap, int cost)
    {
        edges.emplace_back(from, to, cap, cost);
        edges.emplace_back(to, from, 0, -cost);
        G[from].emplace_back(m++);
        G[to].emplace_back(m++);
    }
    bool spfa()
    {
        for (int i = 0; i <= n; i++)
        {
            dis[i] = INF;
            pre[i] = -1;
            inq[i] = false;
        }
        dis[s] = 0, a[s] = INF, inq[s] = true;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u] = false;
            for (int &idx : G[u])
            {
                E &e = edges[idx];
                if (e.cap && dis[e.to] > dis[u] + e.v)
                {
                    dis[e.to] = dis[u] + e.v;
                    pre[e.to] = idx;
                    a[e.to] = min(a[u], e.cap);
                    if (!inq[e.to])
                    {
                        inq[e.to] = true;
                        Q.push(e.to);
                    }
                }
            }
        }
        return pre[t] != -1;
    }
    int solve()
    {
        int flow = 0, cost = 0;
        while (spfa())
        {
            flow += a[t];
            cost += a[t] * dis[t];
            int u = t;
            while (u != s)
            {
                edges[pre[u]].cap -= a[t];
                edges[pre[u] ^ 1].cap += a[t];
                u = edges[pre[u]].from;
            }
        }
        return cost;
    }
};

struct node
{
    int to, next;
} e[N], e2[N];
int root1, root2, cnt1, head1[N], cntt1[N], cnt2, head2[N], cntt2[N];
ull hashnum[N], hashnum2[N]; //两棵树每个节点对应子树的hash值

void addedge1(int x, int y)
{
    e[cnt1].to = y;
    e[cnt1].next = head1[x];
    head1[x] = cnt1++;
    cntt1[x]++;
}
void addedge2(int x, int y)
{
    e2[cnt2].to = y;
    e2[cnt2].next = head2[x];
    head2[x] = cnt2++;
    cntt2[x]++;
}

ull f_hash(int x)
{
    vector<ull> v;
    for (int i = head1[x]; ~i; i = e[i].next)
        v.push_back(f_hash(e[i].to));
    sort(v.begin(), v.end());
    ull h = 28;
    for (ull i : v)
        h = h * (ull)13131 + i;
    hashnum[x] = h;
    return h;
}
ull f_hash2(int x)
{
    vector<ull> v;
    for (int i = head2[x]; ~i; i = e2[i].next)
        v.push_back(f_hash2(e2[i].to));
    sort(v.begin(), v.end());
    ull h = 28;
    for (ull i : v)
        h = h * (ull)13131 + i;
    hashnum2[x] = h;
    return h;
}

int match(int p1, int p2)
{
    if (head1[p1] == -1 && head2[p2] == -1)
        return (p1 == p2 ? -1 : 0); //假如这两个节点都没有子树，则直接返回两节点编号是否相同

    int bas = cntt1[p1] + cntt2[p2];
    MCMF f;
    f.init(bas + 2, bas + 1, bas + 2); //建立最小费用最大流

    for (int i = head1[p1], ii = 0; ~i; i = e[i].next, ii++)
    {
        f.addedge(f.s, ii, 1, 0); //源点向树1上节点的子节点连边，流量为1花费为0
        for (int j = head2[p2], jj = 0; ~j; j = e2[j].next, jj++)
        {
            if (hashnum[e[i].to] == hashnum2[e2[j].to])                     //如果两棵树同构
                f.addedge(ii, jj + cntt1[p1], 1, match(e[i].to, e2[j].to)); //建立流量为1花费为子节点匹配结果的边
        }
    }
    for (int j = head2[p2], jj = 0; ~j; j = e2[j].next, jj++)
        f.addedge(jj + cntt1[p1], f.t, 1, 0); //树2上节点的子节点向汇点连边，流量为1花费为0

    return f.solve() + (p1 == p2 ? -1 : 0); //这里还得加上对p1和p2编号的判断
}

void solve()
{
    mst(head1, -1);
    mst(head2, -1);
    int n, d;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> d;
        if (d)
            addedge1(d, i);
        else
            root1 = i;
    }
    rep(i, 1, n)
    {
        cin >> d;
        if (d)
            addedge2(d, i);
        else
            root2 = i;
    }
    f_hash(root1);
    f_hash2(root2);                          //先做两遍树上哈希
    cout << n + match(root1, root2) << '\n'; //匹配得到的值为负数，表示能够直接匹配的最大对数
}
int main()
{
    closeSync;
    solve();
    return 0;
}