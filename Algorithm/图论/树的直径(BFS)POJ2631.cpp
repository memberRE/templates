#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAX=1e5+20;
int head[MAX],to[MAX<<1],nex[MAX<<1],val[MAX<<1];
int n,tot;
int node,nodeval;
queue< pair<pair<int,int>,int> >que;
void add(int x,int y,int z)
{
	tot++;
	to[tot]=y;
	val[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
void bfs(int u)
{
	while(!que.empty())
		que.pop();
	que.push(make_pair(make_pair(u,u),0));
	int maxx=-1,maxnode=0;
	while(!que.empty())
	{
		int noww=que.front().first.first;
		int fa=que.front().first.second;
		int nowval=que.front().second;
		que.pop();
		if(nowval>maxx)
		{
			maxx=nowval;
			maxnode=noww;
		}
		for(int i=head[noww];i;i=nex[i])
			if(to[i]!=fa)
				que.push(make_pair(make_pair(to[i],noww),nowval+val[i]));
	}
	node=maxnode;
	nodeval=maxx;
}
int main()
{
	int x,y,z;
	while(scanf("%d%d%d",&x,&y,&z)!=EOF)
		add(x,y,z),add(y,x,z);
	n=(tot>>1)+1;
	bfs(1);
	bfs(node);
	cout<<nodeval;
	return 0;
}
