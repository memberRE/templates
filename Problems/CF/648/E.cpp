#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll pic[512];
int main()
{
    int n;
    cin >> n;
    memset(pic, 0, sizeof(pic));
    for (int i = 1; i <= n;i++)
    {
        cin >> pic[i];
    }
    ll ans = pic[1] | pic[2] | pic[3];
    for (int i = 1; i <= n;i++)
        for (int j = i + 1; j <= n;j++)
            for (int k = j + 1; k <= n;k++)
            {
                ans = max(ans, pic[i] | pic[j] | pic[k]);
            }
    cout << ans << endl;
    return 0;
}