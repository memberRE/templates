#include<bits/stdc++.h>
using namespace std;
const int MAX=1e3,INF=0x3f3f3f3f;
struct ppp{
	int to,next,flow;
}edge[10000];
int tot,head[MAX],cur[MAX],dep[MAX],gap[MAX],n,s,t,maxflow,x1=-1,x1s=-1,xn=-1,xnt=-1;
int pic[MAX],dp[MAX];
void add(int u,int v,int w)
{
	edge[tot]=(ppp){v,head[u],w};
	head[u]=tot;
	tot++;
}
void bfs()
{
	memset(dep,-1,sizeof(dep));
	memset(gap,0,sizeof(gap));
	dep[t]=0;
	gap[dep[t]]++;
	queue<int> q;
	q.push(t);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dep[v]!=-1)	continue;
			q.push(v);
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}
	return ;
}
int dfs(int u,int flow)
{
	if(u==t)
	{
		maxflow+=flow;
		return flow;
	}
	int used =0;
	for(int i=cur[u];i!=-1;i=edge[i].next)
	{
		cur[u]=i;
		int v=edge[i].to;
		if(edge[i].flow and dep[v]+1==dep[u])
		{
			int low=dfs(v,min(flow-used,edge[i].flow));
			if(low)
			{
				edge[i].flow-=low;
				edge[i^1].flow+=low;
				used+=low;
			}
			if(used==flow)	return flow;
		}
	}
	gap[dep[u]]--;
	if(!gap[dep[u]])	dep[s]=n*2+5;
	dep[u]--;
	gap[dep[u]]++;
	return used;
}
void isap()
{
	bfs();
	while(dep[s]<n*2+2)
	{
		memcpy(cur,head,sizeof(head));
		dfs(s,INF);
	}
}
int main()
{
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	s=n*2+1,t=n*2+2;
	int mmax=-1;
	for(int i=1;i<=n;i++)
	{
		add(i,i+n,1);
		add(i+n,i,0);//²ðµã i-->> i(in) and i+n(out)
		
		if(i==1)	 x1=tot-2;
		if(i==n)	 xn=tot-2;
		
		scanf("%d",&pic[i]);
		dp[i]=1;
		for(int j=1;j<i;j++)
			if(pic[j]<=pic[i])
				dp[i]=max(dp[i],dp[j]+1);
		mmax=max(mmax,dp[i]);
		if(dp[i]==1)
		{
			add(s,i,1);
			add(i,s,0);
			if(i==1)	x1s=tot-2;
		}	
		for(int j=1;j<i;j++)
			if(dp[j]+1==dp[i] and pic[j]<=pic[i])
			{
				add(j+n,i,1);
				add(i,j+n,0);
			}
	}
	for(int i=1;i<=n;i++)
		if(dp[i]==mmax)
		{
			add(i+n,t,1);
			add(t,i+n,0);
			if(i==n)
				xnt=tot-2;
		}
	isap();
	printf("%d\n%d\n",mmax,maxflow);
	if(x1!=-1)	edge[x1].flow=INF;
	if(x1s!=-1)	edge[x1s].flow=INF;
	if(xn!=-1)	edge[xn].flow=INF;
	if(xnt!=-1)	edge[xnt].flow=INF;
	isap();
	printf("%d",maxflow);
	return 0;
}
