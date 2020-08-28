#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define ls (node<<1)
#define rs ((node<<1)|1)
using namespace std;
const int MAX=1e5+20;
const int MAXN=17;
struct ppp{
	int sum[MAXN];
	int laz[MAXN],flag;//2 xor
}tree[MAX<<2];
int n,m;
int pic[MAX];
void build(int node,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<MAXN;i++)
			tree[node].sum[i]=(pic[l]&(1<<i))>0?1:0;
		return ;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	for(int i=0;i<MAXN;i++)
		tree[node].sum[i]=tree[ls].sum[i]+tree[rs].sum[i];
}
void pushdown(int node,int l,int r)
{
	if(l==r)
	{
		tree[node].flag=0;
		return ;
	}
	int mid=(l+r)>>1;
	if(tree[ls].flag)
		pushdown(ls,l,mid);
	if(tree[rs].flag)
		pushdown(rs,mid+1,r);
	int lenls=mid-l+1,lenrs=r-mid-1+1;
	if(tree[node].flag==2)
	{
		tree[ls].flag=tree[node].flag;
		tree[rs].flag=tree[node].flag;
		for(int i=0;i<MAXN;i++)
		{
			tree[ls].laz[i]=tree[rs].laz[i]=tree[node].laz[i];
			if(tree[node].laz[i])
			{
				tree[ls].sum[i]=lenls-tree[ls].sum[i];
				tree[rs].sum[i]=lenrs-tree[rs].sum[i];
			}
		}	
	}
	if(tree[node].flag==3)
	{
		tree[ls].flag=tree[node].flag;
		tree[rs].flag=tree[node].flag;
		for(int i=0;i<MAXN;i++)
		{
			tree[ls].laz[i]=tree[rs].laz[i]=tree[node].laz[i];
			if(tree[node].laz[i])
			{
				tree[ls].sum[i]=lenls;
				tree[rs].sum[i]=lenrs;
			}
		}	
	}
	if(tree[node].flag==4)
	{
		tree[ls].flag=tree[node].flag;
		tree[rs].flag=tree[node].flag;
		for(int i=0;i<MAXN;i++)
		{
			tree[ls].laz[i]=tree[rs].laz[i]=tree[node].laz[i];
			if(tree[node].laz[i]==0)
			{
				tree[ls].sum[i]=0;
				tree[rs].sum[i]=0;
			}
		}
	}
	tree[node].flag=0;
	return ;
}
int query(int node,int l,int r,int L,int R)
{
	if(l==L and r==R)
	{
		int tem=0;
		for(int i=0;i<MAXN;i++)
			tem+=(tree[node].sum[i]<<i);
		return tem;
	}
	if(tree[node].flag)
		pushdown(node,L,R);
	int mid=(L+R)>>1;
	if(r<=mid)
		return query(ls,l,r,L,mid);
	else if(l>=mid+1)
		return query(rs,l,r,mid+1,R);
	else
		return query(ls,l,mid,L,mid)+query(rs,mid+1,r,mid+1,R);
}
void add(int node,int l ,int r,int L,int R,int x,int opt)
{
	if(tree[node].flag)
		pushdown(node,L,R);
	if(l==L and R==r)
	{
		tree[node].flag=opt;
		for(int i=0;i<MAXN;i++)
			tree[node].laz[i]=(x&(1<<i))>0?1:0;
		int len=R-L+1;
		if(opt==2)
		{
			for(int i=0;i<MAXN;i++)
				if(tree[node].laz[i])
					tree[node].sum[i]=len-tree[node].sum[i];
		}
		else if(opt==3)
		{
			for(int i=0;i<MAXN;i++)
				if(tree[node].laz[i])
					tree[node].sum[i]=len;
		}
		else if(opt==4)
		{
			for(int i=0;i<MAXN;i++)
				if(tree[node].laz[i]==0)
					tree[node].sum[i]=0;
		}
		return ;
	}
	int mid=(L+R)>>1;
	if(r<=mid)
		add(ls,l,r,L,mid,x,opt);
	else if(l>=mid+1)
		add(rs,l,r,mid+1,R,x,opt);
	else
		add(ls,l,mid,L,mid,x,opt),add(rs,mid+1,r,mid+1,R,x,opt);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&pic[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int opt,l,r,x;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			printf("%d\n",query(1,l,r,1,n));
		}
		else 
		{
			scanf("%d",&x);
			add(1,l,r,1,n,x,opt);
		}
	}
	return 0;
}

