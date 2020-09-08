/*
    题意：计算树上各点到其他点的距离的和的最小值（选取不同的点为根计算）
    换根dp
    假设 a 为根节点，b 为直系子节点，那么对于 b 所在子树对 a 的贡献为 dis[b]+point[b]
    ,其中 dis[b]为 b到以b为根节点的子树中所有点的距离之和。
    point[b]为以 b 为根节点的子树中的点的个数，
    其实很好理解，就相当于以 b 为根节点中的所有路径长度全部 +1，然后就到达了 a 节点。
    
    准备工作做完之后，我们就可以开始换根dp，换根dp的思想就是把与根相连的节点通过一定的操作将其变为根。
    依然利用上述节点 a,b ,将根节点从 a 移动到 b ，dp[b] 的值为：dp[a]−point[b]+(n−point[b])，其中：
    −point[b] 表示从 b 引申出来的 point[b] 条路径长度全部 −1.
    n−point[b] 表示从 a 引申出来的不包含 b 的其他路径长度全部 +1
*/
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
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
const int MAX = 1e6 + 20;
int dis[MAX], n; //第一次dfs每个节点到其子节点距离之和
int point[MAX];  //每个节点下子节点个数（包括这个节点本身）
int dp[MAX];     //最终结果
vector<int> pic[MAX];
void dfs(int u, int fa)
{
    point[u] = 1;
    for (auto v : pic[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        point[u] += point[v];
        dis[u] += point[v] + dis[v];
    }
}
void mfs(int u,int fa)
{
    for(auto v : pic[u])
    {
        if (v == fa)
            continue;
        dp[v] = dp[u] + n - 2 * point[v];
        mfs(v, u);
    }
}
int main()
{
    n = read();
    for (int i = 1; i < n;i++)
    {
        int u = read(), v = read();
        pic[u].push_back(v);
        pic[v].push_back(u);
    }
    dfs(1, -1);
    dp[1] = dis[1];
    mfs(1, -1);
    int ans = 0x7f7f7f7f;
    for (int i = 1; i <= n;i++)
        ans = min(ans, dp[i]);
    cout << ans << endl;
    return 0;
}