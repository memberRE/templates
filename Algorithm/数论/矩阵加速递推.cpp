#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
struct mat{
	ll m[4][4];
}a,e;
//ll base[4]={1,1,1,1};
ll n;
mat mul(mat x,mat y)
{
	mat c;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			c.m[i][j]=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
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
	int t;
	scanf("%d",&t);
	for(int i=1;i<=3;i++)
		e.m[i][i]=1;
	a.m[1][1]=a.m[1][3]=a.m[2][1]=a.m[3][2]=1;
	while(t--)
	{
		scanf("%lld",&n);
		if(n<=3)
			printf("1\n");
		else
		{
			mat ans=qpower(a,n-3);
			printf("%lld\n",(ans.m[1][1]+ans.m[1][2]+ans.m[1][3])%MOD);
		}
	}
	return 0;
}
