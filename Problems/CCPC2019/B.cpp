#include<bits/stdc++.h>
#define ls (node<<1)
#define rs ((node<<1)|1)
using namespace std;
typedef long long ll;
const int MAX=1e5+50;
struct ppp{
	int l,r;
	ll minn;
}tree[MAX<<2];
int n,m;
ll pic[MAX],lasans=0;
void build(int l,int r,int node)
{
	int mid=(l+r)>>1;
	tree[node].l=l;
	tree[node].r=r;
	if(l==r)
		tree[node].minn=pic[l];
	else
	{
		build(l,mid,ls);
		build(mid+1,r,rs);
		tree[node].minn=min(tree[ls].minn,tree[rs].minn);
	}
}
void add(ll pos,int node)
{
	if(tree[node].l==tree[node].r)
	{
		tree[node].minn+=10000000;
		return ;
	}
	int mid=(tree[node].l+tree[node].r)>>1;
	if(pos<=(ll)mid)
		add(pos,ls);
	else
		add(pos,rs);
	tree[node].minn=min(tree[ls].minn,tree[rs].minn);
}
ll query(int node,int l,int r,ll k)
{
	int mid=(tree[node].l+tree[node].r)>>1;
	if(tree[node].l==tree[node].r)
	{
		if(tree[node].minn>=k)
			return tree[node].minn;
		else
			return 0;
	}
	if(tree[node].l==l and tree[node].r==r)
	{
		if(tree[node].minn>=k)
			return tree[node].minn;
		else
		{
			ll tem=query(ls,tree[ls].l,tree[ls].r,k);
			ll tem2=query(rs,tree[rs].l,tree[rs].r,k);
			if(tem==0 and tem2!=0)
				return tem2;
			if(tem!=0 and tem2==0)
				return tem;
			return min(tem,tem2);
		}
	}
	if(r<=mid)
		return query(ls,l,r,k);
	else if(l>=mid+1)
		return query(rs,l,r,k);
	else
	{
		ll tem=query(ls,l,mid,k);
		ll tem1=query(rs,mid+1,r,k);
		if(tem==0 and tem1!=0)
			return tem1;
		if(tem!=0 and tem1==0)
			return tem;
		else
			return min(tem,tem1);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		lasans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%lld",&pic[i]);
		build(1,n,1);
		for(int i=1;i<=m;++i)
		{
			int op;
			scanf("%d",&op);
			if(op==1)
			{
				ll t1;
				scanf("%lld",&t1);
				t1^=lasans;
				add(t1,1);
			}
			else
			{
				ll t1,t2;
				scanf("%lld%lld",&t1,&t2);
				t1^=lasans;
				t2^=lasans;//  >=t2
				ll ans=query(1,(int)(t1+1),n,t2);// maybe error
				printf("%lld\n",ans);
				lasans=ans;
			}
		}
	}
	return 0;
}
