#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+10; 
int head[MAX],to[MAX*MAX],next[MAX*MAX],linked[MAX],used[MAX],ans[MAX];
int n,tot;
void add(int u,int v)
{
	tot++;
	to[tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
inline int dfs(int u)
{
	for(int i=head[u];i;i=next[i])
	{
		int v=to[i];
		if(!used[v])
		{
			used[v]=1;
			if(linked[v]==-1 or dfs(linked[v]))
			{
				linked[v]=u;
				ans[u]=v;
				return 1;
			}
		}
	}
	return 0;
}
int km()
{
	int res=0;
	memset(linked,-1,sizeof(linked));
	for(int i=n-1;i>=0;i--)
	{
		memset(used,0,sizeof(used));
		res+=dfs(i);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int d,k1,k2;
		scanf("%d",&d);
		k1=(i+d)%n;
		k2=(i-d+n)%n;
		if(k1>k2)	swap(k1,k2);
		add(i,k2);
		add(i,k1);
	}
	if(km()<n)
		printf("No Answer\n");
	else
	{
		for(int i=0;i<n;i++)
		{
			printf("%d",ans[i]);
			if(i!=n)
				putchar(' ');
		}
	}
	return 0;
}
