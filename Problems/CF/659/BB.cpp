#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 128;
int dp[128][256];
int pic[128];
int depth[256];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, l;
        cin >> n >> k >> l;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n;i++)
        {
            cin >> pic[i];
        }
        for (int i = 1; i <= k;i++)
            depth[i] = i;
        for (int i = k + 1; i <= 2 * k;i++)
            depth[i] = k - (i - k);
        for (int i = 0; i < 2 * k;i++)
            dp[0][i] = 1;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < 2 * k;j++)
            {
                if(dp[i][j])
                {
                    if(pic[i+1] + depth[(j+1)%(2*k)] <=l)
                        dp[i + 1][(j + 1) % (2 * k)] = 1;
                    if (i == 0)
                        continue;
                    if (pic[i] + depth[(j + 1) % (2 * k)] <= l)
                    {
                        int tem = dp[i][(j + 1) % (2 * k)];
                        dp[i][(j + 1) % (2 * k)] = 1;
                        if ((j + 1) % (2 * k) < j && tem != 1)
                            j = -1;
                    }
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < 2 * k;i++)
            if(dp[n][i] == 1)
            {
                flag = 1;
                cout << "Yes" << endl;
                break;
            }
        if(!flag)
            cout << "No" << endl;
    }
    return 0;
}