# CF Edu Round 92

## E（简单数论，有一个有用的处理方法）

### 题意

​	给定d,m,w<=1e9,找到有多少个二元组$(x,y)$满足$1<=x<=d,1<=y<=m$且$dy+x = dx +y(\mod w)$

### 题解

​	化简得：$(d-1)(x-y) = 0 \mod m$

​	所以：$(x-y) = k*w/(d-1)$k为正整数

​	**所以：$(x - y) = t*lcm(w,d-1)/(d-1)$，t为正整数**

​	下面很容易发现结果的统计就是等差数列求和

### code

```cpp
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll m, d, w;
        cin >> m >> d >> w;
        if (d == 1)
        {
            cout << "0\n";
            continue;
        }
        ll g = __gcd(w, d - 1);
        ll tem = w / g;
        d = min(m, d);
        ll topp = d / tem;
        ll ans = (d - tem + d - topp * tem) * topp / 2;
        cout << ans << endl;
    }
    return 0;
}

```

## F（一堆线段 · 类dp的处理）

### 题意

给定$n<=2e5$条线段，每条线段为红色或者蓝色，问你最多选择多少条线段，使得选择的这些线段中，任取两条线段，其要么不相交，要么颜色相同。

### 题解

#### 解法一

​	我们将线段抽象成点，两个点之间连边当且仅当这两边不符合条件，显然这是一个二分图，所以我们就是要求其中的最大独立集，最大独立集 = 点数 - 最大匹配。所以我们来思考如何求这个最大匹配。

​	传统的网络流，匈牙利这种万能算法显然会TLE，但这题我们用贪心来匹配。

​	我们将每个线段的每个端点抽象成一个事件三元组：{端点坐标，0/1表示起点或者终点，所属线段id}

​	然后按照端点坐标排序，坐标相同则起点放前面。

​	从小到大遍历这些事件，开两个集合代表红色和蓝色，储存当前遍历到的事件。

​	如果当前事件是起点，那么直接将其代表线段的终点放入到对应集合；

​	如果是终点，则在颜色不同的那个集合中，查找终点坐标最小的那个线段，将其配对（一定可以配对，且这样一定是最优，思考一下，我们的这些事件是按照坐标排序的，最优性就很容易理解了），然后在另一个集合（与自己颜色相同的那个集合）中删掉自己对应的线段（如果遍历到终点，那么这个线段的起点一定先被遍历到，所以一定存在）。

### 解法2（感觉这个更好想）

​	**线段树优化DP**

​	先离散化, 令$dp[i]$表示范围$[1,i]$能选择的最大线段数. 

​	d[i]=max{d[i],d[j]+[j+1,i]中红色线段数量},

​	d[i]=max{d[i],d[j]+[j+1,i]中蓝色线段数量},

​	对两种颜色分别开一棵线段树, 红色线段树每个叶子x存储**d[x]+([x,i]内红色线段数量)** 显然每次遇到红色线段[l,i],将红色线段树中的[0,l-1]全部加上1, 那么d[i]就是max(红色线段树[0,i-1]最大值,蓝色线段树[0,i-1]最大值).

#### code

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

