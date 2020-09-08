#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef unsigned long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
ll pic[200007];
ll sum[200007];
ll n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> pic[i];
        sum[i] = sum[i - 1] + pic[i];
        sum[i] %= MOD;
    }
    ll ans = 0;
    for (int i = n; i >= 1;i--)
    {
        ans = ((pic[i] * sum[i - 1]) % MOD + ans) % MOD;
    }
    cout << ans % MOD << endl;
}