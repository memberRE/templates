#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+20;
struct ppp{
	int pow,id;
	ll val;
}pic[MAX];
priority_queue<ll> que;
int n,K;
ll ans[MAX],tem_k[16];
bool cam(ppp a,ppp b)
{
	return a.pow<b.pow;
}
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)
		scanf("%d",&pic[i].pow);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&pic[i].val);
		pic[i].id=i;
	}
	sort(pic+1,pic+1+n,cam);
	for(int i=1;i<=n;i++)
	{
		ll tem_ans=0;
		int j=1,topp=0;
		while((!que.empty()) and j<=K)
		{
			tem_ans+=que.top();
			tem_k[topp++]=que.top();
			que.pop();
			j++;
		}
		ans[pic[i].id]=tem_ans+pic[i].val;
		for(j=0;j<topp;j++)
			que.push(tem_k[j]);
		que.push(pic[i].val);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	return 0;
}
