
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 3e6 + 6;
int f[12], cnt, e[2][12];
int gcd(int n, int m)
{
    return m ? gcd(m, n % m) : n;
}
void divide(int n)
{
    cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f[++cnt] = i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        f[++cnt] = n;
}
void cunt(int x, int p)
{
    for (int i = 1; i <= cnt; i++)
    {
        e[p][i] = 0;
        while (x % f[i] == 0)
        {
            e[p][i]++;
            x /= f[i];
        }
    }
}
ll power(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll solve(int a, int b, int c, int d, int p)
{
    ll ans = 1, res = 0;
    for (int i = a; i <= b; i++)
    {
        ll t = 1LL * i * e[0][p]; //cout<<"t="<<t<<endl;
        ll w = t / e[1][p];       //分界点
        if (w < c)
        {
            res = (res + 1LL * (d - c + 1) * t) % (mod - 1);
            continue;
        }
        if (w >= d)
        {
            res = (res + 1LL * (c + d) * (d - c + 1) / 2 * e[1][p]) % (mod - 1);
            continue;
        }
        ll u = 1LL * (c + w) * (w - c + 1) / 2 * e[1][p];
        res = (res + t * (d - w) + u) % (mod - 1);
    }
    ans = ans * power(1LL * f[p], res % (mod - 1)) % mod;
    return ans;
}
int main()
{
    int a, b, c, d, x, y;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &x, &y);
    int g = gcd(x, y);
    ll res = 1;
    divide(g);
    cunt(x, 0);
    cunt(y, 1);
    for (int i = 1; i <= cnt; i++)
    {
        ll tmp = solve(a, b, c, d, i);
        res = (res * tmp % mod + mod) % mod;
    }
    printf("%lld\n", res);
    return 0;
}