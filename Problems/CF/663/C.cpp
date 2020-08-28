#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    ll ans = 1,tem = 1;
    for (int i = 1; i < n;i++)
    {
        ans *= i;
        ans %= MOD;
        tem *= 2;
        tem %= MOD;
    }
    ans = (ans * n) % MOD;
    cout << (ans - tem + 2 * MOD) % MOD;
    return 0;
}