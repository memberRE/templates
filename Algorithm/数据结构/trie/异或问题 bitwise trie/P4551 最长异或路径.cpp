#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct ppp{
	int son[2];
}trie[MAX*32];
int n,head[MAX],nex[MAX<<1],to[MAX<<1],val[MAX<<1];
int XOR[MAX];
int tot,root=1;
int maxx=-1;
void add(int u,int v,int w)
{
	tot++;
	to[tot]=v;
	val[tot]=w;
	nex[tot]=head[u];
	head[u]=tot;
}
void dfs(int u,int deep,int fa)
{
	XOR[u]=deep;
	for(int i=head[u];i;i=nex[i])
		if(to[i]!=fa)
			dfs(to[i],XOR[u]^val[i],u);
}
void creat_trie(int x)
{
	x=XOR[x];
	int noww=root;
	for(int i=30;i>=0;i--)
	{
		int u=x&(1<<i);
		if(u!=0)	u=1;
		if(!trie[noww].son[u])
			trie[noww].son[u]=tot++;
		noww=trie[noww].son[u];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0,0);
	tot=2;
	for(int i=1;i<=n;i++)
		creat_trie(i);
	for(int i=1;i<=n;i++)
	{
		int noww=root,ans=0,x=XOR[i];
		for(int i=30;i>=0;i--)
		{
			int k=x&(1<<i);
			if(k!=0)	k=1;
			k^=1;
			ans<<=1;
			if(trie[noww].son[k])
			{
				noww=trie[noww].son[k];
				ans|=1;
			}
			else
				noww=trie[noww].son[k^1];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
//4
//1 2 3
//2 3 4
//2 4 6
