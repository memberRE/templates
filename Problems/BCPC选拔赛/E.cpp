#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;
int dp[17][MAX];
int main()
{
    int n, d;
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n;i++)
        dp[0][i] = 1;

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if(j>=2)
        }
    }
    cout << dp[d][n] % MOD;
}