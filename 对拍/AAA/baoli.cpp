#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
int a,b,n,pic[MAXN];
int dp[2][5500],cur;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&pic[i]);
			pic[i]-=(a-1);
		}
		memset(dp,0,sizeof(dp));
		dp[0][2550]=1;
		cur=0;
		for(int i=1;i<=n;i++)
		{
			cur^=1;
			for(int j=0;j<=5100;j++)
			{
				dp[cur][j]=dp[cur^1][j];
				if(j-pic[i]>=0 and dp[cur^1][j-pic[i]])
					dp[cur][j]=max(dp[cur][j],dp[cur^1][j-pic[i]]+1);
				if(j+pic[i]<=5000 and dp[cur^1][j+pic[i]])
					dp[cur][j]=max(dp[cur][j],dp[cur^1][j+pic[i]]+1);
				if(dp[cur][j])
					cout<<j<<' '<<dp[cur][j]<<endl;
			}
			system("pause");
		}
		int ans=n-(dp[cur][2550]-1);
		printf("%d\n",ans);
	}
	return 0;
}
