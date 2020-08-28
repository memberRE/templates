#include<bits/stdc++.h>
using namespace std;
const int MAX=30;
typedef long long ll;
ll pic[MAX][MAX];

ll ans=-1;
int n,cnt;
void dfs(int k,int dp,int r,ll tem)
{
	cnt++;
	if(k==0)
	{
//		ll tem=0;
//		for(int i=1;i<=2*n;i++)
//			for(int j=i+1;j<=2*n;j++)
//			{
//				if(((dp>>(i-1))&1)!=((dp>>(j-1))&1))
//					tem+=pic[i][j];
//			}
		ans=max(ans,tem);
		return ;
	}
	for(int i=r;i<=2*n-1;++i)
		if(k-1<=(2*n-(i+1)))
		{
			ll jkl=tem;
			for(int j=0;j<i;++j)
				if(((dp>>j)&1)==0)
					jkl+=pic[i+1][j+1];
			dfs(k-1,dp|(1<<i),i+1,jkl);
		}
			
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
			scanf("%lld",&pic[i][j]);
	dfs(n,0,0,0);
	//选出 n个1，当前情况为0，从0位到后
	cout<<ans<<endl; 
//	cout<<cnt;
	fclose(stdin);
}
