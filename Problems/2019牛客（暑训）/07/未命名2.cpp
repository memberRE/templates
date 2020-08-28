#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
struct node
{
	int l,r;
	ll num;
	int tag;
} tree[maxn<<3];
int bb[maxn*2],X[maxn],Y[maxn],L[maxn],R[maxn];
void build(int root,int l,int r)
{
	tree[root].l=l;
	tree[root].r=r;
	tree[root].num=0;
	tree[root].tag=0;
	if (l+1==r) return ;
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid,r);
}
void pushdown(int root)
{
	if (tree[root].tag==0) return ;
	if (tree[root].l+1==tree[root].r) return ;
	tree[root<<1].tag+=tree[root].tag;
	tree[root<<1].num+=1ll*tree[root].tag*(bb[tree[root<<1].r]-bb[tree[root<<1].l]);
	tree[root<<1|1].tag+=tree[root].tag;
	tree[root<<1|1].num+=1ll*tree[root].tag*(bb[tree[root<<1|1].r]-bb[tree[root<<1|1].l]);
	tree[root].tag=0;
}
void pushup(int root)
{
	if (tree[root].l+1==tree[root].r) return ;
	tree[root].num=tree[root<<1].num+tree[root<<1|1].num;
}
void update(int root,int xx,int yy)
{
	if (xx==tree[root].l && tree[root].r==yy)
	{
		tree[root].num+=bb[yy]-bb[xx];
		tree[root].tag++;
		return ;
	}
	pushdown(root);
	int mid=(tree[root].l+tree[root].r)>>1;
	if (yy<=mid) update(root<<1,xx,yy);
	else if (xx>=mid) update(root<<1|1,xx,yy);
	else
	{
		update(root<<1,xx,mid);
		update(root<<1|1,mid,yy);
	}
	pushup(root);
}
ll query(int root,ll res)
{
	if (tree[root].l+1==tree[root].r)
	{
		ll tmp=tree[root].num/(bb[tree[root].r]-bb[tree[root].l]);
		return bb[tree[root].l]+(res-1)/tmp;
	}
	pushdown(root);
	if (res<=tree[root<<1].num) return query(root<<1,res);
	else return query(root<<1|1,res-tree[root<<1].num);
}
int main()
{
	int n;
	scanf("%d",&n);
	int A1,A2,B1,B2,C1,C2,M1,M2;
	scanf("%d%d%d%d%d%d",&X[1],&X[2],&A1,&B1,&C1,&M1);
	scanf("%d%d%d%d%d%d",&Y[1],&Y[2],&A2,&B2,&C2,&M2);
	for (int i=3; i<=n; i++) X[i]=(1ll*A1*X[i-1]+1ll*B1*X[i-2]+C1)%M1;
	for (int i=3; i<=n; i++) Y[i]=(1ll*A2*Y[i-1]+1ll*B2*Y[i-2]+C2)%M2;
	int tot=0;
	for (int i=1; i<=n; i++)
	{
		L[i]=min(X[i],Y[i])+1,R[i]=max(X[i],Y[i])+1;
		R[i]++;
		bb[++tot]=L[i];
		bb[++tot]=R[i];
	}
	sort(bb+1,bb+1+tot);
	int totn=unique(bb+1,bb+1+tot)-(bb+1);
	for (int i=1; i<=n; i++)
	{
		L[i]=lower_bound(bb+1,bb+1+totn,L[i])-bb;
		R[i]=lower_bound(bb+1,bb+1+totn,R[i])-bb;
	}
	build(1,1,totn);
	ll sum=0;
	for (int i=1; i<=n; i++)
	{
		update(1,L[i],R[i]);  //l--r+1
		sum+=(bb[R[i]]-bb[L[i]]);// len=r-l+1
		ll res=(sum+1)/2;
		ll ans=query(1,res);
		printf("%lld\n",ans);
	}
	return 0;
}
