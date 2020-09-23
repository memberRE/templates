#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;
const int MAX = 2e5 + 20;
struct SEG
{
    int a, b, c;
    int cnt, ans;
    void init(int aa, int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
        cnt = 0;
    }
    bool operator!=(const SEG &a) const
    {
        return a.a != this->a or a.b != this->b or a.c != this->c;
    }
} pic[MAX], for_cdq[MAX];
template <typename T>
struct TREE
{
#define lowbit(x) (x & -x)
    //T *tree;
    T tree[MAX];
    int n;
    TREE(int nn)
    {
        //tree = new T[n + 20]();
        n = nn;
    }
    TREE()
    {
        ;
    }
    inline void build_tree(T sum[])
    {
        for (int i = 1; i <= n; i++)
            tree[i] = sum[i] - sum[i - lowbit(i)];
    }
    inline void add(int x, T k)
    {
        while (x <= n)
        {
            tree[x] += k;
            x += lowbit(x);
        }
    }
    T qurry(int x)
    {
        T ans = 0;
        while (x != 0)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

int n,res[MAX];
TREE<int> tree;

bool cam(SEG a, SEG b)
{
    if (a.a == b.a)
    {
        if (a.b == b.b)
            return a.c < b.c;
        else
            return a.b < b.b;
    }
    else
        return a.a < b.a;
}
bool cam2(SEG a, SEG b)
{
    if (a.b == b.b)
        return a.c < b.c;
    return a.b < b.b;
}
void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(for_cdq + l, for_cdq + mid + 1, cam2);
    sort(for_cdq + mid + 1, for_cdq + r + 1, cam2);
    int j = l;
    for (int i = mid + 1; i <= r; i++)
    {
        while (j <= mid and for_cdq[j].b <= for_cdq[i].b)
        {
            tree.add(for_cdq[j].c, for_cdq[j].cnt);
            j++;
        }
        for_cdq[i].ans += tree.qurry(for_cdq[i].c);
    }
    for (int i = l; i < j; i++)
        tree.add(for_cdq[i].c, -for_cdq[i].cnt);
}

int main()
{
	scanf("%d%d", &n,&tree.n);

    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        pic[i].init(x, y, z);
    }
    sort(pic + 1, pic + 1 + n, cam);
    int topp = 0;
    int L = 1, R = 0;
    for (int i = 1; i <= n; i++)
    {
        topp++;
        if ((pic[i] != pic[i + 1]))
        {
            R++;
            for_cdq[R] = pic[i];
            for_cdq[R].cnt = topp;
            topp = 0;
        }
    }
    cdq(L, R);
    for (int i = 1; i <= R; i++)
        res[for_cdq[i].ans + for_cdq[i].cnt - 1] += for_cdq[i].cnt;
    for (int i = 0; i < n;i++)
        printf("%d\n",res[i]);
    return 0;
}
