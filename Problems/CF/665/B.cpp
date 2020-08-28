#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long  ll;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int main()
{
    int t = read();
    while(t--)
    {
        int x1 = read(), y1 = read(), z1 = read();
        int x2 = read(), y2 = read(), z2 = read();
        ll ans = 0;
        int tem1 = min(z1, y2);
        ans += tem1 * 2;
        z1 -= tem1;
        y2 -= tem1;
        if (z1 != 0)
        {
            tem1 = min(z1, z2);
            z1 -= tem1;
            z2 -= tem1;
        }
        if (z1 != 0 || z2 == 0)
        {
            printf("%lld\n", ans);
            continue;
        }
        //----z1 = 0 and z2 != 0
        tem1 = min(z2, x1);
        z2 -= tem1;
        x1 -= tem1;
        if (z2 == 0)
        {
            printf("%lld\n", ans);
            continue;
        }
        ans -= 2 * min(z2, y1);
        printf("%lld\n", ans);
    }
    return 0;
}