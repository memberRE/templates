#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

typedef long long ll;
using namespace std;
const int MAX = 2e5 + 20;
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
struct SEG
{
    int l, r, t;
} pic[MAX];
int n, cnt, max_num;
int dis_seg[MAX << 1];
int dp[MAX << 1];
vector<int> seg[2][MAX << 1], seg2[MAX << 1];
inline int discrete(int tem[], int cntt)
{
    sort(tem + 1, tem + 1 + cntt);
    int nN = unique(tem + 1, tem + 1 + cntt) - tem - 1;
    return nN;
}
template <class T>
struct SEG_TREE
{
#define ls (node << 1)
#define rs ((node << 1) | 1)
    T *tree, *laz;
    int n;
    // int maxx[MAX << 3];
    // int laz[MAX << 3];
    SEG_TREE(int n)
    {
        tree = new T[n << 2]();
        laz = new T[n << 2]();
        this->n = n;
    }
    inline void pushup(int node)
    {
        tree[node] = max(tree[ls], tree[rs]);
    }
    inline void pushdown(int node)
    {
        if (laz[node])
        {
            laz[ls] += laz[node];
            laz[rs] += laz[node];
            tree[ls] += laz[node];
            tree[rs] += laz[node];
            laz[node] = 0;
        }
    }
    void update(int node, int l, int r, int val, int L, int R)
    {
        if (l <= L and R <= r)
        {
            tree[node] += val;
            laz[node] += val;
            return;
        }
        pushdown(node);
        int mid = (L + R) >> 1;
        if (l <= mid)
            update(ls, l, r, val, L, mid);
        if (r >= mid + 1)
            update(rs, l, r, val, mid + 1, R);
        pushup(node);
    }
    T query(int node, int l, int r, int L, int R)
    {
        if (l <= L and R <= r)
            return tree[node];
        pushdown(node);
        int mid = (L + R) >> 1;
        T ans = 0;
        if (l <= mid)
            ans = max(ans, query(ls, l, r, L, mid));
        if (r >= mid + 1)
            ans = max(ans, query(rs, l, r, mid + 1, R));
        return ans;
    }
    void build(int node, int l, int r, T tar[])
    {
        if (l == r)
            tree[node] = tar[l];
        else
        {
            int mid = (l + r) >> 1;
            build(ls, l, mid, tar);
            build(rs, mid + 1, r, tar);
            pushup(node);
        }
    }
};
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        pic[i].l = read();
        pic[i].r = read();
        pic[i].t = read() - 1;
        dis_seg[++cnt] = pic[i].l;
        dis_seg[++cnt] = pic[i].r;
    }
    max_num = discrete(dis_seg, cnt);
    for (int i = 1; i <= n; i++)
    {
        pic[i].l = lower_bound(dis_seg + 1, dis_seg + 1 + max_num, pic[i].l) - dis_seg;
        pic[i].r = lower_bound(dis_seg + 1, dis_seg + 1 + max_num, pic[i].r) - dis_seg;
        seg[pic[i].t][pic[i].r].push_back(pic[i].l);
    }
    SEG_TREE<int> t1(max_num), t2(max_num);
    for (int i = 1; i <= max_num; i++)
    {
        for (auto l : seg[0][i])
            t1.update(1, 0, l - 1, 1, 0, max_num);
        for (auto l : seg[1][i])
            t2.update(1, 0, l - 1, 1, 0, max_num);
        dp[i] = max(dp[i], t1.query(1, 0, i - 1, 0, max_num));
        dp[i] = max(dp[i], t2.query(1, 0, i - 1, 0, max_num));
        t1.update(1, i, i, dp[i], 0, max_num);
        t2.update(1, i, i, dp[i], 0, max_num);
    }
    cout << dp[max_num] << endl;
    return 0;
}