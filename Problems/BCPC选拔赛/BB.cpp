#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
const int MAX = 2e5 + 10;
typedef long long LL;
LL pic[MAX],orf[MAX],orb[MAX];
int main()
{
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld", &pic[i]);
        orf[i] = pic[i] | orf[i-1];
    }
    for (int i = n; i >= 1;i--)
        orb[i] = pic[i] | orb[i+1];
    LL maxx = 0;
    LL tem = 1;
    for (int i=1; i<=k; i++) {
        tem *= (LL)x;
    }
    for (int i = 1; i <= n;i++)
    {
        maxx = max(maxx, (pic[i] * tem) | orf[i - 1] | orb[i + 1]);
    }
    cout << maxx;
    return 0;
}