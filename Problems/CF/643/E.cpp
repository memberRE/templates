#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 20;
ll pic[MAX];
ll sum[MAX];
ll n, a, r, m;
ll cal(ll h)
{
    int pos = lower_bound(pic + 1, pic + 1 + n, h) - pic - 1;
    ll res = 0;
	ll k1 = h * pos - sum[pos];
	ll k2 = sum[n] - sum[pos] - h * (n - pos);
	res = min(k1, k2);
	k1 -= res;
	k2 -= res;
	res *= m;
	res += k1 * a;
	res += k2 * r;
	return res;
}
int main()
{
    
    cin >> n >> a >> r >> m;
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld", &pic[i]);
    }
    sort(pic + 1, pic + 1 + n);
    m = min(m, a + r);
    for (int i = 1; i <= n;i++)
        sum[i] = sum[i - 1] + pic[i];
    ll ans = 0x3f3f3f3f3f3f3f3f;
    ans = min(ans, cal(sum[n] / n));
	ans = min(ans, cal(sum[n] / n + 1));
	for (int i = 1; i <= n; i++)
		ans = min(ans, cal(pic[i]));
    cout << ans;
}