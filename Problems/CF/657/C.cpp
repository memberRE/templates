#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
struct ppp{
    ll val;
    ll nexval;
    int type;
    /*ll get_bjcal()
    {
        if(type == 0)
            return val + nexval;
        else
            return val*2;
    }*/
    bool operator < (const ppp &a) const {
        /*if(val != a.val)
            return val < a.val;
        else
            return type < a.type;*/
        ll tem = type == 0 ? val + nexval : val * 2;
        ll tem2 = a.type == 0 ? a.val + a.nexval : a.val * 2;
        return tem > tem2;
    }
} pic[100005];
priority_queue<ppp> que;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        ll maxx = -1;
        while(!que.empty())
            que.pop();
        for (int i = 1; i <= m;i++)
        {
            ll o, p;
            scanf("%lld%lld", &o, &p);
            maxx = max(maxx, o);
            pic[i].val = o;
            pic[i].nexval = p;
            pic[i].type = 0;
            que.push(pic[i]);
        }
        if(n == 1)
        {
            printf("%lld\n", maxx);
            continue;
        }
        ll ans = 0;
        while(n > 0)
        {
            ppp tem = que.top();
            if(tem.type == 0)
            {
                que.pop();
                tem.type = 1;
                swap(tem.val, tem.nexval);
                ans += tem.nexval + tem.val;
                n -= 2;
                if(n < 0)
                    ans -= min(tem.nexval, tem.val);
            }
            else
            {
                
            }
        }
    }
}