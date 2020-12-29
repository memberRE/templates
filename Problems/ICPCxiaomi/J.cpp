#define DIN freopen("input.txt", "r", stdin);
#define DOUT freopen("output.txt", "w", stdout);
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define REP_(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
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

const int maxn = 2005;
LL t1[maxn][maxn], t2[maxn][maxn], t3[maxn][maxn], t4[maxn][maxn];
int n, m;
int lowbit(int x) { return x & (-x); }

void init()
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
        {
            t1[i][j] = 0;
            t2[i][j] = 0;
            t3[i][j] = 0;
            t4[i][j] = 0;
        }
}

void add_val(LL t[maxn][maxn], int x, int y, LL v)
{
    for (int i = x; i < n + 1; i += lowbit(i))
        for (int j = y; j < m + 1; j += lowbit(j))
            t[i][j] += v;
}

LL query_sum(LL t[maxn][maxn], int x, int y)
{
    LL ret = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ret += t[i][j];
    return ret;
}

void add_matrix(int x1, int y1, int x2, int y2, LL v)
{
    add_val(t1, x2 + 1, y2 + 1, v);
    add_val(t1, x1, y1, v);
    add_val(t1, x1, y2 + 1, -v);
    add_val(t1, x2 + 1, y1, -v);
    add_val(t2, x2 + 1, y2 + 1, v * (x2 + 1) * (y2 + 1));
    add_val(t2, x1, y1, v * x1 * y1);
    add_val(t2, x1, y2 + 1, -v * x1 * (y2 + 1));
    add_val(t2, x2 + 1, y1, -v * y1 * (x2 + 1));
    add_val(t3, x2 + 1, y2 + 1, v * (x2 + 1));
    add_val(t3, x1, y1, v * x1);
    add_val(t3, x1, y2 + 1, -v * x1);
    add_val(t3, x2 + 1, y1, -v * (x2 + 1));
    add_val(t4, x2 + 1, y2 + 1, v * (y2 + 1));
    add_val(t4, x1, y1, v * y1);
    add_val(t4, x1, y2 + 1, -v * (y2 + 1));
    add_val(t4, x2 + 1, y1, -v * y1);
}

LL query_matrix(int x, int y)
{
    if (!x || !y)
        return 0;
    LL ret = 0;
    ret += query_sum(t1, x, y) * (x + 1) * (y + 1);
    ret -= query_sum(t3, x, y) * (y + 1);
    ret -= query_sum(t4, x, y) * (x + 1);
    ret += query_sum(t2, x, y);
    return ret;
}

LL query_matrix(int x1, int y1, int x2, int y2)
{
    return query_matrix(x1 - 1, y1 - 1) + query_matrix(x2, y2) - query_matrix(x1 - 1, y2) - query_matrix(x2, y1 - 1);
}

int main()
{
    int T = read();
    while (T--)
    {
        n = read(), m = read();
        init();
        int a = read(), b = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                LL x = read();
                add_matrix(i, j, i, j, x);
            }
        for (int i = 1; i <= n - a + 1; i++)
            for (int j = 1; j <= m - b + 1; j++)
            {
                LL x = query_matrix(i, j, i, j);
                add_matrix(i, j, i + a - 1, j + b - 1, -x);
            }
        int flag = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (query_matrix(i, j, i, j) != 0)
                    flag = 0;
        puts(flag ? "^_^" : "QAQ");
    }

    return 0;
}
