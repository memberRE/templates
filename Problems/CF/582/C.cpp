#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pic[16]={9999999999999999,10,5,10,5,2,5,10,5,10};
ll sum[16]={0,45,20,45,20,5,20,45,20,45};
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll n,m;
		scanf("%lld%lld",&n,&m);
		if(m%10==0)
		{
			printf("0\n");
			continue;
		}
			
		ll tem=n/m;
		ll jkl=tem/pic[m%10];
		ll ans=jkl*sum[m%10];
		ll jjj=tem%pic[m%10];
		if(jjj>20)	return 0;
		for(ll i=1;i<=jjj;i++)
			ans+=(m*i)%10;
		printf("%lld\n",ans);
	}
	return 0;
}
