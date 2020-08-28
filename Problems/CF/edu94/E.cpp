#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
const int MAX = 5e3 + 20;
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
int mmin[MAX << 2];
int pic[MAX];
int dp[MAX][MAX],n;
inline int get_min(int x,int y)
{
    if (pic[x] < pic[y])
        return x;
    else
        return y;
}
void build(int node,int l,int r)
{
    if (l == r)
    {
        mmin[node] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    mmin[node] = get_min(mmin[ls] , mmin[rs]);
}
inline int qurry(int node, int l, int r, int L, int R)
{
    if (l == L and r == R)
        return mmin[node];
    else
    {
        int mid = (L + R) >> 1;
        if (r <= mid)
            return qurry(node << 1, l, r, L, mid);
        else if (l >= mid + 1)
            return qurry((node << 1) | 1, l, r, mid + 1, R);
        else
            return get_min(qurry(node << 1, l, mid, L, mid) , qurry((node << 1) | 1, mid + 1, r, mid + 1, R));
    }
}
int mfs(int l,int r,int mins)
{
    if (l>r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r and pic[l] - mins <=0)
        return 0;
    int pos = qurry(1, l, r, 1, n);
    int ann = min(r - l + 1, mfs(l, pos - 1, pic[pos]) + mfs(pos + 1, r, pic[pos]) + pic[pos]-mins);
    dp[l][r] = ann;
    return ann;
}
int main()
{
    n = read();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n;i++)
        pic[i] = read();
    build(1, 1, n);
    cout << mfs(1, n,0);
}