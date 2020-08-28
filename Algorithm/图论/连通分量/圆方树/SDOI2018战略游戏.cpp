/*
    此题为圆方树在一类连通性问题上的应用
    重点在于一个十分神奇的处理方式，按照dfs序排序

    题意：给定一个无向图，q次询问，每次询问会输入S个点，问有多少点，任意去掉其中一个都能使得这S个点不连通 \sum S <= 2e5

    题解：显然只有割点才能起到使得S个点不连通的效果，所以考虑圆方树建图，那么问题的答案就是这S个点在圆方树上两两之间的路径所经过的圆点的并集
    重点：如何去求这个并集
    解决：
        1、看到S的总和不超过2e5，是不是首先想到虚树？对，这题在圆方树上把虚树建出来，答案就出来了。（但我懒得建虚树）
        2、我们把问题转化，从圆方树上找到一个包含这个S个点的最小连通分量，那么答案就是这个最小连通分量的圆点个数-s
        那么怎么搞呢？我们将这S个点按照dfs序排序，然后我们观察一下，从第一个点走到第二个点，再从第二个点走到第三个点，。。。再从第n个点走到第一个点
        走出来的整个路径，正好把我们想找的这个连通分量的所有的边都遍历了两遍！！！！（但不是所有的点都走了两遍，lca会走过多遍）
        所以我们把点权化作其与父节点的连边的边权，用lca查询树上路径权值和，最后得到的权值除以2，减去s，别忘了，我们是把点权上放到边权，所以第1个点
        到第n个点的lca，这个点的点权会被漏掉（不明白为啥的随便画个图就明白了）（这里隐含了一个结论，一堆点以及这堆点两两的lca中，一定是dfs序最大和最小的点的lca深度最小）
        （这个结论为啥成立？想想你是怎么用欧拉序是怎么求lca的（取一段区间的最小值，上述两点的区间显然包含了其他所有两点的区间），就很显然了）
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define mem(x, y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
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

int n, m, q;
vector<int> pic[MAX];
int val[MAX << 1];
int nodde[MAX];
namespace YFT
{
    //const int MAX = MAX;
    vector<int> yf_tree[MAX << 1];
    int dfn[MAX], low[MAX], max_dfn, tot_cc;
    stack<int> stk;
    void tarjan(int u) //构造圆方树
    {
        low[u] = dfn[u] = ++max_dfn;
        stk.push(u);
        val[u] = 1;
        val[1] = 0; //这里仅仅是为了方便把点权上放到边权
        for (auto v : pic[u])
        {
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
                if (low[v] == dfn[u])
                {
                    tot_cc++;            //总的双联通分量数
                    val[tot_cc + n] = 0; //方点
                    while (!stk.empty())
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
    inline void buildYFT()
    {
        for (int i = 1; i <= n;i++)
            if (!dfn[i])
            {
                while(!stk.empty())
                    stk.pop();
                tarjan(i);
            }
    }
    inline void clear()
    {
        for (int i = 1; i <= n << 1;i++)
            yf_tree[i].clear();
        max_dfn = tot_cc = 0;
        memset(dfn, 0, sizeof(int) * (n + 1));
        memset(low, 0, sizeof(int) * (n + 1));
    }
} // namespace YFT
namespace LCA
{
    int deep[MAX << 1], fa[MAX << 1], size[MAX << 1], hson[MAX << 1];
    int id[MAX << 1], cnt, rk[MAX << 1], top[MAX << 1];
    //auto tree = YFT::yf_tree;
    int root = 1;
    bool cam(int a,int b)
    {
        return id[a] < id[b];
    }
    inline void dfs1(int u, int f, int dp)
    {
        deep[u] = dp; 
        fa[u] = f;    
        size[u] = 1; 
        if (f != -1 and f != root) //这里把点权上放到与父节点相连的边上 
            val[u] = val[f] + val[u];
        for (auto v : YFT::yf_tree[u])
        {
            if (v == f)
                continue;
            dfs1(v, u, dp + 1);
            size[u] += size[v];
            if (size[v] > size[hson[u]])
                hson[u] = v; //标记每个非叶子节点的重儿子编号
        }
    }
    inline void dfs2(ll u, ll t) //u当前节点，t当前链的最顶端的节点
    {
        top[u] = t;
        id[u] = ++cnt; //标记每个点的新编号
        rk[cnt] = u;   //反向映射
        if (!hson[u])
            return;
        dfs2(hson[u], t); //先遍历重儿子，使得重链dfs序连续，便于线段树
        for (auto v : YFT::yf_tree[u])
        {
            if (v != hson[u] and v != fa[u])
                dfs2(v, v);
        }
    }
    inline int lca(int x, int y)
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
    inline void init()
    {
        dfs1(1, -1, 1);
        dfs2(1, 1);
    }
    inline void clear()
    {
        mem(deep, 0);
        mem(fa, 0);
        mem(size, 0);
        mem(hson, 0);
        mem(id, 0);
        mem(rk, 0);
        mem(top, 0);
        cnt = 0;
    }
} // namespace LCA
inline void init()
{
    for (int i = 1; i <= n;i++)
        pic[i].clear();
    memset(val, 0, sizeof(val));
    YFT::clear();
    LCA::clear();
}
int main()
{
    int t = read();
    while(t--)
    {
        n = read();
        m = read();
        init();
        for (int i = 1; i <= m; i++)
        {
            int x = read(), y = read();
            pic[x].push_back(y);
            pic[y].push_back(x);
        }
        YFT::buildYFT();
        LCA::init();
        q = read();
        for (int i = 1; i <= q;i++)
        {
            int s = read();
            int ans = 0;
            for (int i = 1; i <= s;i++)
                nodde[i] = read();
            sort(nodde + 1, nodde + 1 + s, LCA::cam);
            nodde[s + 1] = nodde[1];
            for (int i = 1; i <= s;i++)
            {
                int lca = LCA::lca(nodde[i], nodde[i + 1]);
                ans += val[nodde[i]] + val[nodde[i + 1]] - val[lca] * 2;
            }
            ans >>= 1;
            ans -= s;
            ans += (LCA::lca(nodde[1], nodde[s]) <= n);
            printf("%d\n", ans);
        }
    }
    return 0;
}
