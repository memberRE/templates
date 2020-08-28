#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=55;
const int MAXM=1355;
int dp[2][MAXM+5][MAXM+5],stk[2][MAXM*MAXM];
int pic[MAX],n,top,a,b,cur;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		top=cur=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&pic[i]);
			pic[i]-=(a-1);
		}
		memset(dp,0x3f,sizeof(dp));
		dp[cur][0][0]=1;
		dp[cur][pic[1]][0]=0;
		dp[cur][0][pic[1]]=0;
		stk[cur][top++]=0;
		stk[cur][top++]=pic[1]*10000;
		stk[cur][top++]=pic[1];
		int x,y;
		for(int i=2;i<=n;i++)
		{
			int top2=0;
			for(int j=0;j<top;++j)
			{
				x=stk[cur][j]/10000;
				y=stk[cur][j]%10000;//1061109567
				if(dp[cur^1][x][y]!=0x3f3f3f3f)
					dp[cur^1][x][y]=min(dp[cur^1][x][y],dp[cur][x][y]+1); 
				else
				{
					dp[cur^1][x][y]=dp[cur][x][y]+1;
					stk[cur^1][top2++]=x*10000+y;
				}
				
				if(x+pic[i]<=MAXM)
				{
					if(dp[cur^1][x+pic[i]][y]!=0x3f3f3f3f)
						dp[cur^1][x+pic[i]][y]=min(dp[cur^1][x+pic[i]][y],dp[cur][x][y]); 
					else
					{
						dp[cur^1][x+pic[i]][y]=dp[cur][x][y];
						stk[cur^1][top2++]=(x+pic[i])*10000+y;
					}
				}
				if(y+pic[i]<=MAXM)
				{
					if(dp[cur^1][x][y+pic[i]]!=0x3f3f3f3f)
						dp[cur^1][x][y+pic[i]]=min(dp[cur^1][x][y+pic[i]],dp[cur][x][y]); 
					else
					{
						dp[cur^1][x][y+pic[i]]=dp[cur][x][y];
						stk[cur^1][top2++]=x*10000+y+pic[i];
					}	
				}
				dp[cur][x][y]=0x3f3f3f3f;
			}
			top=top2;
			cur^=1;
		}
		int mmin=0x3f3f3f3f;
		for(int i=0;i<=MAXM;i++)
			mmin=min(dp[cur][i][i],mmin);
		printf("%d\n",mmin);
	}
	return 0;	
}
