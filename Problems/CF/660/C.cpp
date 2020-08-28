#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 1e5 + 20;
const int MAXM = 2e5 + 40;
int head[MAXN], to[MAXM], nex[MAXM], tot;
int sumpeo[MAXN],selflaf[MAXN],selfcry[MAXN],totlaf[MAXN],totcry[MAXN];
int P[MAXN], H[MAXN];
int n, m,flag = 0;
void addedge(int x,int y)
{
    tot++;
    to[tot] = y;
    nex[tot] = head[x];
    head[x] = tot;
}
void init()
{
    memset(head, 0, sizeof(head));
    tot = 0;
    flag = 0;
}
void dfs(int u,int fa)
{
    int temlaf = 0, temcry = 0;
    sumpeo[u] = P[u];
    for (int i = head[u]; i;i = nex[i])
    {
        if (to[i] == fa)
            continue;
        else
            dfs(to[i], u);
        temlaf += totlaf[to[i]];
        temcry += totcry[to[i]];
        sumpeo[u] += sumpeo[to[i]];
    }
    // int doulaf = H[u] + sumpeo[u] - 2 * temlaf;
    // if (doulaf < 0 || doulaf %2 != 0)
    //     flag = 1;
    // selflaf[u] = doulaf / 2;
    // int doucry = sumpeo[u] - H[u] - 2 * temcry;
    // if (doucry < 0 || doucry %2 != 0)
    //     flag = 1;
    // selfcry[u] = doucry / 2;
    // totlaf[u] = selflaf[u] + temlaf;
    // totcry[u] = selfcry[u] + temcry;

    int doulaf = H[u] + sumpeo[u];
    if (doulaf < 0 || doulaf %2 != 0)
        flag = 1;
    totlaf[u] = doulaf / 2;
    int doucry = sumpeo[u] - H[u];
    if (doucry < 0 || doucry %2 != 0)
        flag = 1;
    totcry[u] = doucry / 2;
    if (temlaf > totlaf[u])
        flag = 1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n;i++)
            scanf("%d", &P[i]);
        for (int i = 1; i <= n;i++)
            scanf("%d", &H[i]);
        for (int i = 1; i <= n - 1;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        dfs(1, -1);
        if (!flag)
        {
            puts("Yes");
        }
        else
            puts("No");
        
    }
    return 0;
}