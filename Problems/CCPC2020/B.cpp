#include <algorithm>
#include <cmath>
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
namespace MIN25 {
    const int N = 1000010;
    int prime[N], id1[N], id2[N], flag[N], ncnt, m;
    ll g[N], sum[N], a[N], T, n;
    inline int ID(ll x)
    {
        return x <= T ? id1[x] : id2[n / x];
    }
    inline ll calc(ll x)
    {
        return x * (x + 1) / 2 - 1;
    }
    inline ll f(ll x)
    {
        return x;
    }
    inline void init()
    {
        T = sqrt(n + 0.5);
        for (int i = 2; i <= T;i++)
        {
            if (!flag[i])
                prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && (ll)i * prime[j] <= T;j++)
            {
                flag[i * prime[j]] = 1;
                if (i%prime[j] == 0)
                    break;
            }
        }
        for (ll l = 1; l <= n;l = n/(n/l)+1)
        {
            a[++m] = n / l;
            if (a[m] <= T)
                id1[a[m]] = m;
            else
                id2[n / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt;i++)
            for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j];j++)
            {
                g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
            }
    }
    inline ll solve(ll x)
    {
        if (x <= 1)
            return x;
        return n = x, init(), g[ID(n)];
    }
}
int main()
{
    ll n = read();
    cout << MIN25::solve(n);
}