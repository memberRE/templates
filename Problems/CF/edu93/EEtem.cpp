#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define show(x) std::cerr << #x << "=" << x << std::endl
using namespace std;
typedef long long ll;
const double eps=1e-8;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int q,t,d;
int n,m;
set<pii>s1;
set<pii,greater<pii> >s2;
int cnt;
ll sum1,sum2;
int k;///记录雷咒的总数
void debug()
{
    puts("s1:");
    for(auto it:s1)
    {
        printf("(%d %d) ",it.fi,it.se);
    }
    puts("");
    puts("s2:");
    for(auto it:s2)
    {
        printf("(%d %d) ",it.fi,it.se);
    }
    puts("");
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&t,&d);

        if(d>0)
        {
            if(s1.size() && d >= (*s1.begin()).fi)
            {
                s1.insert({d,t}), sum1+=d, cnt+=t; ///记录s1中雷咒的个数
            }
            else
            {
                s2.insert({d,t}), sum2+=d;
            }
            k+=t;
        }
        else
        {
            d = -d;
            if(s1.size() && d >= (*s1.begin()).fi)
            {
                s1.erase(s1.find({d,t})), sum1-=d, cnt-=t;
            }
            else
            {
                s2.erase(s2.find({d,t})), sum2-=d;
            }
            k-=t;
        }
        while(s1.size() > k)
        {
            pii p = *s1.begin();
            int vd = p.fi, vt = p.se;
            s1.erase(p), sum1-=vd, cnt-=vt;
            s2.insert({vd,vt}), sum2+=vd;
        }
        while(s1.size() < k)
        {
            pii p = *s2.begin();
            int vd = p.fi, vt = p.se;
            s1.insert({vd,vt}), sum1+=vd, cnt+=vt;
            s2.erase(p),sum2-=vd;
        }
        //debug();
        ll ans;
        if(k && cnt == k)  ///如果前k大的全是雷咒
        {
            ans = sum1*2 + sum2 - (s1.size()?( (*s1.begin()).fi ):0) + (s2.size()?( (*s2.begin()).fi ):0);
        }
        else ans = sum1*2 + sum2;
        printf("%lld\n",ans);
    }
    return 0;
}