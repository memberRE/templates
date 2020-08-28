#include<bits/stdc++.h>
const int MAX=2e3+20;
using namespace std;
int pic[MAX][MAX],sum[MAX][MAX];
int a[MAX],dp[MAX];
map<int,int> MAP,tem;
int n;
bool check(int len)
{
	for(int i=1;i+len-1<=n;i++)
	{
		int l=i,r=i+len-1;
		int ans=sum[n][l-1]-sum[r][l-1]+sum[l-1][l-1]+sum[n][n]-sum[n][r]-sum[r][n]+sum[l-1][n]+sum[r][r]-sum[l-1][r];
		if(ans==0)
			return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		if(MAP.count(a[i])==0)
			MAP[a[i]]=i;
		else
		{
			pic[i][MAP[a[i]]]=1;
			MAP[a[i]]=i;
		}
	MAP.clear();
	for(int i=1;i<=n;i++)
		if(MAP.count(a[i])==0)
			MAP[a[i]]=i;
	for(int i=n;i>=1;i--)
		if(tem.count(a[i])==0)
			tem[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int qq=MAP[a[i]],ww=tem[a[i]];
		if(qq!=ww)
			pic[ww][qq]=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			sum[i][j]=pic[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	int l=0,r=n;//r一定可以，l不一定 
	check(3);
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<r;
	return 0;
}
