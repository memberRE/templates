#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long  ll;
int A[64], B[64], n;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int mminA = 1000000002, mminB = 1000000002;
        ll ans = 0;
        for (int i = 1; i <= n;i++)
            cin >> A[i],mminA = min(A[i],mminA);
        for (int i = 1; i <= n;i++)
            cin >> B[i],mminB = min(B[i],mminB);
        for (int i = 1; i <= n;i++)
        {
            int leafA = A[i] - mminA;
            int leafB = B[i] - mminB;
            ans += max(leafA, leafB);
        }
        cout << ans << endl;
    }
    return 0;
}