#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=1e5+20;
int head[MAX],to[MAX<<1],nex[MAX<<1],val[MAX<<1];
int n,tot;
int dp[MAX],F[MAX];
void add(int x,int y,int z)
{
	tot++;
	to[tot]=y;
	val[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=nex[i])
	{
		int v=to[i];
		if(v==fa)
			continue;
		dfs(v,u);
		F[u]=max(dp[u]+dp[v]+val[i],F[u]);
		dp[u]=max(dp[v]+val[i],dp[u]);
		
	}
}
int main()
{
	int x,y,z;
	while(scanf("%d%d%d",&x,&y,&z)!=EOF)
		add(x,y,z),add(y,x,z);
	n=(tot>>1)+1;
	dfs(1,-1);
	int ans=-1;
	for(int i=1;i<=n;i++)
		ans=max(ans,F[i]);
	cout<<ans;
	return 0;
}
