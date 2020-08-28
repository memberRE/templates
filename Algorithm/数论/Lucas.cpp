#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=1e5+20;
typedef long long ll;
ll a[MAX];
ll p;
ll qpow(ll y,ll z,ll p )
{
	y%=p;
	ll ans=1;
	for(int i=z;i;i>>=1,y=y*y%p)
		if(i&1)	ans=ans*y%p;
	return ans;
}
ll cm(ll n,ll m)
{
	if(m>n)	return 0;
	return (a[n]*qpow(a[m],p-2,p))%p*qpow(a[n-m],p-2,p)%p;
}
ll lucas(ll n,ll m,ll p)
{
	if(!m)	return 1;
	return cm(n%p,m%p)*lucas(n/p,m/p,p)%p;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld%lld%lld",&n,&m,&p);
		a[0]=1;
		for(int i=1;i<=p;++i)//Ô¤´¦Àí½×³Ë%p 
			a[i]=(a[i-1]*i)%p;
		printf("%lld\n",lucas(n+m,n,p)); 
	}
}
