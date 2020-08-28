#include<bits/stdc++.h>
using namespace std;
const int MAX=4e5,INF=0x3f3f3f3f,MAXN=4e5;
struct ppp{
	int to,next ,flow;
}edge[MAX<<1];
int n,m,tot,s,t,maxflow;
int head[MAXN],cur[MAXN],dep[MAXN],gap[MAXN];
inline void add(int u,int v ,int w)
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
	gap[dep[t]]=1;
	queue<int>q;
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
	return;
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
	if(gap[dep[u]]==0)	dep[s]=n+m+3;
	dep[u]++;
	gap[dep[u]]++;
	return used;
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
int main()
{
	scanf("%d%d",&n,&m);//1~m user ;m+1~m+n facility
	memset(head,-1,sizeof(head));
	s=n+m+2,t=n+m+1;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		add(m+i,t,k);
		add(t,m+i,0);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans+=c;
		a+=m,b+=m;
		add(i,a,INF);
		add(a,i,0);
		add(i,b,INF);
		add(b,i,0);
		add(s,i,c);
		add(i,s,0);
	}
	isap();
	printf("%d",ans-maxflow);
	return 0;
}

