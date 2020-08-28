/*
    题意：
        给定一个无向图，每个点有点权，1e5个询问，每次查询两点之间简单路径（可能有多条）上的权值最小的点的权值,支持修改点权
    题解：
        双联通建立圆方树，方点维护双联通分量中点权最小的点，那么在不考虑修改的情况下，原询问等价于静态树上路径最小点权，树剖即可。
    考虑暴力修改点权，每次更改更新其周围的方点，但是菊花图会卡。
    重点：
        将方点维护的权值改为其所有子节点（一定是圆点）的权值最小值，那么更改权值的时候只要修改一次，但是如何保证查询的正确性？
        考虑如果依旧按照原本的方式查询路径最小点权，其在哪种情况下不正确，当然是在更新方点最小值的时候，改变割点的权值却只更新了一个方点的数据
    如何解决：
        如果查询的两个节点的lca是个方点，那么最后答案还要和fa[lca(u,v)]的点权相比较。
    为何？
        假设lca不是方点，那么对于这条路径上的方点的父亲，也一定在这条路径上，所以即使方点没有被更新好，其父亲一定是更新好的，这样答案是正确的
        如果lca是方点，那么它的父亲一定不在路径上，如果父亲的权值更新，这个lca不会被更新，所以要和父亲再比较一番。
*/
#include <cstring>
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
typedef long long  ll;
const int MAXN = 1e5 + 20;
const int INF = 0x7f7f7f7f;
int n, m,q;
vector<int> pic[MAXN], yf_tree[MAXN << 1];
stack<int> stk;
multiset<int> set_cc[MAXN << 1];
int dfn[MAXN],low[MAXN], max_dfn,tot_cc;
int val[MAXN << 1],deep[MAXN<<1],fa[MAXN<<1],sizee[MAXN<<1],hson[MAXN<<1];
int top[MAXN << 1], id[MAXN << 1], rk[MAXN << 1],cnt;// cnt is zhe max_dfn
int mmin[MAXN << 3], lazy[MAXN << 3];//八倍空间，，别忘了
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
void tarjan(int u)//构造圆方树
{
    low[u] = dfn[u] = ++max_dfn;
    stk.push(u);
    for(auto v : pic[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == dfn[u])
            {
                tot_cc++;//总的双联通分量数
                while(!stk.empty())
                {
                    int x = stk.top();
                    stk.pop();
                    yf_tree[tot_cc + n].push_back(x);
                    yf_tree[x].push_back(tot_cc + n);
                    if (x == v)
                        break;
                }
                yf_tree[tot_cc + n].push_back(u);
                yf_tree[u].push_back(tot_cc + n);
            }
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}
inline void dfs1(ll u, ll father, ll dp)
{
    deep[u] = dp;   //标记每个点的深度 
    fa[u] = father;      //标记每个点的父亲 
    sizee[u] = 1;    //标记每个非叶子节点的子树大小 
    if(u > n)   //如果u是方点，更新其点权
        val[u] = 0x7f7f7f7f;
    for (auto v : yf_tree[u])
    {
        if (v == father)
            continue;
        if (u > n)
            val[u] = min(val[u], val[v]),set_cc[u].insert(val[v]);
        dfs1(v, u, dp + 1);
        sizee[u] += sizee[v];
        if (sizee[v] > sizee[hson[u]])
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
    for (auto v : yf_tree[u])
    {
        if (v != hson[u] and v != fa[u])
            dfs2(v, v);
    }
}
void build(int node,int l,int r)
{
    if (l == r)
    {
        mmin[node] = val[rk[l]];
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    mmin[node] = min(mmin[ls] , mmin[rs]);
}
inline void pushdow(ll node)
{
    lazy[ls] = min(lazy[node],lazy[ls]);
    lazy[rs] = min(lazy[node],lazy[rs]);
    mmin[ls] = min(lazy[node],mmin[ls]);
    mmin[rs] = min(lazy[node],mmin[rs]);
    lazy[node] = INF;
}
inline void update(int node, int l, int r, int L, int R, int k)
{
    if (l == L and R == r)
    {
        mmin[node] = k; //min(mmin[node], k);
        lazy[node] = min(lazy[node],k);
        return;
    }
    else
    {
        if (lazy[node] != INF)
            pushdow(node);
        int mid = (L + R) >> 1;
        if (r <= mid)
            update(node << 1, l, r, L, mid, k);
        else if (l >= mid + 1)
            update((node << 1) | 1, l, r, mid + 1, R, k);
        else
        {
            update(node << 1, l, mid, L, mid, k);
            update((node << 1) | 1, mid + 1, r, mid + 1, R, k);
        }
        mmin[node] = min(mmin[ls], mmin[rs]);
    }
}
inline int qurry(int node, int l, int r, int L, int R)
{
    if (l == L and r == R)
        return mmin[node];
    else
    {
        if (lazy[node])
            pushdow(node);
        ll mid = (L + R) >> 1;
        if (r <= mid)
            return qurry(node << 1, l, r, L, mid);
        else if (l >= mid + 1)
            return qurry((node << 1) | 1, l, r, mid + 1, R);
        else
            return min(qurry(node << 1, l, mid, L, mid) , qurry((node << 1) | 1, mid + 1, r, mid + 1, R));
    }
}
inline int qurryrang(int x, int y)
{
    int ans = 0x7f7f7f7f;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        ans = min(qurry(1, id[top[x]], id[x], 1, cnt),ans) ;
        x = fa[top[x]];
    }
    if (id[x] > id[y])
        swap(x, y);
    ans = min(qurry(1, id[x], id[y], 1, cnt),ans);
    return ans;
}
inline int lca(int x,int y)
{
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    if (id[x] > id[y])
        swap(x, y);
    return x;
}
int main()
{
    n = read();
    m = read();
    q = read();
    memset(lazy, 0x7f, sizeof(lazy));
    for (int i = 1; i <= n;i++)
        val[i] = read();
    for (int i = 1; i <= m;i++)
    {
        int x = read(), y = read();
        pic[x].push_back(y);
        pic[y].push_back(x);
    }
    // init yf_tree
    for (int i = 1; i <= n;i++)
        if (!dfn[i])
        {
            while(!stk.empty())
                stk.pop();
            tarjan(i);
        }
    // init sp
    dfs1(1, -1, 1);
    dfs2(1, 1);
    build(1, 1, cnt);
    for (int i = 1; i <= q;i++)
    {
        char SS[5];
        scanf("%s", SS);
        if (SS[0] == 'C')
        {
            int x = read(), w = read();
            int cc = fa[x];
            if (cc != -1)
            {
                set_cc[cc].erase(val[x]);
                set_cc[cc].insert(w);
                val[cc] = *set_cc[cc].begin();
                update(1, id[cc], id[cc], 1, cnt, val[cc]);
            }
            val[x] = w;
            update(1, id[x], id[x], 1, cnt, w);
        }
        else
        {
            int x = read(), y = read();
            int ans = qurryrang(x, y);
            int lcaa = lca(x, y);
            if (lcaa > n)
                ans = min(ans, val[fa[lcaa]]);
            printf("%d\n", ans);
        }
    }
    return 0;
}