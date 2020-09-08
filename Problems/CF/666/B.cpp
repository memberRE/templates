#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
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
        int n = read();
        int sum = 0;
        int maxx = 0;
        for (int i = 1; i <= n;i++)
        {
            int tem = read();
            sum += tem;
            maxx = max(tem, maxx);
        }
        if (maxx > sum - maxx or sum & 1)
            puts("T");
        else
            puts("HL");
    }
    return 0;
}