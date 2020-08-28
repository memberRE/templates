#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAX=3e5+20;
int tree[MAX<<2],pic[MAX];
int RR[MAX],pos[MAX],n,ans;
void build(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=pic[l];
		return;
	}
	int mid=(l+r)>>1;
	build(node<<1,l,mid);
	build((node<<1)|1,mid+1,r);
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}
int qurry(int node,int l,int r,int L,int R)
{
	if(l<=L and R<=r) return tree[node];
	int mid=(L+R)>>1;
	int maxx=0;
	if(l<=mid)
		maxx=max(maxx,qurry(node<<1,l,r,L,mid));
	if(r>mid)
		maxx=max(maxx,qurry((node<<1)|1,l,r,mid+1,R));
	return maxx;
}
int main()
{
	scanf("%d",&n);
	memset(pos,0x3f,sizeof(pos));
	for(int i=1;i<=n;i++)
		scanf("%d",&pic[i]);
	build(1,1,n);
	RR[n+1]=n+1;
	for(int i=n;i>=1;i--)
	{
		RR[i]=min(pos[pic[i]],RR[i+1]);
		pos[pic[i]]=i;
		for(int j=i;j<RR[i];j++)
		{
			int x=qurry(1,i,j,1,n);
			if(x>j-i+1)
				j=i+x-2;
			else ans++;
		}
	}
	cout<<ans;
	return 0;
}
