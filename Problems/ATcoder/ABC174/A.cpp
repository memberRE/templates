#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long  ll;
int main()
{
    ll n,d;
    cin >> n >> d;
    d *= d;
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x*x + y*y <= d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}