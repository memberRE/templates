#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+20;
char s[MAX];
ll dp[2][MAX];
ll a,b;
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n>>a>>b;
		//a<<=1;
		//b<<=1;
		scanf("%s",s);
		dp[0][0]=b+a;
		dp[1][0]=99999999999999999;
		s[n]='0';
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1' or s[i]=='1')
			{
				dp[0][i]=-1;
				dp[1][i]=dp[1][i-1]+b*2+a;
				if(dp[0][i-1]>0)
					dp[1][i]=min(dp[1][i],dp[0][i-1]+a*2+b*2);
			}
			else
			{
				dp[0][i]=dp[1][i-1]+a*2+b;
				if(dp[0][i-1]>0)
					dp[0][i]=min(dp[0][i-1]+a+b,dp[0][i]);
				dp[1][i]=dp[1][i-1]+a+b*2;
				if(dp[0][i-1]>0)
					dp[1][i]=min(dp[1][i],dp[0][i]+a*2+b);
			}
		}
		printf("%lld\n",dp[0][n]-a);
	}
	return 0;
}

