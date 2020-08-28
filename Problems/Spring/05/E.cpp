#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=1e5+5;
int head[MAX],data[MAX],edge[MAX<<1],nex[MAX<<1],deep[MAX],fa[MAX];
int pic[MAX],arm[MAX],ans[MAX],yh[2][MAX];
int n,tot,anstot;
queue<int> que;
void add(int u,int v)
{
	tot++;
	edge[tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=head[u];i;i=nex[i])
		if(edge[i]!=fa[u])
			dfs(edge[i],u);
}
void bfs()
{
	que.push(1);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		int flag=0;
		if((pic[u]^yh[1][u])!=arm[u])
		{
			ans[anstot++]=u;
			flag^=1;
		}
			
		for(int i=head[u];i;i=nex[i])
			if(edge[i]!=fa[u])
			{
				yh[1][edge[i]]=yh[0][u];
				yh[0][edge[i]]=yh[1][u]^flag;
				que.push(edge[i]);
			}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&pic[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&arm[i]);
	dfs(1,-1);
	bfs();
	printf("%d\n",anstot);
	for(int i=anstot-1;i>=0;i--)
		printf("%d\n",ans[i]);
	return 0;
}
