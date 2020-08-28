#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX = 2e5 + 20;
typedef long long  ll;
int pic[MAX],n,k;
bool check(int goal)
{
    int tem = k,i;
    for (i  = 1; i <= n;i++)
    {   
        if (pic[i] <= goal)
            continue;
        else
        {
            int ans = 0,logg = pic[i];
            ans = logg / goal;
            if (logg % goal == 0)
                ans--;
            tem -= ans;
            if (tem < 0)
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> k;
    int l = 1, r = 0;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &pic[i]);
        r = max(pic[i], r);
    }
    while (l + 2 < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    for (int i = l; i <= r;i++)
        if (check(i))
        {
            cout << i << endl;
            break;
        }
    return 0;
}