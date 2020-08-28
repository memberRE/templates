#include<bits/stdc++.h>
using namespace std;
#define M 524288
#define N 300005

int ans,aim,n,a[N],t[M<<1],vis[N];

void find(int k,int l,int r)
{
	if (l==r){ans=l;return;}
	int mid=l+r>>1;
	if (t[k<<1]<aim) return find(k<<1,l,mid);
	find(k<<1|1,mid+1,r);
}

void ins(int k,int l,int r)
{
	if (l==r){t[k]=aim;return;}
	int mid=l+r>>1;
	if (ans<=mid) ins(k<<1,l,mid);
	else ins(k<<1|1,mid+1,r);
	t[k]=min(t[k<<1],t[k<<1|1]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1,c;i<=n;i++)
	{
		scanf("%d",&c);
		for (int k;c--;)
		{
			scanf("%d",&k);
			if (!vis[k]) vis[k]=i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i]) ans=1;
		else aim=vis[i]+1,find(1,1,M);
		a[i]=ans;aim=i;
		ins(1,1,M);
	}
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
}