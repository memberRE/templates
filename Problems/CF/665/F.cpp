#include <cstring>
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#define ls (node << 1)
#define rs ((node << 1) | 1)
#define mid ((L + R) >> 1)
using namespace std;
typedef long long  ll;
const int MAX = (1 << 18) + 20;
int revisecnt[64],n,q,tf,pic[MAX];
ll sum[MAX << 2];
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
inline void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        sum[node] = pic[l];
        return;
    }
    ll midd = (l + r) >> 1;
    build(node << 1, l, midd);
    build((node << 1) | 1, midd + 1, r);
    sum[node] = (sum[node << 1] + sum[(node << 1) | 1]);
}
void change(int node,int goal,int new_val,int L,int R,int deep)
{
    if (L == R)
    {
        sum[node] = new_val;
        return;
    }
    else
    {
        if (goal <= mid)
            change((ls) ^ revisecnt[deep+1], goal, new_val, L, mid,deep+1);
        else
            change((rs) ^ revisecnt[deep+1], goal, new_val, mid+1, R,deep+1);
        sum[node] = sum[node << 1] + sum[(node << 1) | 1];
    }
}
ll query_sum(int node,int l,int r,int L,int R,int deep)
{
    if (L == l and R == r)
    {
        return sum[node];
    }
    else
    {
        if (r <= mid)
        {
            int temmm = (ls) ^ revisecnt[deep+1];
            int teee = revisecnt[deep+1];
            return query_sum((ls) ^ revisecnt[deep+1], l, r, L, mid,deep+1);
        }
        else if (l >= mid + 1)
        {
            return query_sum((rs) ^ revisecnt[deep+1], l, r, mid+1, R,deep+1);
        }
        else
            return query_sum((ls) ^ revisecnt[deep+1], l, mid, L, mid,deep+1) + query_sum((rs) ^ revisecnt[deep+1], mid + 1, r, mid+1, R,deep+1);
    }
}
int main()
{
    tf = read();
    q = read();
    n = 1 << tf;
    for (int i = 1; i <= n;i++)
        pic[i] = read();
    build(1, 1, n);
    for (int i = 1; i <= q;i++)
    {
        int op = read();
        if (op == 1)
        {
            int x = read(), k = read();
            change(1, x, k, 1, n,0);
        }
        else if (op == 2)
        {
            int k = read();
            if (k == 0)
                continue;
            int tem = tf - k  + 1;
            for (int i = tem; i <= tf;i++)
                revisecnt[i]^=1;
        }
        else if (op == 3)
        {
            int k = read();
            int tem = tf - k;
            revisecnt[tem]^=1;
        }
        else if (op == 4)
        {
            int l = read(), r = read();
            ll ans = query_sum(1, l, r, 1, n,0);
            printf("%lld\n", ans);
        }
        // cout << "### :";
        // for (int i = 0; i <= 18;i++)
        //     cout << revisecnt[i] << " ";
        // cout<<endl << "$$$:  ";
        // for (int i = 1; i <= n;i++)
        //     cout << query_sum(1, i, i, 1, n,0) << ' ';
        // cout << endl;
    }
    return 0;
}