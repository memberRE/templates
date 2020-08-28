#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long  ll;
int R[256], G[256], B[256];
int r, g, b;
ll dp[256][256][256];
ll ans;
void mfs(int x,int y,int z)
{
    if ((x > r and y >g) or( z >b and y >g) or (x>r and z>b))
    {
        dp[x][y][z] = 0;
        return;
    }
        
    if (dp[x][y][z] != 0)
        return;
    if (x<=r and y<=g)
    {
        mfs(x + 1, y + 1, z);
        dp[x][y][z] = max(dp[x][y][z], dp[x + 1][y + 1][z] + R[x] * G[y]);
    }
    if (x<=r and z<=b)
    {
        mfs(x + 1, y, z+1);
        dp[x][y][z] = max(dp[x][y][z], dp[x + 1][y][z + 1] + R[x] * B[z]);
    }
    if (y<=g and z<=b)
    {
        mfs(x, y + 1, z+1);
        dp[x][y][z] = max(dp[x][y][z], dp[x][y + 1][z + 1] + B[z] * G[y]);   
    }
    //dp[x][y][z] = max(dp[x + 1][y + 1][z] + R[x] * G[y], max(dp[x + 1][y][z + 1] + R[x] * B[z], dp[x][y + 1][z + 1] + B[z] * G[y]));
    ans = max(ans, dp[x][y][z]);
}
bool cam(int x,int y)
{
    return x > y;
}
int main()
{
    
    scanf("%d%d%d", &r, &g, &b);
    //memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= r;i++)
    {
        int tem;
        scanf("%d", &tem);
        R[i] = tem;
    }
    for (int i = 1; i <= g;i++)
    {
        int tem;
        scanf("%d", &tem);
        G[i] = tem;
    }
    for (int i = 1; i <= b;i++)
    {
        int tem;
        scanf("%d", &tem);
        B[i] = tem;
    }
    sort(R + 1, R + r + 1, cam);
    sort(G + 1, G + g + 1, cam);
    sort(B + 1, B + b + 1, cam);
    mfs(1, 1, 1);
    cout << ans << endl;
    return 0;
}