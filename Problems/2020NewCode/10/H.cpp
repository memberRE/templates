#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int pic[302][302],n;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(pic, 0, sizeof(pic));
        for (int i = 1; i <= n;i+=2)
            for (int j = 1; j <= n;j+=2)
                pic[i][j] = 1;
        if (n % 2 == 1)
        {
            for (int i = 4; i <= n-2;i+=2)
            {
                pic[i][i] = 1;
            }
            //for (int j = 4;j)
                for (int i = 4; i <= n - 2; i += 4)
                    pic[4][i] = 1, pic[i][4] = 1;
        }
        else
        {
            for (int i = 4; i <= n;i+=2)
            {
                pic[i][i] = 1;
            }
            for (int i = 4; i <= n ;i+=4)
                pic[4][i] = 1,pic[i][4] = 1;
        }
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
                printf("%d", pic[i][j]);
            putchar('\n');
        }
    }
    return 0;
}