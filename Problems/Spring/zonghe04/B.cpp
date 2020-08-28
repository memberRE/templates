#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAX=105;
int head[MAX],pic[MAX],nex[MAX<<1],to[MAX<<1];
int tot,n,m;
int vztd[MAX];
queue<int> que;
void add(int u,int v)
{
	tot++;
	to[tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
int dfs(int u,int fa,int maxdis,int dis)
{
	int ans=pic[u];
	if(maxdis==dis)	return ans;
	for(int i=head[u];i;i=nex[i])
	{
		int v=to[i];
		if(vztd[v] and v!=fa)
			ans+=dfs(v,u,maxdis,dis+1);
	}
	return ans;
}
bool check(int k)
{
	memset(vztd,0,sizeof(vztd));
	while(!que.empty())	que.pop();
	que.push(1);
	while(!que.empty())
	{
		int noww=que.front();
		que.pop();
		vztd[noww]=1;
		int cnt=dfs(noww,0,k,0);
		if(cnt>=m)	return true;
		for(int i=head[noww];i;i=nex[i])
		{
			int v=to[i];
			if(!vztd[v])
				que.push(v);
		}
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++8)
		scanf("%d",&pic[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	int l=0,r=n; //[)
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<r;
	return 0;
}
