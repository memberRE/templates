#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=2e5+2;
typedef long long ll;
struct ppp{
	ll sum,mmin;
}tree[MAX<<2];
int n,q;
ll pic[MAX],ansmin;
inline void update(int node)
{
	tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
	ll mmin1=tree[node<<1].mmin,mmin2=tree[(node<<1)|1].mmin;
	if(mmin1==0)
		tree[node].mmin=mmin2;
	else if(mmin2==0)
		tree[node].mmin=mmin1;
	else
		tree[node].mmin=min(tree[node<<1].mmin,tree[(node<<1)|1].mmin);
}
void build(int l,int r,int node)
{
	if(l==r)
	{
		tree[node].mmin=pic[l];
		tree[node].sum=pic[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
//	tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
//	tree[node].mmin=min(tree[node<<1].mmin,tree[(node<<1)|1].mmin);
	update(node);
}
ll asksum(int l,int r,int node,int L,int R)
{
	if(l==L and r==R)
		return tree[node].sum;
	int mid=(L+R)>>1;
	if(r<=mid)
		return asksum(l,r,node<<1,L,mid);
	if(l>=mid+1)
		return asksum(l,r,(node<<1)|1,mid+1,R);
	return asksum(l,mid,node<<1,L,mid)+asksum(mid+1,r,(node<<1)|1,mid+1,R);
}
ll askmin(int l,int r,int node,int L,int R)
{
	if(l==L and r==R)
		return tree[node].mmin;
	int mid=(L+R)>>1;
	if(r<=mid)
		return askmin(l,r,node<<1,L,mid);
	if(l>=mid+1)
		return askmin(l,r,(node<<1)|1,mid+1,R);
	ll tem1= askmin(l,mid,node<<1,L,mid);
	ll tem2= askmin(mid+1,r,(node<<1)|1,mid+1,R);
	if(tem1==0)	return tem2;
	if(tem2==0)	return tem1;
	return min(tem2,tem1);
}
ll work(int l,int r,int node,int L,int R,ll mod)
{
	if(l==r and L==R)
	{
		tree[node].sum%=mod;
		tree[node].mmin%=mod;
		return tree[node].sum;
	}
	if(l==L and R==r)
	{
		if(tree[node].sum==0)
			return 0;
		int mid=(l+r)>>1;
		work(l,mid,node<<1,L,mid,mod);
		work(mid+1,r,(node<<1)|1,mid+1,R,mod);
		update(node); 
		return tree[node].sum;
	}
	int mid=(L+R)>>1;
	if(r<=mid)
	{
		ll jkl= work(l,r,node<<1,L,mid,mod);
		update(node);
		return jkl;
	}	
	if(l>=mid+1)
	{
		ll jkl= work(l,r,(node<<1)|1,mid+1,R,mod);
		update(node);
		return jkl;
	}
	
	ll jkl= work(l,mid,node<<1,L,mid,mod)+work(mid+1,r,(node<<1)|1,mid+1,R,mod);
	update(node);
	return jkl;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
			scanf("%lld",&pic[i]);
		build(1,n,1);
		for(int i=1;i<=q;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			ll presum=asksum(l,r,1,1,n);//注意最小值非0！！！！ 
			ll ansmin=askmin(l,r,1,1,n);
			ll lassum;
			if(ansmin!=0)
				lassum=work(l,r,1,1,n,ansmin);
			else
				lassum=presum;
			printf("%lld %lld\n",presum,lassum);
		}
	}
	return 0;
}
