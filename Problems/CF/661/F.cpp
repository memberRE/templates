#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long  ll;
const int MAX = 3005;
int dp[MAX][MAX],n,ans = 1;
int inc[MAX], no_inc[MAX];
struct ppp{
    int x, y;
} seg[MAX];
inline void init()
{
    memset(dp, -1, sizeof(dp));
    memset(inc, 0, sizeof(inc));
    memset(no_inc, 0, sizeof(no_inc));
    ans = 1;
}
bool cam(ppp a,ppp b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y > b.y;
}
int mfs(int l,int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
        return dp[l][r] = 1;
    if (l > r)
        return 0;
    int tem = mfs(l + 1, r);
    tem = max(tem, mfs(l + 1, inc[l]) + mfs(no_inc[l], r) + 1);
    dp[l][r] = tem;
    ans = max(ans, dp[l][r]);
    return dp[l][r];
    /*if (pick == 0)
        dp[node][pick] = max(mfs(node + 1, 1), mfs(node + 1, 0));
    else
    {
        int tem = 1;
        for (int i = node + 1; i <= n;i++)
        {
            if (seg[i].y <= seg[node].y)
                tem++;
            else if (seg[i].x <= seg[node].y)
                continue;
            else if (seg[i].x > seg[node].y)
            {
                tem += max(mfs(i, 1), mfs(i, 0));
                break;
            }
        }
        dp[node][pick] = tem;
    }*/
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            scanf("%d%d", &seg[i].x, &seg[i].y);
        sort(seg + 1, seg + 1 + n,cam);
        for (int i = 1; i <= n;i++)
        {
            int tem = 0;
            for (int j = i + 1; j <= n;j++)
            {
                if (seg[j].y <= seg[i].y)
                    tem++;
                else if (seg[j].x <= seg[i].y)
                    continue;
                else if (seg[j].x > seg[i].y)
                {
                    no_inc[i] = j;
                    break;
                }
            }
            inc[i] = i + tem;
            if (no_inc[i] == 0)
                no_inc[i] = n + 1;
        }
        mfs(1, n);
        // for (int i = 1; i <= 7;i++)
        // {
        //     for (int j = 1; j <= 7;j++)
        //         cout << dp[i][j] << " ";
        //     cout<<endl;
        // }
            
        printf("%d\n", ans);
    }
    return 0;
}
