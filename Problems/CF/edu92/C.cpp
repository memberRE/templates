#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
bool flag[N];
int fa[N], dep[N];

int n, m, k;
vector<int> G[N];

void dfs(int x, int f, int d)
{
    dep[x] = d;
    fa[x] = f;
    for (auto y : G[x])
    {
        if (dep[y] == 0)
            dfs(y, x, d + 1);
        if (dep[x] - dep[y] + 1 >= k)
        {
            cout << 2 << endl;
            cout << dep[x] - dep[y] + 1 << endl;
            cout << y << " ";
            int z = x;
            while (z != y)
            {
                cout << z << " ";
                z = fa[z];
            }
            exit(0);
        }
    }
    if (!flag[x])
        for (auto y : G[x])
        {
            flag[y] = 1;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while (k * k < n)
        k++;

    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0, 1);
    cout << 1 << endl;
    for (int i = 1; k; i++)
    {
        if (flag[i])
            continue;
        cout << i << " ";
        k--;
    }
    return 0;
}
