#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX = 2e5 + 20;
typedef long long  ll;
int head[MAX], to[MAX], nex[MAX], tot,cd[MAX],rd[MAX];
int pic[MAX],n,stk[MAX],topp,vztd[MAX];
ll dp[MAX][2],ans,vall[MAX];
void mfs(int u)
{
    if (vztd[u])
        return;
    vztd[u] = 1;
    ll tem = 0;
    for (int i = head[u]; i;i = nex[i])
    {
        int v = to[i];
        mfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        if (dp[v][0] < 0 and dp[v][1] < 0)
            continue;
        if (dp[v][0] > dp[v][1])
            continue;
        else
            tem += vall[v];
     }
    ll val = tem + pic[u];
    vall[u] = val;
    dp[u][1] = dp[u][0] + val;
    if (dp[u][1] > dp[u][0])
    {
        stk[topp++] = u;
    }
}
void addedge(int x,int y)
{
    tot++;
    to[tot] = y;
    nex[tot] = head[x];
    head[x] = tot;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        scanf("%d", &pic[i]);
    for (int i = 1; i <= n;i++)
    {
        int b;
        scanf("%d", &b);
        if (b == -1)
            continue;
        rd[i]++;
        cd[b]++;
        addedge(b, i);
    }
    for (int i = 1; i <= n;i++)
    {
        if(rd[i] == 0)
        {
            mfs(i);
            ans += max(dp[i][0], dp[i][1]);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < topp;i++)
        printf("%d ", stk[i]);
    return 0;
}
