#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long  ll;
int vztd[5000000];
int main()
{
    ll k;
    cin >> k;
    ll tem = 7;
    ll ans = 1;
    while (tem < k)
        tem = tem * 10 + 7,ans++;
    for (;;)
    {
        if (tem % k == 0)
        {
            cout << ans << endl;
            return 0;
        }
        ans++;
        tem = tem * 10 + 7;
        tem %= k;
        if (vztd[tem] == 1)
            break;
        else
            vztd[tem] = 1;
    }
    cout << -1 << endl;
    return 0;
}