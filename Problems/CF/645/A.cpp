#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int t, m, n;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        int ans = (m >> 1) * n;
        if (m & 1)
        {
            ans += n / 2;
            if (n & 1)
                ans++;
        }
        cout << ans << endl;
    }
}