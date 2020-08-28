#include<bits/stdc++.h>
#define maxn 651
#define INF 9999999
using namespace std;
int st[maxn],n,dp[maxn][maxn],sum[maxn];

int dostone(int i,int j)
{
	if(dp[i][j]&&dp[i][j]!=INF)	return dp[i][j];
	
	if(i==j)return 0;
	dp[i][j]=INF;
	for(int k=i;k<j;k++)
		dp[i][j]=min(dp[i][j],dostone(i,k)+dostone(k+1,j)+sum[j]-sum[i-1]);
	return dp[i][j];	
}

int main()
{
	cin>>n;
	memset(sum,0,sizeof(sum));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
		sum[i]=sum[i-1]+st[i];	
	}
	cout<<dostone(1,n);
	return 0;
}

