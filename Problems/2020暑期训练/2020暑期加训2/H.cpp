#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define LL long long
const int maxn = 200010, eps = 1e-8;
struct Vector
{
    LL x, y;
    void rd()
    {
        scanf("%I64d%I64d", &x, &y);
    }
    Vector operator+(const Vector &v) const
    {
        return (Vector){x + v.x, y + v.y};
    }
    Vector operator-(const Vector &v) const
    {
        return (Vector){x - v.x, y - v.y};
    }
} a[maxn];
LL cross(Vector v, Vector u)
{
    return v.x * u.y - v.y * u.x;
}
int f[maxn], del[maxn], n, ans, now;
int comp(int x, int y)
{
    return cross(a[x], a[y]) > 0;
}
int main()
{
    //freopen("a.in","r",stdin);
    int tem, nn = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i].rd();
    a[0] = a[n];
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i++)
        if (!cross(a[i] - a[i - 1], a[i + 1] - a[i - 1]))
            del[i] = 1;
    for (int i = 1; i <= n; i++)
        if (!del[i])
            a[++nn] = a[i];
    n = nn;
    a[0] = a[n];
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i++)
        f[i] = i;
    sort(f + 1, f + n + 1, comp);
    for (int i = 1, j; i <= n; i = j)
    {
        tem = 0;
        for (j = i; j <= n && !cross(a[f[i]], a[f[j]]); j++)
        {
            if (cross(a[f[j]], a[f[j] - 1]) >= 0 && cross(a[f[j]], a[f[j] + 1]) > 0)
            {
                if (cross(a[f[j] - 1] - a[f[j]], a[f[j] + 1] - a[f[j]]) > 0)
                    now++;
                else
                    tem++;
            }
            if (cross(a[f[j]], a[f[j] - 1]) < 0 && cross(a[f[j]], a[f[j] + 1]) <= 0)
            {
                if (cross(a[f[j] - 1] - a[f[j]], a[f[j] + 1] - a[f[j]]) < 0)
                    now--;
                else
                    tem--;
            }
        }
        ans = max(ans, now);
        now += tem;
        ans = max(ans, now);
    }
    printf("%d\n", ans + 1);
}