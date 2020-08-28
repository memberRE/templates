#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int pic[5002];
int ans[5002];
int main()
{
    int n, k;
    cin >> n >> k;
    if (n %2 == 1 && k!=0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (n%2 == 0 && k!=n/2)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n;i+=2)
    {
        ans[i] = (i+1)/2;
        ans[i + 1] = n - ans[i];
    }
    ans[n] = n;
    for (int i = 1; i <= n;i++)
        cout << ans[i] << ' ';
    return 0;
}