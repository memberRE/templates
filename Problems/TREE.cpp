#include<bits/stdc++.h>
using namespace std;
const int MAX=4e5+20;
int head[MAX],nex[MAX<<1],to[MAX<<1],val[MAX<<1],tot;
int n,K,root=1,ans;
int all_node,subt_siz[MAX],size_self[MAX];
int vztd[MAX],dep[MAX],len[MAX];
int belong[MAX],cnt_sbt[MAX];
bool cam(int u,int v)
{
	return dep[u]<dep[v];
}
void add(int u,int v,int w)
{
	tot++;
	nex[tot]=head[u];
	to[tot]=v;
	val[tot]=w;
	head[u]=tot;
}
void get_root(int u,int fa)
{
	subt_siz[u]=0;
	size_self[u]=1;
	for(int i=head[u];i;i=nex[i])
	{
		int v=to[i];
		if(v==fa or vztd[v])	continue;
		get_root(v,u);
		size_self[u]+=size_self[v];
		subt_siz[u]=max(subt_siz[u],size_self[v]);
	}
	subt_siz[u] = max(subt_siz[u], all_node-size_self[u]); 
	if(subt_siz[u]<subt_siz[root])
		root=u;
	//root=(subt_siz[u]>subt_siz[root])?u:root;
}
void get_len(int u,int fa,int bel)
{
	len[++len[0]]=u;
	belong[u]=bel;//node u is belong to subtree_bel
	for(int i=head[u];i;i=nex[i])
	{
		int v=to[i],w=val[i];
		if(v==fa or vztd[v])	continue;
		dep[v]=dep[u]+w;
		if(u==root)
			get_len(v,u,v);
		else
			get_len(v,u,bel);
	}
}
int cal(int u)
{
	dep[u]=0;
	len[0]=0;
	get_len(u,0,0);
	sort(len+1,len+1+len[0],cam);
	for(int i=1;i<=len[0];i++)
		cnt_sbt[belong[len[i]]]=0;
	for(int i=1;i<=len[0];i++)
		cnt_sbt[belong[len[i]]]++;
	int tem_ans=0;
	for(int l=1,r=len[0];l<r;)
	{
		if(dep[len[l]]+dep[len[r]]<=K)
		{
			tem_ans+=(r-l);
			cnt_sbt[belong[len[l]]]--;
			tem_ans-=(cnt_sbt[belong[len[l]]]);
			l++;
		}
		else
		{
			cnt_sbt[belong[len[r]]]--;
			r--;
		}
	}
	return tem_ans;
}
void work(int u) //u is the centroid of tree
{
	vztd[u]=1;
	ans+=cal(u);
	for(int i=head[u];i;i=nex[i])
	{
		int v=to[i];
		if(vztd[v])	continue;
		all_node=size_self[v];
		root=v;
		get_root(v,u);
		work(root);
	}
}
int main()
{
	scanf("%d",&n);
	all_node=n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	scanf("%d",&K);
	get_root(1,0);
	work(root);
	cout<<ans;
	return 0;
}
