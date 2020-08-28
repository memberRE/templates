#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long  LL;
const int MAXN = 1e7 + 20, MOD = 998244353, G = 3, Gi = 332748118;
//  ;G is yuanGen
int n,m,l,rev[MAXN];
LL a[MAXN], b[MAXN];
inline LL qpower(LL a,LL b)
{
    LL ans = 1;
    while (b) 
    {
        if(b&1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
inline void NTT(LL *p,int len,int op)
{
    for (int i = 0; i < len;i++)
        if(i<rev[i])
            swap(p[i], p[rev[i]]);
    for (int mid = 1; mid < len;mid<<=1)
    {
        LL wn = qpower(op == 1 ? G : Gi, (MOD - 1) / (mid << 1));
        for (int j = 0; j < len;j+=(mid<<1))
        {
            LL w = 1;
            for (int k = 0; k < mid;k++,w=(w*wn)%MOD)
            {
                int x = p[j + k], y = w * p[j + k + mid] % MOD;
                p[j + k] = (x + y) % MOD;
                p[j + k + mid] = (x - y + MOD) % MOD;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<=m;i++)
        scanf("%lld",&b[i]);
    int len=1;
    while(len<n+1+m)	len<<=1,l++;//maybe error
    for(int i=0;i<len;i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    NTT(a, len, 1);
    NTT(b, len, 1);
    for(int i=0;i<len;i++)
        a[i] = a[i] * b[i] % MOD;
    NTT(a, len, -1);
    LL inv = qpower(len, MOD - 2);
    for(int i=0;i<=n+m;i++)
        printf("%lld ", (a[i] * inv) % MOD);
    return 0;
}
