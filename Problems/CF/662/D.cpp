#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const int MAX = 2005;
int dp[MAX][MAX];
char s[MAX][MAX];
LL ans = 0;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = 1;
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j == 1 || j == m)
            {
                dp[i][j] = 1;
                continue;
            }
            if (s[i][j] != s[i - 1][j - 1] || s[i][j] != s[i - 1][j] || s[i][j] != s[i - 1][j + 1] || s[i][j] != s[i - 2][j])
            {
                dp[i][j] = 1;
                continue;
            }
            int x = 100000;
            x = min(min(min(min(x, dp[i - 2][j]), dp[i - 1][j + 1]), dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
            dp[i][j] = x;
        }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            ans += dp[i][j];
    printf("%lld", ans);

    return 0;
}
