#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
struct mat{
	ll m[2][2];
}a,e;
//ll base[4]={1,1,1,1};
ll n,q;
mat mul(mat x,mat y)
{
	mat c;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			c.m[i][j]=0;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				c.m[i][j]=c.m[i][j]%MOD+x.m[i][k]*y.m[k][j]%MOD;
	return c;
}
mat  qpower(mat x,ll y)
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
	scanf("%lld%lld",&q,&n);
	for(int i=1;i<=2;i++)
		e.m[i][i]=1;
	a.m[1][1]=3;a.m[1][2]=2;a.m[2][1]=1;
	ll lasans=0,lasn=n,ans=0;
	while(q--)
	{
		ll N=lasn^(lasans*lasans);
		if(N==0)
		{
			ans^=0;
			lasans=0;
			lasn=N;
		}
		else if(N==1)
		{
			ans^=1;
			lasans=1;
			lasn=N;
		}
		else
		{
			mat ANS=qpower(a,N-2);
			ans^=(ANS.m[1][1]%MOD);
			lasans=ANS.m[1][1];
			lasn=N;
			//printf("%lld\n",(+ans.m[1][2]+ans.m[1][3])%MOD);
		}
	}
	return 0;
}
