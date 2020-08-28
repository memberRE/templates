#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '-')
        c = getchar();
    if (c == '-')
        flag = 0, c = getchar();
    while (c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
int main()
{
    int t = read();
    while (t--)
    {
        int p = read(), f = read();
        int cnts = read(), cntw = read();
        int s = read(), w = read();
        int ans = 0;
        for (int i = 0; i <= cnts; i++)
        {
            int j = min(cntw, (p - s * i) / w);
            int S = cnts - i, W = cntw - j;
            int temans = i + j;
            if (s * i > p)
                break;
            int fl = 0;
            if (s <= w)
                fl = 1,swap(s, w), swap(S, W);
            j = min(W, f / w);
            temans += j + min(S, (f - j * w) / s);
            ans = max(ans, temans);
            if (fl)
                swap(s, w);
        }
        printf("%d\n", ans);
    }
}