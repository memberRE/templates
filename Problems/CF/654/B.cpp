#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sum(ll x)
{
    return (x * (x + 1)) >> 1;
}
int main()
{
    ll n, r, t;
    cin >> t;
    while(t--)
    {
        cin >> n >> r;
        ll ans = 0;
        if(r<n) {
            ans += sum(r);
        }
        else
        {
            ans += sum(n - 1);
            ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}