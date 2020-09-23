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
const int MAX = 1e5 + 80;
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
int n, m;
namespace GRAPH
{
    int head[MAX], nex[MAX << 1], to[MAX << 1], tot;
    ll node_val[MAX];
    inline void addedge(int u, int v)
    {
        tot++;
        to[tot] = v;
        nex[tot] = head[u];
        head[u] = tot;
    }
} // namespace GRAPH
namespace TREAP //维护区间加法以及子树换父亲
{
    struct NODE
    {
        ll val, sum;
        int type, segtype; //segtype即节点所表示区间的type的总和，用于更新sum
        int rnd, ch[2], size, lazy, fa;
    } treap[MAX << 1];
    int root, tot;
    inline int NEW_NODE(int val, int type) //type is not necessary
    {
        tot++;
        treap[tot].val = val * type;
        treap[tot].sum = val * type;
        treap[tot].rnd = rand();
        treap[tot].type = type;
        treap[tot].segtype = type;
        treap[tot].size = 1;
        return tot;
    }
    inline void update(int p)
    {
        treap[p].size = treap[treap[p].ch[1]].size + treap[treap[p].ch[0]].size + 1;
        treap[p].sum = treap[treap[p].ch[1]].sum + treap[treap[p].ch[0]].sum + treap[p].val;
        treap[p].segtype = treap[treap[p].ch[1]].segtype + treap[treap[p].ch[0]].segtype + treap[p].type;
    }
    inline void pushlazy(int node, ll lazy)
    {
        treap[node].val += lazy * treap[node].type;
        treap[node].sum += lazy * treap[node].segtype;
        treap[node].lazy += lazy;
    }
    inline void pushdown(int p)
    {
        // if (p and treap[p].lazy)
        // {
        //     swap(treap[p].ch[0], treap[p].ch[1]);
        //     if (treap[p].ch[0])
        //         treap[treap[p].ch[0]].lazy ^= 1;
        //     if (treap[p].ch[1])
        //         treap[treap[p].ch[1]].lazy ^= 1;
        //     treap[p].lazy = 0;
        // }
        // 以上针对区间反转，lazy为0、1表示区间是否反转。

        if (p and treap[p].lazy)
        {
            if (treap[p].ch[0])
                pushlazy(treap[p].ch[0], treap[p].lazy);
            if (treap[p].ch[1])
                pushlazy(treap[p].ch[1], treap[p].lazy);
            treap[p].lazy = 0;
        }
    }
    inline void merge(int &now, int x, int y)
    {
        pushdown(x);
        pushdown(y);
        //pushdown(now);
        if (x == 0 or y == 0)
        {
            now = x + y;
            return;
        }
        if (treap[x].rnd < treap[y].rnd)
        {
            now = x;
            merge(treap[now].ch[1], treap[x].ch[1], y);
            if (treap[x].ch[1])
                treap[treap[x].ch[1]].fa = x;
        }
        else
        {
            now = y;
            merge(treap[now].ch[0], x, treap[y].ch[0]);
            if (treap[y].ch[0])
                treap[treap[y].ch[0]].fa = y;
        }
        update(now);
        pushdown(now);
    }
    inline void split(int now, int rank, int &x, int &y)
    {
        pushdown(now);
        if (now == 0)
        {
            x = 0;
            y = 0;
            return;
        }
        if (rank == 0)
        {
            x = 0, y = now;
            return;
        }
        if (rank >= treap[now].size)
        {
            y = 0, x = now;
            return;
        }
        if (treap[treap[now].ch[0]].size + 1 <= rank)
        {
            x = now;
            split(treap[now].ch[1], rank - treap[treap[now].ch[0]].size - 1, treap[x].ch[1], y);
            treap[treap[now].ch[1]].fa = 0;
            if (treap[x].ch[0])
                treap[treap[x].ch[0]].fa = x;
            if (treap[x].ch[1])
                treap[treap[x].ch[1]].fa = x; 
            // if (x)
            //     treap[x].fa = now;
        }
        else
        {
            y = now;
            split(treap[now].ch[0], rank, x, treap[y].ch[0]);
            treap[treap[now].ch[0]].fa = 0;
            if (treap[y].ch[0])
                treap[treap[y].ch[0]].fa = y;
            if (treap[y].ch[1])
                treap[treap[y].ch[1]].fa = y; 
            // if (y)
            //     treap[y].fa = now;
        }
        update(now);
        pushdown(now);
    }
    inline int getRankById(int id)
    {
        int ans = 0, flag = 1;
        while (id)
        {
            if (flag)
                ans += treap[treap[id].ch[0]].size + 1;
            flag = (treap[treap[id].fa].ch[1] == id);
            id = treap[id].fa;
        }
        return ans;
    }

} // namespace TREAP
namespace EULAR
{
    int L[MAX], R[MAX];
    //这里L和R记录的是第一次出现的dfn代表的节点编号，和第二次的节点编号
    //使用 的时候需要哦另外计算该节点的rnk，因为括号序列是可以变的，节点rank会改变
    void dfs_eu(int node, int fa)
    {
        TREAP::merge(TREAP::root, TREAP::root, L[node] = TREAP::NEW_NODE(GRAPH::node_val[node], 1));
        for (int i = GRAPH::head[node]; i; i = GRAPH::nex[i])
            if (GRAPH::to[i] != fa)
                dfs_eu(GRAPH::to[i], node);
        TREAP::merge(TREAP::root, TREAP::root, R[node] = TREAP::NEW_NODE(GRAPH::node_val[node], -1));
    }
} // namespace EULAR

int main()
{
    n = read();
    for (int i = 2; i <= n; i++)
    {
        int tem = read();
        GRAPH::addedge(i, tem);
        GRAPH::addedge(tem, i);
    }
    for (int i = 1; i <= n; i++)
        GRAPH::node_val[i] = read();
    EULAR::dfs_eu(1, -1);
    int T = read();
    while (T--)
    {
        char S[10];
        scanf("%s", S);
        if (S[0] == 'Q')
        {
            int x = 0, y = 0;
            int node = read();
            TREAP::split(TREAP::root, TREAP::getRankById(EULAR::L[node]), x, y);
            printf("%lld\n", TREAP::treap[x].sum);
            TREAP::merge(TREAP::root, x, y);
        }
        else if (S[0] == 'C')
        {
            int x = read(), y = read();
            int a, b, c, d, e,f;
            TREAP::split(TREAP::root, TREAP::getRankById(EULAR::L[x]) - 1, a, d);
            TREAP::split(d, TREAP::getRankById(EULAR::R[x]), b, c);
            TREAP::merge(e, a, c);
            TREAP::split(e, TREAP::getRankById(EULAR::L[y]), a, c);
            TREAP::merge(f, a, b);
            TREAP::merge(TREAP::root, f, c);
        }
        else if (S[0] == 'F')
        {
            int x = read(), v = read();
            int l = TREAP::getRankById(EULAR::L[x]);
            int r = TREAP::getRankById(EULAR::R[x]);
            int a, b, c, d;
            TREAP::split(TREAP::root, l - 1, a, d);
            TREAP::split(d, r - l + 1, b, c);
            TREAP::pushlazy(b, (ll)v);
            int temm;
            TREAP::merge(temm, a, b);
            TREAP::merge(TREAP::root, temm, c);
        }
    }
}
