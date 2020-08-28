#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include <utility>
#include<vector>
#include<queue>
using namespace std;
typedef long long  ll;
struct ppp{
    int val, type;
    int val2, type2;
} pic[512],pic2[512];
pair<int, int> fuck[512];
ll dp[512][512];
priority_queue<int> R, G, B;
ll ans,tot,tot_fuck,tot_pic2;
inline bool check()
{
    if (R.size() + G.size() == 0)
        return false;
    if (R.size() + B.size() == 0)
        return false;
    if (B.size() + G.size() == 0)
        return false;
    return true;
}
void mfs(int x,int y)
{
    if (x >= tot_pic2 || y >= tot_fuck)
        return;
    if (dp[x][y] != 0)
        return;
    mfs(x + 1, y + 1);
    mfs(x + 1, y);
    ll tem = pic2[x].val * fuck[y].first + pic2[x].val2 * fuck[y].second - pic2[x].val * pic2[x].val2;
    dp[x][y] = max(dp[x + 1][y], dp[x + 1][y + 1] + tem);
}
void chai(priority_queue<int> &las , int type)
{
    for (int i = 0; i < tot;i++)
    {
        if (pic[i].type != type and pic[i].type2 != type)
        {
            pic2[tot_pic2++] = pic[i];
        }
    }
    while(las.size() > 1)
    {
        int max1 = las.top();
        las.pop();
        int max2 = las.top();
        las.pop();
        fuck[tot_fuck++] = make_pair(max1, max2);
    }
    for (int i = 0; i <= tot_fuck;i++)
        dp[tot_pic2][i] = ans;
    for (int i = 0; i <= tot_pic2;i++)
        dp[i][tot_fuck] = ans;
    mfs(0, 0);
    for (int i = 0; i < tot_pic2;i++)
        for (int j = 0; j < tot_fuck;j++)
            ans = max(ans, dp[i][j]);
    // int i = 0;
    // while(las.size() > 1)
    // {
    //     int max1 = las.top();
    //     las.pop();
    //     int max2 = las.top();
    //     las.pop();
    //     for (; i < tot;i++)
    //     {
    //         if (pic[i].type != type and pic[i].type2 != type)
    //         {
    //             if (pic[i].val * max1 + max2 * pic[i].val2 > pic[i].val2 * pic[i].val)
    //             {
    //                 ans -= pic[i].val2 * pic[i].val;
    //                 ans += pic[i].val * max1 + max2 * pic[i].val2;
    //                 i++;
    //                 break;
    //             }
    //         }
    //     }
    //     if (i == tot)
    //         break;
    // }
}
int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    for (int i = 1; i <= r;i++)
    {
        int tem;
        scanf("%d", &tem);
        R.push(tem);
    }
    for (int i = 1; i <= g;i++)
    {
        int tem;
        scanf("%d", &tem);
        G.push(tem);
    }
    for (int i = 1; i <= b;i++)
    {
        int tem;
        scanf("%d", &tem);
        B.push(tem);
    }
    while(1)
    {
        if (!check())
            break;
        int max1 = -1, max2 = -1, js1 = 0, js2 = 0;
        if (!R.empty())
            max1 = R.top(),js1 = 1;
        if (!G.empty())
        {
            if (max1 == -1)
            {
                max1 = G.top();
                js1 = 2;
            }
            else
            {
                if (max1 < G.top())
                {
                    max2 = max1, js2 = js1;
                    max1 = G.top(), js1 = 2;
                }
                else if (max2 < G.top())
                {
                    max2 = G.top();
                    js2 = 2;
                }
            }
        }
        if (!B.empty())
        {
            if (max1 < B.top())
            {
                max2 = max1, js2 = js1;
                max1 = B.top(), js1 = 3;
            }
            else
            {
                if (max2 < B.top())
                {
                    max2 = B.top();
                    js2 = 3;
                }
            }
        }
        ans += max1 * max2;
        ppp jkl;
        jkl.val = max1;
        jkl.val2 = max2;
        jkl.type = js1;
        jkl.type2 = js2;
        pic[tot++] = jkl;
        if (js1 == 1 || js2 == 1)
            R.pop();
        if (js1 == 2 || js2 == 2)
            G.pop();
        if (js1 == 3 || js2 == 3)
            B.pop();
    }
    if (R.size() != 0)
        chai(R, 1);
    else if (G.size() != 0)
        chai(G, 2);
    else if (B.size() != 0)
        chai(B, 3);
    cout << ans << endl;
    return 0;
}