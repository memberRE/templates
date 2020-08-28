#include<iostream>
#include<algorithm>
#include<cstdio>
#define SUM(x) ((x*(x+1))/2)
using namespace std;
typedef long long  ll;
const int MAX = 2e5 + 20;
ll n, x;
ll pic[MAX << 1];
ll sum_day[MAX << 1];
ll sum_hug[MAX << 1];
ll checkbeg(int i)
{
    int pos = lower_bound(sum_day + 1 + i, sum_day + 1 + 2 * n, x + sum_day[i] - 1) - sum_day;
    if(sum_day[pos] > x + sum_day[i] - 1)
    	pos--;
	//ll tem = sum_day[pos];
	ll lasday = x + sum_day[i] - 1 - sum_day[pos];
    ll ans = sum_hug[pos] - sum_hug[i] + pic[i] + SUM(lasday);
    return ans;
}
ll checkend(int k)
{
    int l = 0, r = k;
    while(l+2 < r)
    {
        int mid = (l + r) >> 1;
        if (sum_day[k] - sum_day[mid] > x)
            l = mid;
        else
            r = mid;
    }
    while(l<r)
        if (sum_day[k] - sum_day[r] > x)
            r--;
        else
        	break;
    ll ans = sum_hug[k] - sum_hug[r];
    ll lasday = x - sum_day[k] + sum_day[r ];
    if(lasday == 0)
        return ans;
    else
    {
        return ans + ((pic[k] + pic[k] - lasday + 1) * lasday) / 2;
    }
}
int main()
{
    scanf("%lld%lld", &n, &x);
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld", &pic[i]);
        pic[i + n] = pic[i];
        sum_day[i] = sum_day[i - 1] + pic[i];
        sum_hug[i] = sum_hug[i - 1] + ((pic[i] - 1) * pic[i]) / 2;
    }
    for (int i = n + 1; i <= 2 * n;i++)
        sum_day[i] = sum_day[i - 1] + pic[i],
        sum_hug[i] = sum_hug[i - 1] + ((pic[i-n] - 1) * pic[i-n]) / 2;
    ll ans = 0;
    for (int i = 1; i <= n;i++)
    {
        ans = max(ans, checkbeg(i));
        ans = max(ans, checkend(i));
    }
    cout << ans << endl;
    return 0;
}
