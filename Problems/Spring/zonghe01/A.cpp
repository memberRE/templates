#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
struct ppp{
	ll noww;
	int step;
	ppp (ll nowww=0,int stepp=0){noww=nowww,step=stepp;}
};
queue<ppp>que;
//map<ll,ll> M;
ll M[1000007];
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	if(n>m)
	{
		printf("%lld\n",n-m);
		return 0;
	}
	que.push((ppp){n,0});
	while(!que.empty())
	{
		ppp x=que.front();
		que.pop();
		ll xx=x.noww;
		if(xx-1==m or xx*2==m)
		{
			printf("%d",x.step+1);
			return 0;
		}
		else 
		{
			if(xx-1>0 and /*M.count(xx-1)*/M[xx-1]==0)
			{
				que.push((ppp){xx-1,x.step+1});
				M[xx-1]=1;
			}
			if(/*M.count(xx*2)*/M[xx*2]==0)
			{
				que.push((ppp){xx*2,x.step+1});
				M[xx*2]=1;
			}
		}
	}
	return 0;
}
