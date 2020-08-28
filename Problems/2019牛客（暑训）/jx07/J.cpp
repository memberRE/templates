#include<bits/stdc++.h>
using namespace std;
const int MAXN=10200;
const int MAXM=512;
int m,n,s[MAXN];
double pic[MAXM][MAXM],dp[MAXN][MAXM];
int main()
{
	while(scanf("%d",&m)!=EOF)
	{
		m=m*(m-1)*(m-2);
		m/=6;
		for(int i=0;i<m;++i)
			for(int j=0;j<m;++j)
				scanf("%lf",&pic[i][j]);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=0;i<m;i++)
			dp[n][i]=pic[i][s[n]];
		for(int i=n-1;i>=1;i--)
			for(int j=0;j<m;j++)
				dp[i][j]=pic[j][s[i]]*max(dp[i+1][j],dp[i+1][s[i]]);	
		double ans=0.0;	
		for(int i=0;i<m;i++)
			ans=max(ans,dp[1][i]);
		printf("%lf\n",ans);
	}
	return 0;
}
