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
const int MAXN = 1e6 + 20;
const double PI=acos(-1); 
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
struct complex
{
    double x, y;
    complex(double xx = 0, double yy = 0) { x = xx, y = yy; }
} a[MAXN], b[MAXN];
int rev[MAXN], l,temm[MAXN];

complex operator+(complex a, complex b)
{
    return complex(a.x + b.x, a.y + b.y);
}
complex operator-(complex a, complex b)
{
    return complex(a.x - b.x, a.y - b.y);
}
complex operator*(complex a, complex b)
{
    return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
void fft(complex *p, int len, int op)
{
    for (int i = 0; i < len; i++)
        if (i < rev[i])
            swap(p[i], p[rev[i]]);
    for (int mid = 1; mid < len; mid <<= 1)
    {
        complex wn(cos(PI / mid), sin(PI / mid) * op);
        int stepp = mid << 1;
        for (int j = 0; j < len; j += stepp)
        {
            complex w(1, 0);
            for (int k = 0; k < mid; k++, w = w * wn)
            {
                complex x = p[j + k];
                complex y = w * p[j + k + mid];
                p[j + k] = x + y;
                p[j + k + mid] = x - y;
            }
        }
    }
}
int main()
{
    int n = read(), x = read(), y = read();
    for (int i = 0; i <= n; i++)
    {
        int tem = read();
        a[tem].x = 1;
        b[x - tem] = 1;
    }
    int len = 1;
    for (len = 1; len <= (x << 1); len <<= 1, l++)
        ;
    for (int i = 0; i < len; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    fft(a, len, 1);
    fft(b, len, 1);
    for (int i = 0; i < len; i++)
        a[i] = a[i] * b[i];
    fft(a, len, -1);

    for (int i = 1; i <= x; i++)
    {
        ll p = (ll)(a[i + x].x + 0.5);
        if (p)
            for (int j = 2 * (i + y); j < MAXN; j += 2 * (i + y))
                temm[j] = 2 * (i + y);
    }
    for (int j = 2 * (x + y); j < MAXN; j += 2 * (x + y))
        temm[j] = 2 * (x + y);
    int T = read();
    while (T--)
    {
        int jkl = read();
        printf("%d ", temm[jkl] ? temm[jkl] : -1);
    }
    return 0;
}