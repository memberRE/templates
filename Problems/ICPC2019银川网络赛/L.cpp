#include<bits/stdc++.h>
#define ls (node<<1)
#define rs ((node<<1)|1)
using namespace std;
typedef long long ll;
const int MAX=1e5+20;
struct ppp{
	int loca,val;
};
struct TREE{
	int mmin,laz,sum;
}tree[MAX<<2];
map<int,int> pos;
int n,topmax,topmin;
ll ans;
ppp stkmax[MAX],stkmin[MAX];
void down(int node,int l,int r)
{
	if(l==r)	return ;
	int jkl=tree[node].laz;
	tree[ls].laz+=jkl;
	tree[rs].laz+=jkl;
	tree[ls].mmin+=jkl;
	tree[rs].mmin+=jkl;
	tree[node].laz=0;
}
void up(int node, int l,int r)
{
//	if(l==r)
//		return ;
	tree[node].mmin=min(tree[ls].mmin,tree[rs].mmin);
	if(tree[ls].mmin==tree[rs].mmin)
		tree[node].sum=tree[ls].sum+tree[rs].sum;
	else	tree[node].sum=tree[node].mmin==tree[ls].mmin?tree[ls].sum:tree[rs].sum;
}
void Insert(int node,int L,int R,int p)
{
	if(L==R)
		tree[node].mmin=-1,tree[node].sum=1,tree[node].laz=0;
	else
	{
		if(tree[node].laz)
			down(node,L,R);
		int mid=(L+R)>>1;
		if(p<=mid)
			Insert(ls,L,mid,p);
		else
			Insert(rs,mid+1,R,p);
		up(node,L,R);
	}
}
void add(int node,int L,int R,int l,int r,int k)
{
	if(L==l and R==r)
	{
		tree[node].laz+=k;
		tree[node].mmin+=k;
		//if(L==R and tree[node].mmin==-1)	tree[node].sum=1;
	}
	else
	{
		if(tree[node].laz)
			down(node,L,R);
		int mid=(L+R)>>1;
		if(r<=mid)
			add(ls,L,mid,l,r,k);
		else if(l>=mid+1)
			add(rs,mid+1,R,l,r,k);
		else
			add(ls,L,mid,l,mid,k),add(rs,mid+1,R,mid+1,r,k);
		up(node,L,R);
	}
	
}
void build(int node,int l,int r)
{
	tree[node].mmin=999999999;
	tree[node].sum=tree[node].laz=0;
	int mid=(l+r)>>1;
	if(l==r)	return ;
	else
		build(ls,l,mid),build(rs,mid+1,r);
}
int main()
{
	int t,QWE=0;
	scanf("%d",&t);
//	stkmax[1].val=1000700000;
//	stkmin[1].val=-1;
	while(t--)
	{
		topmax=topmin=0;
		ans=0;
		//memset(tree,0,sizeof(tree));
		pos.clear();
		scanf("%d",&n);
		build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			ppp a;
			scanf("%d",&a.val);
			a.loca=i;
			Insert(1,1,n,i);
			while(topmax)
			{
				if(stkmax[topmax].val<=a.val)
				{
					topmax--;
					add(1,1,n,stkmax[topmax].loca+1,stkmax[topmax+1].loca,a.val-stkmax[topmax+1].val);
				}
				else
					break;
			}
			stkmax[++topmax]=a;
			while(topmin)
			{
				if(stkmin[topmin].val>=a.val)
				{
					topmin--;
					add(1,1,n,stkmin[topmin].loca+1,stkmin[topmin+1].loca,-a.val+stkmin[topmin+1].val);
				}
				else
					break;
			}
			stkmin[++topmin]=a;
			int tem=1;
			if(pos.count(a.val))
				tem=pos[a.val]+1;
			if(tem<=i-1)	
				add(1,1,n,tem,i-1,-1);
			pos[a.val]=i;
			ans+=tree[1].sum;
		}
		QWE++;
		printf("Case #%d: %lld\n",QWE,ans);
	}
	return 0;
}
