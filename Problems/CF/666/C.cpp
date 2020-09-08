#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
const int MAX = 1e6 + 20;
int n,pic[MAX],d,r1,r2,r3;
ll dp[MAX][3];
ll ans;
int main()
{
    n = read();
    r1 = read();
    r2 = read();
    r3 = read();
    d = read();
    r1 = min(r1, r3);
    dp[0][0] = -d;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n;i++)
        pic[i] = read();
    for (int i = 1; i <= n;i++)
    {
        dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + r1 * pic[i] + r3 + d, dp[i - 1][1] + min(r1 * pic[i] + r3 + 3 * d,3*d+min(r1 * pic[i] + r1, r2) + r1)));
        dp[i][1] = min(dp[i][1], min(dp[i - 1][1] + 3 * d + min(r1 * pic[i] + r1, r2) + r1, dp[i - 1][0] + d + min(r1 * pic[i] + r1, r2) + r1));
    }
    //for (int i = 1;i)
    cout << min(dp[n][0], dp[n][1] + 2 * d + r1)<<endl;
}