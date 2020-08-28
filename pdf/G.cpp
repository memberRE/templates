#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1e5+20;
struct ppp{
	int sum,minmod,num,l,r,lazy;
}tree[MAX<<2];
struct ret{
	int num,minmod;
};
int n,q;
int b[MAX];
int build(int node,int l,int r)
{
	int mid=(l+r)>>1;
	tree[node].sum=0;
	tree[node].l=l;
	tree[node].r=r;
	tree[node].num=1;
	tree[node].lazy=0;
	if(l==r)
		tree[node].minmod=b[l];
	else
	{
		tree[node].minmod=build(node<<1,l,mid);
		tree[node].minmod=build((node<<1)|1,mid+1,r);
	}
	return tree[node].minmod;
}
void upp(int node)
{
	if(tree[node].l!=tree[node].r)
	{
		tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
		if(tree[node<<1].minmod==tree[(node<<1)|1].minmod)
			tree[node].minmod=tree[node<<1].minmod,tree[node].num=tree[node<<1].num+tree[(node<<1)|1].num;
		else if(tree[node<<1].minmod>tree[(node<<1)|1].minmod)
			tree[node].minmod=tree[(node<<1)|1].minmod,tree[node].num=tree[(node<<1)|1].num;
		else
			tree[node].minmod=tree[node<<1].minmod,tree[node].num=tree[node<<1].num;
	}
}
void pushlazy(int node)
{
	if(tree[node].lazy>0)
	{
		tree[node<<1].minmod-=tree[node].lazy;
		tree[(node<<1)|1].minmod-=tree[node].lazy;
		if(tree[node<<1].l!=tree[node<<1].r)
			tree[node<<1].lazy+=tree[node].lazy;
		if(tree[(node<<1)|1].l!=tree[(node<<1)|1].r)
			tree[(node<<1)|1].lazy+=tree[node].lazy;
		tree[node].lazy=0;
	}
}
void pushdown(int node)
{
	pushlazy(node);
	if(tree[node].minmod==0)
	{
		if(tree[node].l==tree[node].r)
		{
			tree[node].sum+=tree[node].num;
			tree[node].minmod=b[tree[node].l];
			tree[node].lazy=0;
			tree[node].num=1;
		}
		else
		{
			pushdown(node<<1);
			pushdown((node<<1)|1);
		}
	}
	upp(node);
}
void add(int node,int l,int r)
{
	pushlazy(node);
	if(tree[node].l==l and tree[node].r==r)
	{
		tree[node].minmod--;
		tree[node].lazy++;
		pushlazy(node);
		if(tree[node].minmod==0)
		{
			tree[node].sum+=tree[node].num;
			pushdown(node<<1);
			pushdown((node<<1)|1);
		}
		upp(node);
		return ;
	}
	int mid=(tree[node].l+tree[node].r)>>1;
	if(r<=mid)
		add(node<<1,l,r);
	else if(l>=mid+1)
		add((node<<1)|1,l,r);
	else
		add(node<<1,l,mid),add((node<<1)|1,mid+1,r);
	upp(node);
}
int query(int node,int l,int r)
{
	if(tree[node].lazy>0)
		pushlazy(node);
	if(tree[node].l==l and tree[node].r==r)
		return tree[node].sum;
	int mid=(tree[node].l+tree[node].r)>>1;
	if(r<=mid)
		return query(node<<1,l,r);
	else if(l>=mid+1)
		return query((node<<1)|1,l,r);
	else
		return query(node<<1,l,mid)+query((node<<1)|1,mid+1,r);
}
int main()
{
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		getchar();
		build(1,1,n);
		char S[10];
		int x,y;
		for(int i=1;i<=q;++i)
		{
			scanf("%s%d%d",S,&x,&y);
			if(S[0]=='a')
				add(1,x,y);
			else
				printf("%d\n",query(1,x,y));
		}
	}
	return 0;
}
