#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int MAX = 1e5 + 20;
int a[MAX];
int sum[MAX];
int cnt[2000090];
char s[MAX];
LL ans = 0;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ans = 0;
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            a[i] = s[i] - '0';
            sum[i] = a[i];
        }
        for (int j = 1; j < n; j++)
            sum[j] += sum[j - 1];
        for (int i = 0; i < n; i++)
            sum[i] -= i + 1;
        for (int i = 0; i <= n * 10 * 2 + 2; i++)
            cnt[i] = 0;
        cnt[0 + n * 10] = 1;
        for (int i = 0; i < n; i++)
        {
            if (cnt[sum[i] + n * 10])
                ans += cnt[sum[i] + n * 10];
            cnt[sum[i] + n * 10]++;
        }
        cout << ans << endl;
    }
}
