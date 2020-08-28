#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include<map>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7;
char S[1002][20005];
int len[1002];
int dp[1002][20005];
int upper[20005], downn[20005], dp2[2][20005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%s", S[i]);
        len[i] = strlen(S[i]);
    }
    for (int i = 0; i <= len[1];i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < len[i - 1];j++)
        {
            int tem = 0;
            for (int l = 0, r = 0; l < len[i - 1] and r < len[i];l++,r++)
            {
                if (l == j)
                {
                    r--;
                    continue;
                }
                upper[tem] = S[i - 1][l] - S[i][r];
                downn[tem] = S[i - 1][l] - S[i][r + 1];
                tem++;
            }
            dp2[0][0]
            for()
        }
    }
}
