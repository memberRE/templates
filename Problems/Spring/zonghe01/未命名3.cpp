#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAX=1e5+5;
const long long MOD=1e9+7;
typedef long long ll;
int n;
char pic[MAX];
ll jc[MAX];
ll num[10];
ll qpower(ll a,ll b,ll c)
{
	ll ans=1;
	a%=c;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%c;
		b=b>>1;
		a=(a*a)%c;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",pic);
	for(int i=0;pic[i];i++)
	{
		if(pic[i]=='A')
			num[0]++;
		if(pic[i]=='T')
			num[1]++;
		if(pic[i]=='C')
			num[2]++;
		if(pic[i]=='G')
			num[3]++;
	}
	jc[0]=jc[1]=1;
//	for(int i=2;i<=n;i++)
//		jc[i]=(jc[i-1]*i)%MOD;
	sort(num,num+4); 
	ll maxx=-1,cnt=0;
	for(int i=3;i>=0;i--)
	{
		if(num[i]>maxx)
			maxx=num[i],cnt=1;
		else if(num[i]==maxx)
			cnt++;
	}
	cout<<qpower(cnt,n,MOD);
//	unsigned long long ans=jc[n];
//	for(int i=0;i<4;i++)
//	{
//		ans*=qpower(jc[num[i]],MOD-2,MOD);
//		ans%=MOD;
//	}
//	cout<<ans;
	return 0;
}
