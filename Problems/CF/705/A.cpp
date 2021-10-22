#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;

int main()
{
    int t = read();
    while(t--)
    {
        int n = read(),k = read();
        int tem = (k&1) + k/2;
        printf("%d\n",n-k+k-tem);
        for(int i = k+1;i<=n;i++)
            printf("%d ",i);
        for(int i = tem;i<k;i++ )
            printf("%d ",i);
        putchar('\n');
    }
    return 0;
}
