#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
//#define lowbit(x) (x&-x)
using namespace std;
using namespace std;
typedef long long  ll;
const int MAX=2e6+50;
ll tree[MAX],sum[MAX],n,m;
char s[MAX];

inline int lowbit(int x)
{
	return x& -x;
}
//void build_tree()
//{
//	for(int i=1;i<=n;i++)
//		tree[i]=sum[i]-sum[i-lowbit(i)];
//}
void add(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=(ll)k;
		x+=lowbit(x);
	}
}

ll qurry(int x)
{
	ll ans=0;
	while(x!=0)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
void cha(int x)
{
    int l = x;
    ll tem = /*sum[l] - sum[l - 1] + */qurry(l);
    tem += x - 1;
    tem %= n;
    if(tem < 0)
        tem += n;
    printf("%c", s[tem]);
}
int main()
{
	//scanf("%d%d",&n,&m);
    scanf("%s", s);
    scanf("%d", &m);
    getchar();
    n = strlen(s);
	//build_tree();
    ll ans = 0;
    for(int i=1;i<=m;i++)
	{
		char op;
        int x;
        scanf("%c %d", &op, &x);
        getchar();
		if(op=='M')
		{
			if(x < 0)
                x += n;
            if(x > 0)
            {
                ans += (ll)x;
                // int l = 1,r = x,val = n - x;
                // add(l, val);
                // add(r+1,-val);
                // add(r + 1, -x);
                // add(n + 1, x);
            }
            /*for (int i = 1; i <= n;i++)
                cha(i);*/
            /*else
            {
                x = abs(x);
                int l = n - x + 1,r = n,val = n - x;
                add(l, val);
                add(r+1,-val);
            }*/
		}
		else if(op == 'A')
		{
            /*cha(x);*/
            ll tem = ans + x - 1;
            tem %= n;
            putchar(s[tem]);
            putchar('\n');
        }
	}
	return 0;
}
