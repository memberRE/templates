#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2e5 + 20;
typedef long long  ll;
ll dp[MAX][2], pic[MAX];
ll read()
{
    ll x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int main()
{
    ll t = read();
    while(t--)
    {
        ll n = read();
        for (int i = 1; i <= n;i++)
            pic[i] = read();
        sort(pic + 1, pic + 1 + n);
        dp[0][1] = pic[5] - pic[4];
        dp[0][0] = 0;
        for (int i = 1; i <= n / 2 - 4;i++)
        {
            
        }
    }
}
