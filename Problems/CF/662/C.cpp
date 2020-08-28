#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int pic[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m = 0, tot = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            pic[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            pic[x]++;
            m = max(m, pic[x]);
        }
        for (int i = 1; i <= n; i++)
            if (pic[i] == m)
                tot++;
        printf("%d\n", (n - m - tot + 1) / (m - 1));
    }
    return 0;
}
