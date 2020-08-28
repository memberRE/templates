#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
char pic[256][256];
int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        //getchar();
        for (int i = 1; i <= n;i++)
            cin >> pic[i];
        int ans = 0;
        for (int i = 0; i < m;i++)
            if (pic[n][i] == 'D')
                ans++;
        for (int i = 1; i <= n;i++)
            if (pic[i][m-1] == 'R')
                ans++;
        cout << ans << endl;
    }
    return 0;
}