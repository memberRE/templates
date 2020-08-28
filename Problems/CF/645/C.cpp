#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long  ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll x, y, a, s, d, f;
        cin >> a >> s >> d >> f;
        x = d - a + 1;
        y = f - s + 1;
        ll X = max(x, y);
        ll Y = min(x, y);
        ll tem = Y - 1;
        tem = (tem * (tem + 1)) >> 1;
        tem += tem;
        tem += (Y - 1) * (X - Y - 1);
        cout << tem + 1<<endl;
    }
    return 0;
}