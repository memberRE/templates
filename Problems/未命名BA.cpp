#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ppp{
	int next ,to;
}edge[2509];
int head[55],dp[52][52],nnum=0;
bool vztd[52][52];
int n;
void addedge(int u,int v)
{
	nnum++;
	edge[nnum].to=v;
	edge[nnum].next=head[u];
	head[u]=nnum;
}
int dfs(int gst,int mogg)
{
	int ans=-1;
	if(dp[gst][mogg]!=-1)
		return dp[gst][mogg];
	if(gst==mogg)
		{
			dp[gst][mogg]=2;
			return dp[gst][mogg];
		}
	for(int i=head[gst];i!=-1;i=edge[i].next)
		if(edge[i].to==0)
			{
				dp[gst][mogg]=1;
				return dp[gst][mogg];
			}
	vztd[gst][mogg]=1;
	bool rettwo=1;
	int kknum=0;
	for(int i=head[gst];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=mogg)
		{
			bool allone=1,havtwo=0;
			for(int j=head[mogg];j!=-1;j=edge[j].next)
			{
				if(edge[j].to==0)	continue;
				kknum++;
				int k=-1;
				if(!vztd[edge[i].to][edge[j].to])
					k=dfs(edge[i].to,edge[j].to);
				if(k!=1)
					allone=0;
				if(k==2)
					havtwo=1;
			}
			if(allone)
			{
				ans=1;
				break;
			}
			if(!havtwo)
				rettwo=0;
		}
	}
	if(kknum==0)
	{
		vztd[gst][mogg]=0;
		dp[gst][mogg]=2;
		return dp[gst][mogg];
	}
	if(ans!=1)
	{
		if(rettwo)
			ans=2;
		else
			ans=0;
	}
	vztd[gst][mogg]=0;
	dp[gst][mogg]=ans;
	return dp[gst][mogg];
}
int main()
{
	cin>>n;// from 0 to n-1
	memset(head,-1,sizeof(head));
	memset(dp,-1,sizeof(dp));
	memset(vztd,0,sizeof(vztd));
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int k;
			cin>>k;
			addedge(i,k);
		}
	}
	cout<<dfs(1,2)<<endl;
//	dfs(1,2);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}	*/
	return 0;
}
