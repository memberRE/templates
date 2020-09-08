#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
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
int T, t, d, n, m, cnt,k;
set<pair<int, int>> set1;
set<pair<int, int>, greater<pair<int, int>>> set2;
ll sum1, sum2;
int main()
{
    T = read();
    while (T--)
    {
        t = read();
        d = read();
        if (d > 0)
        {
            if (set1.size() && d >= (*set1.begin()).first)
                set1.insert({d, t}), sum1 += d, cnt += t;
            else
                set2.insert({d, t}), sum2 += d;
            k += t;
        }
        else
        {
            d = -d;
            if (set1.size() && d >= (*set1.begin()).first)
                set1.erase(set1.find({d, t})), sum1 -= d, cnt -= t;
            else
                set2.erase(set2.find({d, t})), sum2 -= d;
            k -= t;
        }
        while (set1.size() > k)
        {
            pair<int,int> p = *set1.begin();
            int vd = p.first, vt = p.second;
            set1.erase(p), sum1 -= vd, cnt -= vt;
            set2.insert({vd, vt}), sum2 += vd;
        }
        while (set1.size() < k)
        {
            pair<int,int> p = *set2.begin();
            int vd = p.first, vt = p.second;
            set1.insert({vd, vt}), sum1 += vd, cnt += vt;
            set2.erase(p), sum2 -= vd;
        }
        ll ans;
        if (k > 0 and cnt == k)
            ans = sum1 * 2 + sum2 - (set1.size() ? ((*set1.begin()).first) : 0) + (set2.size() ? ((*set2.begin()).first) : 0);
        else
            ans = sum1 * 2 + sum2;
        printf("%lld\n", ans);
    }
}