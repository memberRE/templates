#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 3e5 + 10;
int pic[MAX];
int dp[MAX];
int main()
{
    int n;
    int maxx = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &pic[i]);
        dp[i] = 1;
    }
    for (int i = 2; i <= n;i++)
    {
        if (abs(pic[i] - pic[i - 1]) <= 2)
        {
            dp[i] = dp[i - 1] + 1;
            maxx = max(maxx, dp[i]);
        }
    }
    cout << maxx;
    return 0;
}