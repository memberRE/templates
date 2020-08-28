#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1020;
const ll MOD=1e9+7;
ll q[MAXN],x[MAXN],sum[MAXN][MAXN],pre_sum[MAXN][MAXN],dp[MAXN][MAXN];
ll tem[MAXN];
ll n,t;
int main()
{
	freopen("kebab.in","r",stdin);
	freopen("kebab.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(ll i=1;i<=n;++i)
		scanf("%lld%lld",&q[i],&x[i]);
	for(ll i=0;i<=t;i++)
		sum[0][i]=1;
	pre_sum[0][t]=1;
	for(ll k=1;k<=n;k++)
	{
		memset(tem,0,sizeof(tem));
		for(ll i=1;i<=q[k];++i)
		{
			dp[i][0]=0;
			if(i-t>0)//自己那块的贡献 
				for(ll j=1;j<=min(q[k]-x[k],i-t);++j)
					tem[j]+=dp[i-t][j]%MOD,tem[j]%=MOD;//j or j-1
			for(ll j=1;j<=min(q[k]-x[k],i);++j)
			{
				if(j==1)
				{
					if(i>=t)
						dp[i][j]=sum[k-1][0];
					else
						dp[i][j]=sum[k-1][t-i];
				}
				else
				{
					if(i-t<0)
						dp[i][j]=0;
					else
						dp[i][j]=tem[j-1];
				}
				pre_sum[k][min(t,q[k]-i)]+=dp[i][j];
				pre_sum[k][min(t,q[k]-i)]%=MOD;
//				pre_sum[k][i]+=dp[i][j];
//				pre_sum[k][i]%=MOD;
			}
		}
		for(ll i=0;i<=t;i++)
		{
			pre_sum[k][min(t,q[k]+i)]+=pre_sum[k-1][i];
			pre_sum[k][min(t,q[k]+i)]%=MOD;
		}
			//pre_sum[k][min(q[i]+i,t)]+=pre_sum[k-1][i],pre_sum[k][min(i+q[i],t)]%=MOD;
		sum[k][t]=pre_sum[k][t];
		for(ll i=t-1;i>=0;i--)
			sum[k][i]=(pre_sum[k][i]+sum[k][i+1])%MOD;
	}
	printf("%lld",sum[n][0]);
	return 0;
}
/*
3 1
4 3
2 2
2 1
*/
