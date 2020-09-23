#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <cassert>
#define MAXN 200005
#define MAXM 400005
using namespace std;
inline char gal()
{
	char c=getchar();
	while (!isalpha(c)) c=getchar();
	return c;
}
inline int read()
{
	int ans=0;
	char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) ans=(ans<<3)+(ans<<1)+(c^48),c=getchar();
	return ans;
}
typedef long long ll;
vector<int> e[MAXN];
int w[MAXN];
int sig[MAXN],ind[MAXN],siz[MAXN],rad[MAXN],ch[MAXN][2],fa[MAXN],tot;
ll val[MAXN],sum[MAXN],lzy[MAXN];
inline int newnode(int v,int type)
{
	++tot,siz[tot]=1,sum[tot]=val[tot]=v*type,sig[tot]=ind[tot]=type,rad[tot]=rand();
	return tot;
}
inline void update(int x)
{
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1,ind[x]=ind[ch[x][0]]+ind[ch[x][1]]+sig[x];
	sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+val[x];
}
inline void pushlzy(int x,ll v){val[x]+=sig[x]*v,sum[x]+=v*ind[x],lzy[x]+=v;}
inline void pushdown(int x)
{
	if (lzy[x])
	{
		if (ch[x][0]) pushlzy(ch[x][0],lzy[x]);
		if (ch[x][1]) pushlzy(ch[x][1],lzy[x]);
		lzy[x]=0;
	}
}
int merge(int x,int y)
{
	if (!x||!y) return x|y;
	pushdown(x),pushdown(y);
	if (rad[x]<rad[y]) return ch[x][1]=merge(ch[x][1],y),ch[x][1]&&(fa[ch[x][1]]=x),update(x),x;
	return ch[y][0]=merge(x,ch[y][0]),ch[y][0]&&(fa[ch[y][0]]=y),update(y),y;
}
void split(int x,int k,int& l,int& r)
{
	if (!x) return (void)(l=r=0);
	pushdown(x);
	if (k<=siz[ch[x][0]]) split(ch[x][0],k,l,r),fa[ch[x][0]]=0,ch[x][0]=r,r&&(fa[r]=x),update(x),r=x;
	else split(ch[x][1],k-siz[ch[x][0]]-1,l,r),fa[ch[x][1]]=0,ch[x][1]=l,l&&(fa[l]=x),update(x),l=x;
}
int rt,l[MAXN],r[MAXN];
inline void modify(int l,int r,int v)
{
	int a,b,c,d;
	split(rt,l-1,a,d);
	split(d,r-l+1,b,c);
	pushlzy(b,v);
	rt=merge(merge(a,b),c);	
}
inline int getrk(int x)
{
	int f=1,ans=0;
	while (x)
	{
		if (f) ans+=siz[ch[x][0]]+1;
		f=(ch[fa[x]][1]==x),x=fa[x];
	}
	return ans;
}
void dfs(int u)
{
	int t;
	t=merge(rt,l[u]=newnode(w[u],1)),rt=t;
	for (int i=0;i<(int)e[u].size();i++) dfs(e[u][i]);
	t=merge(rt,r[u]=newnode(w[u],-1)),rt=t;
}
int main()
{
	int n=read();
	for (int i=2;i<=n;i++) e[read()].push_back(i);
	for (int i=1;i<=n;i++) w[i]=read();
	dfs(1);
	for (int T=read();T;T--)
	{
		char op=gal();
		if (op=='Q') 
		{
			int a,b;
			split(rt,getrk(l[read()]),a,b);
			printf("%lld\n",sum[a]);
			rt=merge(a,b);
		}
		if (op=='C')
		{
			int x,y;
			x=read(),y=read();
			int a,b,c,d,e;
			split(rt,getrk(l[x])-1,a,d);
			split(d,getrk(r[x]),b,c);
			e=merge(a,c);
			split(e,getrk(l[y]),a,c);
			rt=merge(merge(a,b),c);
		}
		if (op=='F')
		{
			int x,v;
			x=read(),v=read();
			modify(getrk(l[x]),getrk(r[x]),v);
		}
	}
	return 0;
}