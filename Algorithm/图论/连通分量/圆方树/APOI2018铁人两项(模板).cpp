/*
    题意：给定一个无向图，问有多少个三元组(x,y,z)，满足从x到z有一条简单路径经过y
    题解：双联通建立圆方树，任取两个圆点，答案就是两个圆点路径的点权和,方点点权为双连通分量大小，圆点点权为-1
    （-1是为了减去任取的两个圆点x,z,同时为了去掉割点的同时计算）
    利用双连通分量两个点之间的路径必然经过分量中的所有点
*/
#include <cstring>
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long  ll;
const int MAXN = 1e5 + 20;
int n, m;
vector<int> pic[MAXN], tree[MAXN << 1];
stack<int> stk;
int dfn[MAXN],low[MAXN], max_dfn,size_cc,tot_cc;
int val[MAXN << 1];
ll ans;
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
    ++size_cc;
    for(auto v : pic[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == dfn[u])
            {
                tot_cc++;//总的双联通分量数
                val[tot_cc + n] = 0; //方点
                while(!stk.empty())
                {
                    int x = stk.top();
                    stk.pop();
                    tree[tot_cc + n].push_back(x);
                    tree[x].push_back(tot_cc + n);
                    val[tot_cc + n]++;
                    if (x == v)
                        break;
                }
                tree[tot_cc + n].push_back(u);
                tree[u].push_back(tot_cc + n);
                val[tot_cc + n]++;
            }
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}
/*
        构造完圆方树后，问题转化为，统计树中任意两点路径的权值和，
    这个可以用换根dp来做，但是很麻烦。
        考虑每个点权的贡献，其对答案的贡献 = val*经过的路径条数
*/
int vztd[MAXN << 1], siz[MAXN << 1];
void dfs(int u,int fa)
{
    vztd[u] = 1;
    siz[u] = (u <= n);//统计圆点数量，编号小于n的一定是原点
    for(auto v : tree[u])
        if (v != fa)
        {
            dfs(v, u);
		    ans += 2ll * val[u] * siz[u] * siz[v];
            // 子树各个点配对，包括了当前节点
		    siz[u] += siz[v];
        }
    ans += 2ll * val[u] * siz[u] * (size_cc - siz[u]);
    //祖先节点和子节点配对，包含了祖先节点和当前节点的配对
}
int main()
{
    n = read();
    m = read();
    memset(val, -1, sizeof(val));
    for (int i = 1; i <= m;i++)
    {
        int x = read(), y = read();
        pic[x].push_back(y);
        pic[y].push_back(x);
    }
    for (int i = 1; i <= n;i++)
        if (!dfn[i])
        {
            while(!stk.empty())
                stk.pop();
            size_cc = 0;
            tarjan(i);
            dfs(i, 0);
        }
    cout << ans << endl;
    return 0;
}