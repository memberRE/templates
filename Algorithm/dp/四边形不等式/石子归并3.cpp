#include<bits/stdc++.h>
using namespace std;
const int MAX=3050;
int pic[MAX],sum[MAX]; 
int dp[MAX][MAX],s[MAX][MAX];
int main()
{
	int n;
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pic[i]);
		sum[i]=sum[i-1]+pic[i];
	}
	for(int i=1;i<=n;i++)
		s[i][i]=i,dp[i][i]=0;;
	for(int l=1;l<n;l++)
	{
		for(int i=1;i<n;i++)
		{
			if(l+i>n)
				break;
			for(int k=s[i][i+l-1];k<=s[i+1][i+l];k++)
				if(dp[i][i+l]>=dp[i][k]+dp[k+1][i+l])
				{
					dp[i][i+l]=dp[i][k]+dp[k+1][i+l];
					s[i][i+l]=k;
				}
			dp[i][i+l]+=sum[i+l]-sum[i-1];
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
