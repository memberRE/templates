#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 20;
int pic[MAXN];
int tem[MAXN];
int b[MAXN];
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
    while (t--)
    {
        int n = read();
        int mmin = 0x7f7f7f7f;
        for (int i = 1; i <= n;i++)
        {
            pic[i] = read();
            tem[i] = pic[i];
            mmin = min(pic[i], mmin);
        }
        sort(tem + 1, tem + 1 + n);
        bool ans = true;
        for (int i = 1; i <= n; i++)
            if (pic[i] % mmin != 0 and tem[i] != pic[i])
            {
                ans = false;
                break;
            }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}