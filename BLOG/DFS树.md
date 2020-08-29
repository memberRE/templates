# DFS树

## 概念

**树边：**dfs过程中直接走过的边

**回边：**dfs过程中因为已经访问过的原因不去走的边

## 结论

- dfs树中，**回边连接的一定是一个顶点以及其一个子孙节点**。

- 当且仅当树边 uv 不存在连接其祖先和子孙节点的回边时，它是桥。也就是说，树边 uv 是桥当且仅当此时没有回边跨越它
- 回边一定不是桥
## 用途

无向图的dfs树，一般用于：仙人掌图；与环相关的问题；用于思考与解释一些不太显然的贪心与构造算法

有向图的dfs树，构造支配树，强连通。

## 例题

### CF1325F Ehab's Last Theorem

**题意：**给定一个n个节点的无向图，无重边自环，需要你在以下两个条件中任意找到一个：

- 找到一个长度大于$ceil(\sqrt{n})$的环
- 找到一个大小正好为$ceil(\sqrt{n})$的独立集，即集合中任意两点不直接相连

**题解：**

​		首先看找环：在dfs树中，如果一条回边，正好跨过了树边长度大于指定长度的深度，那么显然能找到满足第一个条件的环。

​		否则：dfs树上的每一个节点，一定不会有多于$\sqrt{n}$条回边（注意：回边属于一个点当且仅当这条回边连接了该点和一个dfs序小于这个点的点），所以可以从深度从大到小，取出节点，并且标记不能访问的节点，这样每次不能访问的节点一定不会超过根号n，所以一定能找到符合第二个条件的独立集。

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
bool flag[N];
int fa[N], dep[N];

int n,m,k;
vector<int> G[N];

void dfs(int x,int f,int d) {
    dep[x] = d;
    fa[x] = f;
    for(auto y:G[x]) {
        if(dep[y]==0)
            dfs(y,x,d+1);
        if(dep[x]-dep[y]+1>=k) {
            cout<<2<<endl;
            cout<<dep[x]-dep[y]+1<<endl;
            cout<<y<<" ";
            int z = x;
            while(z!=y) {
                cout<<z<<" ";
                z = fa[z];
            }
            exit(0);
        }
    }
    if(!flag[x])
        for(auto y:G[x]) {
            flag[y] = 1;
        } 
}

int main() {
    ios::sync_with_stdio(0);
    cin>>n>>m;
    while(k*k<n) k++;

    for(int i=0,a,b;i<m;i++) {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0,1);
    cout<<1<<endl;
    for(int i=1; k; i++) {
        if(flag[i]) continue;
        cout<<i<<" ";
        k--;
    }
    return 0;
}
```

### CF Round 663E

**题意：**给定一个无向图，无重边无自环，需要你在以下两个条件中任意找到一个：

- 存在一条简单路径（路径上每个点只经过一次），这条简单路径覆盖了至少n/2向上取整个点
- 可以从图中选出至少n/2向上取整个点，将其两两分组，任意两组点(A,B),(C,D)，原图中这四个点的诱导子图，至多有两条边。

**题解：**

​		构造图的dfs树，如果树的最大高度超过了n/2，那么显然存在符合条件1的路径。

​		否则，我们将处在dfs树同一高度的这些点，两两配对，因为最大高度不超n/2，所以一定能取符合条件2的个数要求的点，下面思考这些点为何符合条件2。

​		首先，由于每一组都是dfs树中的相同高度，所以组内两个点一定不直接相连。下面任取两个组，考虑组间的连边，不妨设这两个组分别为$(A,B),(C,D)$，且第一组的深度小于等于第二组。

​		考虑第一种情况（以下全部在dfs树中考虑）：A是C和D的祖先，那么A有可能与这两个点都有连边，但此时C和D不在B的子树内（因为A和B高度相同），不可能有边相连（**回边只会连接一个节点与其祖先节点，即不存在横跨边**），此时至多有两条边，符合条件。

​		考虑第二种情况，A是C的祖先，B是D的祖先，那么此时最多也只有AC,BD两条边，符合。

​		第三种：这几个点没有祖先关系，那么一定 没有边相连。

​		$Q.E.D.$

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#define ls (node << 1)
#define rs ((node << 1) | 1)
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
const int MAX = 5e5 + 20;
int n, m, flag,max_dep;
int vztd[MAX], dep[MAX];
vector<int> pic[MAX], ans[MAX];
vector<pair<int, int>> outp;
stack<int> stk;
void dfs(int u, int deep)
{
    if (flag)
        return;
    dep[u] = deep;
    vztd[u] = 1;
    max_dep = max(max_dep, deep);
    ans[deep].push_back(u);
    stk.push(u);
    if (deep >= (n + 1) >> 1)
    {
        flag = 1;
        puts("PATH");
        printf("%d\n", deep);
        while(!stk.empty())
        {
            int tem = stk.top();
            stk.pop();
            printf("%d ", tem);
        }
        puts("");
        return;
    }
    for(auto v : pic[u])
    {
        if (vztd[v])
            continue;
        //stk.push(v);
        // vztd[v] = 1;
        dfs(v, deep + 1);
    }
    if (!stk.empty())
        stk.pop();
}
int main()
{
    int t = read();
    while (t--)
    {
        n = read();
        m = read();
        flag = 0;
        max_dep = 0;
        for (int i = 1; i <= n; i++)
            pic[i].clear(), ans[i].clear(), vztd[i] = dep[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read();
            pic[u].push_back(v);
            pic[v].push_back(u);
        }
        while(!stk.empty())
            stk.pop();
        dfs(1, 1);
        if (!flag)
        {
            puts("PAIRING");
            outp.clear();
            for (int i = 1; i <= max_dep;i++)
            {
                for (int j = 0; j + 1 < ans[i].size();j+=2)
                    outp.push_back({ans[i][j], ans[i][j + 1]});
            }
            printf("%d\n", outp.size());
            for(auto v : outp)
                printf("%d %d\n", v.first, v.second);
        }
    }
    return 0;
}
```

