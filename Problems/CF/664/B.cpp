#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
#define MAXN 200005
using namespace std;
int u[MAXN], v[MAXN], n, m, k;
typedef pair<int, int> pi;
vector<int> e[MAXN];
vector<pi> lis[MAXN];
inline int id(const pi &p) { return p.first * (p.first - 1) / 2 + p.second; }
int ans[10], key[MAXN], val[10][10], rt, cnt;
void check()
{
    int t = 0;
    for (int i = 1; i <= k; i++)
        t += val[i][ans[i]];
    if (t == rt)
        ++cnt;
}
void dfs(int i)
{
    if (i > k)
        return check();
    for (ans[i] = 1; ans[i] <= i; ans[i]++)
        dfs(i + 1);
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        rt += (key[i] = rand());
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        u[w] = x, v[w] = y;
    }
    for (int i = 1; i <= m; i++)
        e[u[i]].push_back(v[i]);
    for (int u = 1; u <= n; u++)
        for (int i = 0; i < (int)e[u].size(); i++)
            val[e[u].size()][i + 1] += key[e[u][i]];
    dfs(1);
    cout << cnt;
    return 0;
}