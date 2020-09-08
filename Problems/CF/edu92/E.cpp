#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll m, d, w;
        cin >> m >> d >> w;
        if (d == 1)
        {
            cout << "0\n";
            continue;
        }
        ll g = __gcd(w, d - 1);
        ll tem = w / g;
        d = min(m, d);
        ll topp = d / tem;
        ll ans = (d - tem + d - topp * tem) * topp / 2;
        cout << ans << endl;
    }
    return 0;
}
