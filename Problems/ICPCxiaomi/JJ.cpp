#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
const int MAX = 2025;
using namespace std;
ll tree[MAX][MAX];
int n, m;
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
inline int lowbit(int x) { return x & (-x); }
void add(int x, int y, ll v)
{
    while (x <= n)
    {
        int ty = y;
        while (ty <= m)
            tree[x][ty] += v, ty += lowbit(ty);
        x += lowbit(x);
    }
}
void real_add(int x1, int y1, int x2, int y2, ll v)
{
    add(x1, y1, v);
    add(x1, y2 + 1, -v);
    add(x2 + 1, y1, -v);
    add(x2 + 1, y2 + 1, v);
}
ll ask(int x, int y)
{
    ll res = 0;
    while (x)
    {
        int ty = y;
        while (ty)
            res += tree[x][ty], ty -= lowbit(ty);
        x -= lowbit(x);
    }
    return res;
}
inline void init()
{
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= m; j++)
            tree[i][j] = 0;
}
int main()
{
    int T = read();
    while (T--)
    {
        n = read();
        m = read();
        int err = 0;
        init();
        int a = read(), b = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                ll x = read();
                real_add(i, j, i, j, x);
            }
        for (int i = 1; i <= n - a + 1; i++)
            for (int j = 1; j <= m - b + 1; j++)
            {
                if (err == 1)
                    break;
                ll x = ask(i, j);
                if (x > 0)
                    real_add(i, j, i + a - 1, j + b - 1, -x);
                else if (x < 0)
                    err = 1;
            }
        int flag = 1;
        if (err == 1)
        {
            flag = 0;
            goto ooopp;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (ask(i, j) != 0)
                    flag = 0;
    ooopp:
        puts(flag ? "^_^" : "QAQ");
    }
}