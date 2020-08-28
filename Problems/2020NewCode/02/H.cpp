#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#define ls (node << 1)
#define rs ((node << 1) | 1)
#define mid ((L + R) >> 1)
using namespace std;
const int MAX = 2e5 + 200;
struct ppp{
    int l, r;
    int sum, min_inter,minL,maxR;
} tree[MAX * 4];
int pic[MAX],n,q;
pair<int, int> op[MAX];
void decrease()
{
    sort(pic + 1, pic + 1 + q);
    n = unique(pic + 1, pic + 1 + q) - pic - 1;
}
void build(int node,int L,int R)
{
    tree[node].l = L;
    tree[node].r = R;
    tree[node].min_inter = 2147483640;
    tree[node].minL = -1;
    tree[node].maxR = -1;
    if(L== R)
        return;
    build(ls,L,mid);
    build(rs,mid + 1,R);
}
void _insert(int node,int x,int L,int R,int l_max,int r_min)
{
    tree[node].sum++;
    if(tree[node].minL > x || tree[node].minL == -1)
        tree[node].minL = x;
    if(tree[node].maxR < x)
        tree[node].maxR = x;
    int tem = 2147483640;
    if(l_max >= L)
        tem = min(tem, pic[x] - pic[l_max]);
    if(r_min <= R && r_min)
        tem = min(tem, pic[r_min] - pic[x]);
    if(tem != 2147483640 && (tree[node].min_inter > tem))
        tree[node].min_inter = tem;
    if(L == R && L == x)
        return;
    if (x <= mid)
        _insert(ls, x, L, mid, l_max, r_min);
    else
        _insert(rs, x, mid + 1, R, l_max, r_min);
}
void _del(int node,int x,int L,int R,int l_max,int r_min)
{
    tree[node].sum--;
    if(!(l_max == r_min && l_max == 0))
    {
        if(tree[node].minL == x)
        {
            if(r_min <= R && r_min)
                tree[node].minL = r_min;
            else
                tree[node].minL = -1;
        }
        if(tree[node].maxR == x)
        {
            if(l_max >= L && l_max)
                tree[node].maxR = l_max;
            else
                tree[node].maxR = -1;
        }
    }
    
    if(L == R && L == x)
        return;
    if (x <= mid)
        _del(ls, x, L, mid, l_max, r_min);
    else
        _del(rs, x, mid + 1, R, l_max, r_min);
    int tem = 2147483640;
    if(l_max >= L)
        tem = min(tem, pic[x] - pic[l_max]);
    if(r_min <= R && r_min)
        tem = min(tem, pic[r_min] - pic[x]);
    if(tem != 2147483640 && (tree[node].min_inter == tem))
    {
        tree[node].min_inter = min(tree[ls].min_inter, tree[rs].min_inter);
        int ll = tree[ls].maxR;
        int rr = tree[rs].minL;
        if(ll != -1 && rr != -1)
            tree[node].min_inter = min(tree[node].min_inter, pic[rr] - pic[ll]);
    }
}
int query_min(int node,int l,int r,int L,int R)
{
    if (l > R || r < L)
        return 0;
    if (l <= L && r >= R)
        return tree[node].minL == -1 ? 0 : tree[node].minL;
    if (L == R)
        return tree[node].sum == 0 ? 0 : L;
    int tem = query_min(ls, l, r, L, mid);
    if (tem != 0)
        return tem;
    return query_min(rs, l, r, mid + 1, R);
}
int query_max(int node,int l,int r,int L,int R)
{
    if (l > R || r < L)
        return 0;
    if (l <= L && r >= R)
        return tree[node].maxR == -1 ? 0 : tree[node].maxR;
    if (L == R)
        return tree[node].sum == 0 ? 0 : L;
    int tem = query_max(rs, l, r, mid + 1, R);
    if (tem != 0)
        return tem;
    return query_max(ls, l, r, L, mid);
}
int query_sum(int node,int l,int L,int R)
{
    if(l == L && l == R)
        return tree[node].sum;
    if(l >= mid+1)
        return query_sum(rs, l, mid + 1, R);
    else
        return query_sum(ls, l, L, mid);
}
int query_inter(int node,int l,int r,int L,int R)
{
    if (l > R || r < L)
        return 2147483641;
    if (l <= L && r >= R)
        return tree[node].min_inter;
    if(r <= mid)
        return query_inter(ls, l, r, L, mid);
    else if(l >= mid + 1)
        return query_inter(rs, l, r, mid+1, R);
    else
    {
        int tem = 2147483641;
        tem = min(tem, query_inter(rs, l, r, mid + 1, R));
        tem = min(tem, query_inter(ls, l, r, L, mid));
        int ll = tree[ls].maxR;
        int rr = tree[rs].minL;
        if(ll != -1 && rr != -1 && ll >= l && rr <= r)
            tem = min(tem, pic[rr] - pic[ll]);
        return tem;
    }
}
int main()
{
    scanf("%d", &q);
    for (int i = 1; i <= q;i++)
    {
        int o, p;
        scanf("%d%d", &o, &p);
        pic[i] = p;
        op[i] = make_pair(o, p);
    }
    decrease();
    build(1, 1, n);
    for (int i = 1; i <= q;i++)
    {
        int x = lower_bound(pic + 1, pic + 1 + n, op[i].second) - pic;
        if(op[i].first == 1)
        {
            if(query_sum(1,x, 1, n) != 0)
                _insert(1, x, 1, n,0,0);
            else
            {
                int l_max = query_max(1,1, x - 1, 1, n);
                int r_max = query_min(1,x + 1, n, 1, n);
                _insert(1, x, 1, n, l_max, r_max);
            }
        }
        else if(op[i].first == 2)
        {
           if(query_sum(1,x, 1, n) > 1)
                _del(1, x, 1, n,0,0);
            else
            {
                int l_max = query_max(1,1, x - 1, 1, n);
                int r_max = query_min(1,x + 1, n, 1, n);
                _del(1, x, 1, n, l_max, r_max);
            }
        }
        else 
        {
            int mmin1 = query_max(1,1, x, 1, n);
            int mmin2;
            if(query_sum(1,mmin1, 1, n) == 1)
                mmin2 = query_max(1,1, mmin1 - 1, 1, n);
            else
                mmin2 = mmin1;
            if(pic[mmin1] + pic[mmin2] > op[i].second)
            {
                printf("Yes\n");
                continue;
            }
            int mmin3 = query_min(1,x + 1, n, 1, n);
            if(mmin3 <= 0)
            {
            	printf("No\n");
            	continue;
			}
            mmin3 = pic[mmin3] - op[i].second;
            mmin3 = upper_bound(pic + 1, pic + 1 + n, mmin3) - pic;
            int tem = query_inter(1,mmin3, n, 1, n);
            if(tem >= op[i].second)
            {
                printf("No\n");
                continue;
            }
            printf("Yes\n");
        }
    }
    return 0;
}
