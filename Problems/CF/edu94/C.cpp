#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long LL;
const int MAX = 200100;
char ans[MAX], s[MAX];
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
        int x, n;
        int flag = 1;
        scanf("%s", s);
        x = read();
        n = strlen(s);
        for (int i = 0; i < n; i++)
            ans[i] = '1';
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0')
                continue;
            ans[i - x] = (i >= x) ? '0' : ans[i - x];
            ans[i + x] = (i + x < n) ? '0' : ans[i + x];
        }
        for (int i = 0; i < n; i++)
        {
            if (i < x and i + x < n)
                ans[i] = s[i + x];
            else if (i + x >= n and i >= x)
                ans[i] = s[i - x];
        }
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                if (!((i >= x and ans[i - x] == '1') or (i + x < n and ans[i + x] == '1')))
                    flag = 0;
            }
        if (flag)
        {
            ans[n] = 0;
            puts(ans);
        }
        else
            puts("-1");
    }
}