#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define lson l, m, lch[rt]
#define rson m + 1, r, rch[rt]
using namespace std;

int read()
{
    int x, f = 1;
    char ch;
    while (ch = getchar(), ch < '0' || ch > '9')
        if (ch == '-')
            f = -1;
    x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48;
    return x * f;
}

const int N = 200005;
int cnt, lch[N * 33], rch[N * 33], val[N * 33], root[N], las[N];
int pic[N], n, m;
int ans[N];
struct ppp
{
    int ls, rs;
    int sum;
} tree[N * 20];
int roott[N], tot;
int build(int l, int r)
{
    int node = ++tot;
    if (l == r)
        return node;
    int mid = (l + r) >> 1;
    tree[node].ls = build(l, mid);
    tree[node].rs = build(mid + 1, r);
    return node;
}
int insert(int node, int l, int r, int x, int num)
{
    int p = ++tot;
    tree[p] = tree[node];
    if (l == r)
    {
        tree[p].sum += num;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        tree[p].ls = insert(tree[node].ls, l, mid, x, num);
    else
        tree[p].rs = insert(tree[node].rs, mid + 1, r, x, num);
    tree[p].sum = tree[tree[p].ls].sum + tree[tree[p].rs].sum;
    return p;
}
int query_exist(int noder, int nodel, int l, int r, int x)
{
    if (l == r)
        return tree[noder].sum - tree[nodel].sum;
    int mid = (l + r) >> 1;
    if (x <= mid)
        return query_exist(tree[noder].ls, tree[nodel].ls, l, mid, x);
    else
        return query_exist(tree[noder].rs, tree[nodel].rs, mid + 1, r, x);
}

void update(int l, int r, int &rt, int las, int p, int c)
{
    rt = ++cnt;
    lch[rt] = lch[las], rch[rt] = rch[las];
    if (l == r)
    {
        val[rt] = c;
        return;
    }
    int m = l + r >> 1;
    if (p <= m)
        update(lson, lch[las], p, c);
    else
        update(rson, rch[las], p, c);
    val[rt] = min(val[lch[rt]], val[rch[rt]]);
}

int query(int l, int r, int rt, int k)
{
    if (l == r)
        return l;
    int m = l + r >> 1;
    if (val[lch[rt]] >= k)
        return query(rson, k);
    return query(lson, k);
}
int main()
{
    n = read();
    m = read();
    memset(ans, 0x7f, sizeof(ans));
    roott[0] = build(1, N);
    for (int i = 1; i <= n; i++)
    {
        pic[i] = read(), update(1, 1e9, root[i], root[i - 1], pic[i], i);
        roott[i] = insert(root[i - 1], 1, N, pic[i], 1);
    }
    int lref = 1, rref = 1;
    while (rref <= n and lref <= n)
    {
        int mex = query(1, 1e9, root[rref], lref);
        if (mex != 1)
            ans[mex] = min(ans[mex], rref - lref + 1);
        while(!query_exist(roott[rref], int nodel, int l, int r, int x))
    }

    // for (i = 1; i <= m; i++)
    // {
    //     a = read();
    //     b = read();
    //     printf("%d\n", query(0, 1e9, root[b], a));
    // }
    return 0;
}