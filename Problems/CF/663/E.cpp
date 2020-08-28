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