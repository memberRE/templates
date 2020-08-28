#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5+20;
typedef long long ll;
int head[MAX], nex[MAX << 1], to[MAX << 1];
ll val[MAX];
int sum0[MAX << 1],sum1[MAX];
int L[MAX], R[MAX];
int pic[MAX];
int tot, n,dfn;
bool check(int u)
{
    return sum[R[u]] - sum[L[u] - 1] == 0;
}
void add(int u,int v)
{
    tot++;
    to[tot] = v;
    nex[tot] = head[u];
    head[u] = tot;
}
void dfs(int u,int fa)
{
    dfn++;
    //sum[dfn] = pic[u];
    if(pic[u] == 1)
        sum0[dfn] = 1;
    else if(pic[u] == -1)
        sum1[dfn] = 1;
    L[u] = dfn;
    for (int i = head[u]; i; i =nex[i])
    {
        if (to[i] != fa)
        {
            dfs(to[i], u);
            //cnt[u] += cnt[to[i]];
        }
    }
//    dfn++;
//    sum[dfn] = pic[u];
    R[u] = dfn;
}
ll dp(int u,int fa)
{
    ll ans = 0;
    if(check(u))
    {
        ans = ((ll)cnt[u]) * val[u];
    }
    else
        return -1;
    ll tem = 0;
    for (int i = head[u]; i; i =nex[i])
    {
        if (to[i] == fa)
        	continue;
		ll jkl = dp(to[i], u);
        if (jkl == -1)
            return ans;
        tem += jkl;
    }
    ans = min(ans, tem);
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &val[i]);
        int b, c;
        scanf("%d%d", &b, &c);
        if(b!=c)
            pic[i] = b == 0 ? -1 : 1;
    }
    for (int i = 1; i <= n - 1;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 1);
    for (int i = 1; i <= dfn;i++)
        sum0[i] += sum0[i - 1];
    //ll ans = 0;
    if (sum[dfn]!=0)
    {
        cout << -1;
        return 0;
    }
    cout << dp(1, 1);
    return 0;
}
