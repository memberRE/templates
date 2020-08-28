#include <algorithm>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 50, N = 1e6;
template <class T>
struct segment_tree_sum
{
#define chl (k << 1)
#define chr (k << 1 | 1)
#define mid ((l + r) >> 1)
    T *t, *tag;
    int n;

    segment_tree_sum(int n)
    {
        t = new T[n << 2]();
        this->n = n;
    }

    void push_up(int k) { t[k] = t[chl] + t[chr]; }

    void update(int k, int l, int r, int ll, T x)
    {
        if (ll < l || ll > r)
            return;
        if (ll == l && ll == r)
        {
            t[k] = x;
            return;
        }
        update(chl, l, mid, ll, x);
        update(chr, mid + 1, r, ll, x);
        push_up(k);
    }
    void update(int ll, T x) { update(1, 1, n, ll, x); }

    T query(int k, int l, int r, int ll, int rr)
    {
        if (l > rr || ll > r)
            return 0;
        if (l >= ll && r <= rr)
            return t[k];
        return query(chl, l, mid, ll, rr) + query(chr, mid + 1, r, ll, rr);
    }
    T query(int ll, int rr) { return query(1, 1, n, ll, rr); }
};
segment_tree_sum<int> tree(N);
pair<int, int> pic[MAXN << 1];
int n, m, tot;
int leftx[MAXN], rx[MAXN];
int lefty[MAXN], righty[MAXN];
LL ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int y;
        cin >> y;
        cin >> leftx[y] >> rx[y];
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cin >> lefty[x] >> righty[x];
        pic[++tot] = pair<int, int>(lefty[x], x);
        pic[++tot] = pair<int, int>(righty[x], x);
    }
    sort(pic + 1, pic + tot + 1);
    int cur = 1;
    for (int y = 0; y <= N; y++)
    {
        int r = cur - 1;
        while (r + 1 <= tot && pic[r + 1].first == y)
            r++;
        for (int i = cur; i <= r;i++)
        {
            int XX = pic[i].second, YY = pic[i].first;
            if (YY == lefty[XX])
                tree.update(XX, 1);
        }
        if (leftx[y] < rx[y])
            ans += tree.query(leftx[y], rx[y]);
        for (int i = cur; i <= r;i++)
        {
            int XX = pic[i].second, YY = pic[i].first;
            if (YY == righty[XX])
                tree.update(XX, 0);
        }
        cur = r + 1;
    }
    for (int i = 1; i <= N;i++)
    {
        if (leftx[i] == 0 && rx[i] == N)
            ans++;
        if (lefty[i] == 0 && righty[i] == N)
            ans++;
    }
    cout << ans + 1 << endl;

    return 0;
}
