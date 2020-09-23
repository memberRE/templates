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
namespace PRI
{
    const int maxn = 1e6 + 5, N = 1e6;
    bool isprime[maxn];
    int prime[maxn], tot;
    void init()
    {
        for (int i = 2; i <= N; i++)
            isprime[i] = 1;
        for (int i = 1; i <= N; i++)
            if (isprime[i])
                for (ll j = 1ll * i * i;j <= N; j += i)
                    isprime[j] = 0;
        // REP(i, 2, N)
        for (int i = 2; i <= N; i++)
            if (isprime[i])
                prime[++tot] = i;
    }
} // namespace PRI

int L[32],jkl;
int dp[10];          //{不能分成技术，分一次技术，分两次技术，多次偶次幂，多次几次幂}
int divide_p(int n) //质因数分解，返回质因子个数
{
    //int cntt = 0;
    int has2 = 0;
    int ans = 0;
    if (n % 2 == 0)
    {
        has2 = 1;
        while (n % 2 == 0)
            n /= 2;
    }
    for (int i = 2; i<= PRI::tot && PRI::prime[i]*PRI::prime[i]<=n; i++)
    {
        if (n % PRI::prime[i] == 0)
        {
            while (n % PRI::prime[i] == 0)
                n /= PRI::prime[i], ans++;
        }
    }
    if (n > 1)
        ans++;
    int temm = 0;
    if (has2)
    {
        if (ans <= 2)
            dp[ans]++,temm = 1;
        else if ((ans + 1) % 2 == 0)
            dp[3]++;
        else
            dp[4]++;
        return temm == 1?0: ans;
    }
    else
    {
        if (ans - 1 <= 2)
            dp[ans - 1]++,temm = 1;
        else if (ans % 2 == 0)
            dp[3]++;
        else
            dp[4]++;
        return temm == 1?0: ans - 1;
    }
}
inline int check(int k)
{
    if (/*dp[3] == dp[4] and dp[3] == 0*/ !jkl)
    {
        return k ^ 1;
    }
    else
        return k;
}
int main()
{
    int t = read();
    PRI::init();
    while (t--)
    {
        int n = read();
        int tem = 0;
        memset(dp, 0, sizeof(dp));
        jkl = 0;
        for (int i = 1; i <= n; i++)
        {
            L[i] = read();
            if (L[i] == 1)
                continue;
            jkl += divide_p(L[i]);
        }
        jkl %= 2;
        for (int i = 0; i <= 4; i++)
            dp[i] %= 2;
        if (dp[0] == dp[1] and dp[1] == dp[2])
        {
            tem = check(0);
        }
        else
            tem = check(1);
        if (tem == 0)
            puts("W");
        else
            puts("L");
    }
    return 0;
}