#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
struct mat{
	ll m[102][102];
}a,e;
ll n,p;
mat mul(mat x,mat y)
{
	mat c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c.m[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				c.m[i][j]=c.m[i][j]%MOD+x.m[i][k]*y.m[k][j]%MOD;
	return c;
}
mat quickpow(mat x,ll y)	//X^y
{
	mat ans=e;
	while(y)
	{
		if(y&1)
			ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int main()
{
	cout<<(int)'\n';
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a.m[i][j]);
	for(int i=1;i<=n;i++)
		e.m[i][i]=1;
	mat ans=quickpow(a,p);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",ans.m[i][j]%MOD);
		putchar('\n');
	}
	return 0;
}
