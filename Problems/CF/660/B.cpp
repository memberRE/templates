#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int tem = n / 4;
        if (n %4!=0)
            tem++;
        int i;
        for (i = 1; i <= n - tem;i++)
            putchar('9');
        for (; i <= n;i++)
            putchar('8');
        putchar('\n');
    }
    return 0;
}