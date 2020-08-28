#include<bits/stdc++.h>
using namespace std;
const int MAX=3e4,INF=0x3f3f3f3f;
struct ppp{
	int to,next,flow;
}edge[MAX<<1];
int n,m,tot,maxflow,s,t;
int head[MAX],cur[MAX],dep[MAX],gap[MAX];
void add(int u,int v,int w)
{
	edge[tot]=(ppp){v,head[u],w};
	head[u]=tot;
	tot++;
}
int dfs(int u,int flow)
{
	if(u==t)
	{
		maxflow+=flow;
		return flow;
	}
	int used=0;
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
			if(used ==flow )	return  used;
		}
	}
	gap[dep[u]]--;
	if(gap[dep[u]]==0)	dep[s]=n+m+3;
	dep[u]++;
	gap[dep[u]]++;
	return used;
}
void bfs()
{
	memset(dep,-1,sizeof(dep));
	memset(gap,0,sizeof(gap));
	dep[t]=0;
	queue<int> q;
	q.push(t);
	gap[dep[t]]++;
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
void isap()
{
	bfs();
	while(dep[s]<n+m+2)
	{
		memcpy(cur,head,sizeof(head));
		dfs(s,INF);
	}
}
void print()
{
	for(int i=1;i<=m;i++)
	{
		printf("%d:",i);
		for(int j=head[i];j!=-1;j=edge[j].next)
			if(edge[j].to>m and edge[j].to<=m+n and edge[j].flow)
				printf(" %d",edge[j].to-m);
		putchar('\n');
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&m,&n);
	int sum=0;
	s=m+n+1,t=n+m+2;
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		add(i,t,k);
		add(t,i,0);
		sum+=k;
	}
	for(int i=1;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		for(int j=1;j<=p;j++)
		{
			int k;
			scanf("%d",&k);
			add(i+m,k,1);
			add(k,i+m,0);
		}
		add(s,i+m,1);
		add(i+m,s,0);
	}
	isap();
	if(maxflow<sum)
		printf("No Solution!");
	else
		print();
	return 0;
}
