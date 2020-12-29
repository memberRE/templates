#define DIN freopen("input.txt", "r", stdin);
#define DOUT freopen("output.txt", "w", stdout);
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define REP_(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
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

const int maxn = 1e5 + 5;
int n;
LL L, R, a[maxn], l[maxn], r[maxn], suml, sum;

bool can(LL x)
{
    REP(i, 1, n)
    if (x * l[i] > a[i]) return 0;
    LL cha = x * (L - suml);
    LL bu = 0;
    REP(i, 1, n)
    {
        bu += min(a[i] - x * l[i], (r[i] - l[i]) * x);
    }
    return bu >= cha;
}

int main()
{
    n = read();
    L = read(), R = read();
    REP(i, 1, n)
    a[i] = read();
    REP(i, 1, n)
    l[i] = read(),
    r[i] = read();
    REP(i, 1, n)
    suml += l[i],
        sum += a[i];

    if (suml > R)
        return puts("0"), 0;
    else if (suml >= L && suml <= R)
    {
        LL ans = 1e9;
        REP(i, 1, n)
        if (l[i]) ans = min(ans, a[i] / l[i]);
        //REP(i,1,n) ans=min(ans,a[i]/l[i]);
        cout << ans;
    }
    else // suml<L
    {
        LL left = 0, right = 1e9 + 5, mid;
        while (left < right - 1)
        {
            mid = (left + right) / 2;
            if (can(mid))
                left = mid;
            else
                right = mid;
        }
        cout << left;
    }

    return 0;
}
