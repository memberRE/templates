#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long  ll;
int A[64], n;
int vztd[128];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(vztd, 0, sizeof(vztd));
        int ans = 0;
        for (int i = 1; i <= n;i++)
            cin >> A[i],vztd[A[i]]++;
        for (int i = 2; i <= 2 * n;i++)
        {
            int tem = 0;
            for (int j = 1; j <= i / 2;j++)
                tem += (j != i - j)? min(vztd[j], vztd[i - j]):vztd[j]/2;
            ans = max(ans, tem);
        }
        cout << ans << endl;
    }
    return 0;
}