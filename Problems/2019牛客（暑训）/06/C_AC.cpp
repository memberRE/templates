#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+20;
typedef long long ll;
struct ppp{
	ll h,c,num;
}pic[MAX];
int n;
ll ans,tem,tot;
ll sum[256];
bool cam(ppp a,ppp b)
{
	return a.h<b.h;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		ans=tem=tot=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&pic[i].h,&pic[i].c,&pic[i].num);
			tem+=pic[i].c*pic[i].num;
		}
		sort(pic+1,pic+1+n,cam);
		ans=tem+10;
		int j;
		for(int i=1;i<=n;i++)
		{
			j=i;
			while(pic[j].h==pic[i].h and j<=n)
				j++;
			j--;
			ll num=0;
			for(int k=i;k<=j;k++)
				num+=pic[k].num,tot+=pic[k].num,tem-=pic[k].num*pic[k].c;
			ll cutdown=tot-num*2+1;
			ll mony=0;
			for(int k=1;k<=200 and cutdown>0;k++)
				if(cutdown-sum[k]>=0)
				{
					mony+=sum[k]*k;
					cutdown-=sum[k];
				}
				else
				{
					mony+=cutdown*k;
					break;
				}
		//	cout<<tem<<' '<<mony<<endl;
			ans=min(ans,tem+mony);
			for(int k=i;k<=j;k++)
				sum[pic[k].c]+=pic[k].num;
			i=j;
		}
		printf("%lld\n",ans);
	}
}
