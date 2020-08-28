#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+2;
int pic[MAX],n,a[MAX],t[MAX];
struct ppp{
	int l,r,sum;
}tree[MAX*4];
void discrete()
{
	sort(t+1,t+n+1);
	int cnt=unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(t+1,t+cnt+1,pic[i])-t;
}
void build_tree(int l,int r,int node)
{
	tree[node].l=l;
	tree[node].r=r;
	if(l==r)	return ;
	int mid=(l+r)>>1;
	build_tree(l,mid,node<<1);
	build_tree(mid+1,r,(node<<1)|1);
}
int findans(int l,int r,int node)
{
	if(l>r)	return 0;
	if(tree[node].l==l and tree[node].r==r)
		return tree[node].sum;
	int mid=tree[node<<1].r;
	if(l>mid)
		return findans(l,r,(node<<1)|1);
	if(r<=mid)
		return findans(l,r,node<<1);
	else
		return findans(l,mid,node<<1)+findans(mid+1,r,(node<<1)|1);
}
void add(int k)
{
	for(int i=1;;)
	{
		if(tree[i].l==tree[i].r)
		{
			tree[i].sum=1;
			break;
		}
		tree[i].sum++;
		int mid=tree[i<<1].r;
		if(k<=mid)
			i=i<<1;
		else
			i=(i<<1)|1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pic[i]);
		t[i]=pic[i];
	}
	discrete();
	build_tree(1,n,1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=findans(a[i]+1,n,1);
		add(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
