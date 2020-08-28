#include <iostream>
#include <cstdio>
#include<algorithm>
#include <queue>
#define ls (node << 1)
#define rs ((node << 1) | 1)
#define mid ((L + R) >> 1)
using namespace std;
const int MAX = 3e5 + 20;
int n,lim[MAX],ans[MAX];
int tree[MAX << 2];
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
void insert(int node,int x,int val,int L,int R)
{
    if (L == R)
    {
        tree[node] = val;
        return;
    }
    if (x <= mid)
        insert(ls, x, val, L, mid);
    else
        insert(rs, x, val, mid + 1, R);
    tree[node] = min(tree[ls], tree[rs]);
}
int query(int node, int val, int L, int R)
{
    if (L == R)
    {
        return L;
    }
    if(tree[ls] <= val)
        return query(ls, val, L, mid);
    else
        return query(rs, val, mid + 1, R);
}
int main()
{
    n = read();
    for (int i = 1; i <= n;i++)
    {
        int c = read();
        while(c--)
        {
            int tem = read();
            lim[tem] = lim[tem] == 0 ? i : lim[tem];
        }
    }
    for (int i = 1; i <= n;i++)
    {
        if (lim[i] == 0)
            ans[i] = 1;
        else
        {
            ans[i] = query(1, lim[i], 1, MAX - 1);
        }
        insert(1, ans[i], i, 1, MAX - 1);
    }
    for (int i = 1; i <= n;i++)
        printf("%d ", ans[i]);
    return 0;
}