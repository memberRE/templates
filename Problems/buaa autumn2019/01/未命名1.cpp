#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXM=1e5+100;
const int MAXN=2090;
const long long INF=4557430888798830399;
typedef long long ll;
int head[MAXN],to[MAXM],nex[MAXM],val[MAXM],tot;
ll dis[MAXN][MAXN],adder,ans[300005];
bool vztd[MAXN][MAXN];
queue<pair<int,int> > q;
pair<int,ll> stk[MAXN];
int topp;
int n,m,s,t,Q;
void add(int x,int y,int z)
{
	tot++;
	to[tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
	val[tot]=z;
}
void init()
{
	memset(head,0,sizeof(head));
	memset(ans,0,sizeof(ans));
	topp=0;
	tot=0;
	adder=0;
}
void spfa()
{
	while(!q.empty())
		q.pop();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=INF,vztd[i][j]=0;
	//memset(vztd,0,sizeof(vztd));
	dis[s][0]=0;
	vztd[s][0]=1;
	q.push(pair<int,int>(s,0));
	while(!q.empty())
	{
		int x=q.front().first;
		int ct=q.front().second;
		q.pop();
		vztd[x][ct]=0;
		if(ct>=n-1)	continue;
		for(int i=head[x];i;i=nex[i])
		{
			if(dis[x][ct]+val[i]<dis[to[i]][ct+1])
			{
				dis[to[i]][ct+1]=dis[x][ct]+val[i];
				if(!vztd[to[i]][ct+1])
				{
					q.push(pair<int,int>(to[i],ct+1));
					vztd[to[i]][ct+1]=1;
				}
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d%d",&n,&m,&Q);
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		scanf("%d%d",&s,&t);
		spfa();
		for(int i=1;i<=n;i++)
		{
			if(dis[t][i]<INF)
				stk[topp++]=pair<int,ll>(i,dis[t][i]);
		}
		for(int i=1;i<=Q;i++)
		{
			scanf("%lld",&adder);
			if(ans[adder])
				printf("%lld\n",ans[adder]);
			else
			{
				ll mmin=INF;
				for(int j=0;j<topp;j++)
					mmin=min(mmin,(ll)stk[j].first*adder+stk[j].second);
				ans[adder]=mmin;
				printf("%lld\n",mmin);
			}
		}
	}
	return 0;
}
