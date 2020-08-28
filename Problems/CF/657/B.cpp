#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long  ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll l, r, m;
        cin >> l >> r >> m;
        ll LL = max(0ll, m + l - r), RR = m + r - l;
        ll a;
        ll n;
        for (a = l; a <= r;a++)
        {
            ll tem = (LL / a) * a;
            if( tem >=LL && tem <= RR && LL/a!=0)
            {
                n = LL / a;
                break;
            }
            tem += a;
            if( tem >=LL && tem <= RR)
            {
                n = LL / a + 1;
                break;
            }
        }
        ll d = a * n - m;
        ll b, c;
        if(d <= 0)
        {
            b = r;
            c = d + b;
        }
        else
        {
            c = r;
            b = c - d;
        }
        cout << a << " " << b << ' ' << c << endl;
    }
    return 0;
}