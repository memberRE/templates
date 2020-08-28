#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include <stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 1e6 + 20;
int n, m;
char pic[8][MAX];
int dp[MAX][12];
int main()
{
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    if ((n >= 4 && m >= 4))
    {
        puts("-1");
        while(getchar()!=EOF);
        return 0;
    }
    else if (n == 1 || m == 1)
    {
        puts("0");
        while(getchar()!=EOF);
        return 0;
    }
    if (n < m)
    {
        for (int i = 1; i <= n;i++)
            scanf("%s", pic[i] + 1);
    }
    else
    {
        getchar();
		for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                pic[j][i] = getchar();
            }
            getchar();
        }
        swap(n, m);
    }
//    for(int i = 1;i<=n;i++)
//    {
//    	for(int j = 1;j<=m;j++)
//    		cout<<pic[i][j];
//    	cout<<endl;
//	}
    	
    // ensure n < m n <=3;
    int maxdp = n == 3 ? 7 : 3;
    for (int i = 0; i <= 8;i++)
        dp[0][i] = 0;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 0; j <= maxdp;j++)
        {
            int tem = 0;
            for (int k = 1; k <= n;k++)
                tem = (tem << 1) + pic[k][i] - '0';
            tem ^= j;
            int temans = 0;
            while(tem)
            {
                temans+=tem&1;
                //tem &= -tem;
                tem >>=1;
            }
            if (maxdp == 3)
            {
                if (j == 0)
                    dp[i][j] = min(dp[i - 1][2], dp[i - 1][1]) + temans;
                if (j == 1)
                    dp[i][j] = min(dp[i - 1][3], dp[i - 1][0]) + temans;
                if (j == 2)
                    dp[i][j] = min(dp[i - 1][3], dp[i - 1][0]) + temans;
                if (j == 3)
                    dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + temans;
            }
            if (maxdp == 7)
            {
                if (j == 0)
                    dp[i][j] = min(dp[i - 1][2], dp[i - 1][5]) + temans;
                if (j == 1)
                    dp[i][j] = min(dp[i - 1][4], dp[i - 1][3]) + temans;
                if (j == 2)
                    dp[i][j] = min(dp[i - 1][0], dp[i - 1][7]) + temans;
                if (j == 3)
                    dp[i][j] = min(dp[i - 1][1], dp[i - 1][6]) + temans;
                if (j == 4)
                    dp[i][j] = min(dp[i - 1][1], dp[i - 1][6]) + temans;
                if (j == 5)
                    dp[i][j] = min(dp[i - 1][0], dp[i - 1][7]) + temans;
                if (j == 6)
                    dp[i][j] = min(dp[i - 1][4], dp[i - 1][3]) + temans;
                if (j == 7)
                    dp[i][j] = min(dp[i - 1][5], dp[i - 1][2]) + temans;
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= maxdp;i++)
        ans = min(ans, dp[m][i]);
    cout << ans << endl;
    return 0;
}
