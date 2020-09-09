#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN = 1e3 + 20;
vector<int> pic[2][MAXN];
int n, m;
inline void addedge(vector<int> grap[], int u, int v)
{
    grap[u].push_back(v);
    grap[v].push_back(u);
}
namespace TREE_HASH
{
    ull hashnum[MAXN];
    ull tree_hash(int node,vector<int> temm[])
    {
        vector<ull> stk;
        for (auto v : temm[node])
            stk.push_back(tree_hash(v,temm));
        sort(stk.begin(), stk.end());
        ull h = 28;
        for (ull i : stk)
            h = h * (ull)13131 + i;
        hashnum[node] = h;
        return h;
    }
} // namespace TREE_HASH
int main()
{
    //该版本未经测试，慎重使用
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(pic[0], u, v);
        addedge(pic[0], v, u);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(pic[1], u, v);
        addedge(pic[1], v, u);
    }
}