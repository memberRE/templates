#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int MAX = 0x3f3f3f3f;
const LL MOD = 1e9 + 7;
LL n;
int T;

int main()
{
        cin >> n;
        LL i = 1, ans = 0;
        while (i <= n)
        {
            LL v = n / i;
            LL last = n / v;
            ans += v * (last - i + 1);
            ans %= mod;
            i = last + 1;
        }
        cout << ans << endl;
    return 0;
}