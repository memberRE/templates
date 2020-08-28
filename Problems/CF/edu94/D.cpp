#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long  ll;
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
const int MAX = 3e3 + 10;
int pic[MAX];
pair<int, int> seg[MAX * MAX];
int tot;
ll dp[MAX][MAX];
inline void init(int n)
{
    tot = 0;
    for (int i = 0; i <= n;i++)
        memset(dp[i], 0, sizeof(ll) * (n + 1));
}
int main()
{
    int t = read();
    while(t--)
    {
        int n = read();
        ll ans = 0;
        for (int i = 1; i <= n;i++)
            pic[i] = read();
        for (int i = 1; i <n ;i++)
            for (int j = i + 1; j <= n;j++)
                if (pic[i] == pic[j])
                {
                    seg[++tot] = {i, j};
                    dp[i][j] = 1;
                }
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        for (int tem = 1; tem <= tot;tem++)
        {
            int i = seg[tem].first, k = seg[tem].second;
            if (k == n || k - i == 1)
                continue;
            ans += (dp[k - 1][n] - dp[i][n] - dp[k - 1][k] + dp[i][k]);
        }
        init(n);
        printf("%lld\n", ans);
    }
    return 0;
}