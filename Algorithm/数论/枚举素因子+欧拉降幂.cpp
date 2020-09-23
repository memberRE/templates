/*
    题意：给定a,b,c,d,x,y(1e6)，求出\prod_a<=i<=b \prod_c<=j<=d gcd(x^i,y^j);
    题解：由于x,y给定，所以对gcd(x,y)做出贡献的就是其相同的素因子，
    所以求出素因子p,则问题转化为对每个素因子p，求p^ {\sum{a<=i<=b}\sum{c<=j<=d}min(ti,oj)};
    这个幂次很大，所以，欧拉降幂
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
const int MOD = 998244353;
int zyz[180], x_cntt[180], y_cntt[180];
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
ll q_power(ll a, ll b, ll modd)
{
    ll res = 1;
    a %= modd;
    while (b)
    {
        if (b & 1)
            res = res * a % modd;
        a = a * a % modd;
        b >>= 1;
    }
    return res;
}
int divide_p(int n, int f[]) //质因数分解，返回质因子个数
{
    int cntt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f[++cntt] = i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        f[++cntt] = n;
    return cntt;
}
int main()
{
    int a = read(), b = read(), c = read(), d = read(), x = read(), y = read();
    int gcdd = __gcd(x, y);
    int cnt = divide_p(gcdd, zyz);
    for (int i = 1; i <= cnt; i++) //记录x,y质因子幂次
    {
        while (x % zyz[i] == 0)
        {
            x_cntt[i]++;
            x /= zyz[i];
        }
        while (y % zyz[i] == 0)
        {
            y_cntt[i]++;
            y /= zyz[i];
        }
    }
    ll finans = 1;
    for (int p = 1; p <= cnt; p++)
    {
        ll ans = 1, temm = 0;
        for (int i = a; i <= b; i++)
        {
            ll t = 1LL * i * x_cntt[p];
            ll w = t / y_cntt[p]; //分界点
            if (w < c)
            {
                temm = (temm + 1LL * (d - c + 1) * t) % (MOD - 1);
                //\phi(MOD) = MOD - 1;
                continue;
            }
            if (w >= d)
            {
                temm = (temm + 1LL * (c + d) * (d - c + 1) / 2 * y_cntt[p]) % (MOD - 1);
                continue;
            }
            ll u = 1LL * (c + w) * (w - c + 1) / 2 * y_cntt[p];
            temm = (temm + t * (d - w) + u) % (MOD - 1);
        }
        ans = ans * q_power(1LL * zyz[p], temm % (MOD - 1),MOD) % MOD;
        finans = (finans * ans % MOD + MOD) % MOD;
    }
    cout << finans << endl;
    return 0;
}
