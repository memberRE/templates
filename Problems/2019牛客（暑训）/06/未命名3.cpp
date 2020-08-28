#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct tree
{
	LL h,c,p;
} a[100005];
bool cmp(tree a,tree b)
{
	return a.h<b.h;
}
LL n;
LL tmp=0,ans=0,tot=0;
LL num[205];
int main()
{
	while(cin>>n)
	{
		memset(num,0,sizeof(num));
		ans=tmp=tot=0;
		for(LL i=0; i<n; ++i)
		{
			scanf("%lld%lld%lld",&a[i].h,&a[i].c,&a[i].p);
			tmp+=a[i].c*a[i].p;
		}
		ans=tmp;
		sort(a,a+n,cmp);
		for(LL i=0,j; i<n; i=j)
		{
			j=i;
			while(a[j].h==a[i].h&&j<n)++j;
			LL sum=0;
			LL cost=0;
			for(LL t=i; t<j; ++t)
			{
				tmp-=a[t].c*a[t].p;
				tot+=a[t].p;
				sum+=a[t].p;
			}
			sum=tot-sum*2+1;
			cout<<sum<<endl;
			for(LL w=1; sum>0; ++w)
			{
				if(num[w]<=sum)
				{
					cost+=w*num[w];
					sum-=num[w];
				}
				else
				{
					cost+=sum*w;
					break;
				}
			}
			ans=min(ans,cost+tmp);
		//	cout<<tmp<<' '<<cost<<endl;
			for(LL t=i; t<j; ++t)
				num[a[t].c]+=a[t].p;
		}
		cout<<ans<<endl;
	}
}
