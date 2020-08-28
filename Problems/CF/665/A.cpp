#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
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
    while (t--)
    {
        int n = read(), k =read();
        if (k <= n)
        {
            if (k % 2 == n % 2)
                puts("0");
            else
                puts("1");
        }
        else
            cout << k - n << endl;
    }
    return 0;
}