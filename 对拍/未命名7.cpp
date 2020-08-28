#include<bits/stdc++.h>
#define ls(k) a[k].ch[0]
#define rs(k) a[k].ch[1]
using namespace std;
struct node
{
	int l,r,cnt,ch[2];
};
node a[510000];
int cnt=1;
struct num
{
	int val;
	int loc;
	bool operator < (const num &a) const
	{
		return val<a.val;
	}
};
num lisanhua[51000];
int yingshe[51000];
int n;
void init()
{
	int cnt=0;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>lisanhua[i].val;
		lisanhua[i].loc=i;
	}
	sort(lisanhua+1,lisanhua+n+1);
	lisanhua[0].val=19260817;
	for(int i=1; i<=n; ++i)
	{
		if(lisanhua[i].val!=lisanhua[i-1].val) yingshe[lisanhua[i].loc]=cnt+1,++cnt;
		else yingshe[lisanhua[i].loc]=cnt;
	}
}

void update(int k)
{
	a[k].cnt=a[ls(k)].cnt+a[rs(k)].cnt;
}

void build(int k,int l,int r)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r) return;
	int mid=l+r;
	mid/=2;
	ls(k)=cnt+1,++cnt,build(cnt,l,mid);
	rs(k)=cnt+1,++cnt,build(cnt,mid+1,r);
}

void ins(int k,int val)
{
	if(a[k].l==a[k].r&&a[k].l==val)
	{
		a[k].cnt++;
		return;
	}
	int mid=a[k].l+a[k].r;
	mid/=2;
	if(val<=mid) ins(ls(k),val);
	else ins(rs(k),val);
	update(k);
}

int query(int k,int l,int r)
{
	if(a[k].l==l&&a[k].r==r)
	{
		return a[k].cnt;
	}
	int mid=a[k].l+a[k].r;
	mid/=2;
	if(r<=mid) return query(ls(k),l,r);
	else if(l>mid) return query(rs(k),l,r);
	else return query(ls(k),l,mid)+query(rs(k),mid+1,r);
}
int main()
{
	build(1,0,51000);
	init();
	long long ans=0;
	for(int i=1; i<=n; ++i)
	{
		ins(1,yingshe[i]);
		ans+=query(1,yingshe[i]+1,n+1);
	}
	cout<<ans;
	return 0;
}
