#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX = 1024;
const int INF = 0x3f3f3f3f
int dp[MAX][1 << 16];
int marx[5][5], tem[5][5];
int val[5],pic[MAX];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 4;i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= n;i++)
    {
        char tem[8];
        scanf("%s", tem);
        for (int j = 0; j <= 3;j++)
        {
            pic[i] <<= 1;
            pic[i] += tem[j] == '.' ? 0 : 1;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    
}