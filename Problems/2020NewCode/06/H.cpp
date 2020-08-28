#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll dp[128][1024];
ll sum[128][1024];
ll same[128];
int len;
char N[128];
ll dfs(int pos, int num_sum,bool lead,  bool limit)
{
    if (num_sum < 0)
        return 0;
    int up = limit ? N[len - pos] - '0' : 9;
    if (pos == 1)
    {
        return num_sum <= 9 ? min(up, num_sum) : 0;
    }
    if (!limit && !lead && dp[pos][num_sum] != -1)
        return dp[pos][num_sum];
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        ans += dfs(pos - 1, num_sum - i, lead && i == 0, limit && i == (N[len - pos] - '0'));
        ans %= MOD;
    }
    //计算完，记录状态
    if (!limit && !lead)
        dp[pos][num_sum] = ans;
    if (pos == len)
        dp[pos][num_sum] = ans;
    return ans;
}
ll dfs22(int pos,bool lead,  bool limit)
{
    int up = limit ? N[len - pos] - '0' : 9;
    if (pos == 1)
    {
        return 0;
    }
    if (!limit && !lead && same[pos] != -1)
        return same[pos];
    ll ans = 0;
    for (int i = 1; i <= up;i++)
    {
        ans += dfs22(pos - 1, lead && i == 0, limit && i == (N[len - pos] - '0'));
    }
    for (int det = 1; det <= up - 1; det++)
    {
        ans += 
    }
    for (int i = 0; i <= up; i++) //枚举，然后把不同情况的个数加到ans就可以了
    {
        ans += dfs22(pos - 1, lead && i == 0, limit && i == (N[len - pos] - '0'));
        ans %= MOD;
    }
    //计算完，记录状态
    if (!limit && !lead)
        dp[pos][num_sum] = ans;
    if (pos == len)
        dp[pos][num_sum] = ans;
    return ans;
}
int main()
{
    scanf("%s", N);
    len = strlen(N);
    memset(dp, -1, sizeof(dp));
    //memset(same, -1, sizeof(same));
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 1; i <= len * 9;i++)
    {
        dfs(len, i, true, true);
    }
    /*for (int i = 2; i <= len;i++)
        for (int j = 1; j <= len * 9;j++)
            for (int k = 1; k <= 9;k++)
                if (j - k >= 0)
                {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= MOD;
                }*/
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len * 9; j++)
            sum[i][j] = (dp[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]) % MOD;

    ll ans = 0;
    for (int i = 1; i <= len;i++)
    {
        for (int j = 1; j <= i * 9;j++)
        {
            ans += dp[i][j] * (sum[i - 1][len * 9] - sum[i - 1][j]);
            ans %= MOD;
        }
    }
}