typedef long long ll;
using namespace std;
const int MAX = 2e5 + 20;
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
struct SEG
{
    int l, r, t;
} pic[MAX];
int n, cnt, max_num;
int dis_seg[MAX << 1];
int dp[MAX << 1];
vector<int> seg[2][MAX << 1], seg2[MAX << 1];
inline int discrete(int tem[], int cntt)
{
    sort(tem + 1, tem + 1 + cntt);
    int nN = unique(tem + 1, tem + 1 + cntt) - tem - 1;
    return nN;
}
template <class T>
struct SEG_TREE
{
#define ls (node << 1)
#define rs ((node << 1) | 1)
    T *tree, *laz;
    int n;
    // int maxx[MAX << 3];
    // int laz[MAX << 3];
    SEG_TREE(int n)
    {
        tree = new T[n << 2]();
        laz = new T[n << 2]();
        this->n = n;
    }
    inline void pushup(int node)
    {
        tree[node] = max(tree[ls], tree[rs]);
    }
    inline void pushdown(int node)
    {
        if (laz[node])
        {
            laz[ls] += laz[node];
            laz[rs] += laz[node];
            tree[ls] += laz[node];
            tree[rs] += laz[node];
            laz[node] = 0;
        }
    }
    void update(int node, int l, int r, int val, int L, int R)
    {
        if (l <= L and R <= r)
        {
            tree[node] += val;
            laz[node] += val;
            return;
        }
        pushdown(node);
        int mid = (L + R) >> 1;
        if (l <= mid)
            update(ls, l, r, val, L, mid);
        if (r >= mid + 1)
            update(rs, l, r, val, mid + 1, R);
        pushup(node);
    }
    T query(int node, int l, int r, int L, int R)
    {
        if (l <= L and R <= r)
            return tree[node];
        pushdown(node);
        int mid = (L + R) >> 1;
        T ans = 0;
        if (l <= mid)
            ans = max(ans, query(ls, l, r, L, mid));
        if (r >= mid + 1)
            ans = max(ans, query(rs, l, r, mid + 1, R));
        return ans;
    }
    void build(int node, int l, int r, T tar[])
    {
        if (l == r)
            tree[node] = tar[l];
        else
        {
            int mid = (l + r) >> 1;
            build(ls, l, mid, tar);
            build(rs, mid + 1, r, tar);
            pushup(node);
        }
    }
};
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        pic[i].l = read();
        pic[i].r = read();
        pic[i].t = read() - 1;
        dis_seg[++cnt] = pic[i].l;
        dis_seg[++cnt] = pic[i].r;
    }
    max_num = discrete(dis_seg, cnt);
    for (int i = 1; i <= n; i++)
    {
        pic[i].l = lower_bound(dis_seg + 1, dis_seg + 1 + max_num, pic[i].l) - dis_seg;
        pic[i].r = lower_bound(dis_seg + 1, dis_seg + 1 + max_num, pic[i].r) - dis_seg;
        seg[pic[i].t][pic[i].r].push_back(pic[i].l);
    }
    SEG_TREE<int> t1(max_num), t2(max_num);
    for (int i = 1; i <= max_num; i++)
    {
        for (auto l : seg[0][i])
            t1.update(1, 0, l - 1, 1, 0, max_num);
        for (auto l : seg[1][i])
            t2.update(1, 0, l - 1, 1, 0, max_num);
        dp[i] = max(dp[i], t1.query(1, 0, i - 1, 0, max_num));
        dp[i] = max(dp[i], t2.query(1, 0, i - 1, 0, max_num));
        t1.update(1, i, i, dp[i], 0, max_num);
        t2.update(1, i, i, dp[i], 0, max_num);
    }
    cout << dp[max_num] << endl;
    return 0;
}
```

## G（边双缩点+换根dp）

### 题意：

​		给定一个无向图，1e5个点和边，无重边,无自环，每个点有点权，边有边权，有k个点是特殊点，现在你可以给这个无向图的每条边赋一个方向变成有向边，也可以使其保持无向，最终的花费是所有保持无向的边的权值和。现在定义饱和点：所有的特殊点都可以到达的点叫饱和点。每有一个饱和点，你能获得的收益就是这个点的点权。现在需要输出，如果你不得不让第$i$个点变为饱和点，那么你的最大收益是多少。输出n个数，即$(1<=i<=n)$都要输出。

### 题解：

​		首先，对于一个边双连通分量，由于任意两点之间至少存在两条边不重复路径，因此可以通过将其所有边修改为有向边使其成为一个强连通分量。对于一个强连通分量，只要其中一个点饱和，则其余点都饱和，边双缩点，将其转化为树上问题。

​		缩点后，以某个特殊点所在连通分量所代表的点为根，如果以某个点为根的子树中不含关键节点，则这棵子树无需向外连边，即子树上的所有点都只连一条到子节点的有向边即可，不需要花费连无向边的费用，因此可以将该子树上的点全部合并到根节点的父节点上。最终构造出来的树的根节点和所有叶子节点都含关键节点。

​		这里解释一下为什么要以某个关键节所在点为根：因为在后面树形dp的时候首先默认了对于当前dp的点，其子树上所有点都能到达它，而不含关键节点的点不需要其他点都能到达它如果加反边会增加不必要的花费，结果不是最优。

​		设$f[x]$为以x为根的子树中如果饱和点包含x，那么最大收益为$f[x]$。

​		这里的饱和点的含义是：如果x为根节点则所有以x为根的子树中所有的关键节点都能到达该点，否则x为整个树上的饱和点，但是算收益时只减去子树内的边(后面转移的时候会考虑上其余边)。
状态转移方程为：$f[x] = val[x]+\sum max(0,f[y] - w_{x,y})$  y是x的子节点

​		状态转移方程的含义为首先假设子树上的所有点都能到达x，那么x为饱和点，此时收益为val[x]，如果对于子节点y，如果以y为根的子树中的一些点也想成为饱和点，那么需要在当前收益上加上$f[y]-w_{x,y}$考虑到最大收益，因此只加为正的时候的，$f[root]$为保证根节点是饱和点时的最大收益。

由于题目中要求求出对于每个点，保证该点为饱和点时的最大收益，因此还需要进行换根dp

状态转移方程为：$f[y]=f[y]+\max (0,f[x]-\max (0,f[y]-w_{x,y})-w_{x,y})$

​		这里x为y的父节点。保证y点为饱和点时的最大收益，为以y为根节点时的最大收益加上父节点x对$f[y]$的贡献再减去$w_{x,y}$。而父节点x对f[y]的贡献为保证x点为饱和点时的最大收益减去以y为根的子树对其的贡献。

​		最终复杂度$O(n)$

### code

```cpp
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
```

