#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+20;
typedef long long ll;
struct ppp{
	ll num,atk;
}pic[MAX];
int n,cntt,jkl;
ll num[MAX],ans,summ;
bool cam(ppp a,ppp b)
{
	return a.num*b.atk<a.atk*b.num;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;;i++)
	{
		num[i]=num[i-1]+i;
		if(num[i]>500002)
		{
			cntt=i;
			break;
		}
	}
	while(t--)
	{
		scanf("%d",&n);
		ans=summ=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&pic[i].num,&pic[i].atk);
			summ+=pic[i].atk;
			pic[i].num=lower_bound(num,num+cntt+1,pic[i].num)-num;
		}
		sort(pic+1,pic+1+n,cam);
		for(int i=1;i<=n;i++)
		{
			ans+=pic[i].atk*pic[i].num;
			summ-=pic[i].atk;
			ans+=summ*pic[i].num;
		}
		jkl++;
		printf("Case #%d: %lld\n",jkl,ans);
	}
	return 0;
}
