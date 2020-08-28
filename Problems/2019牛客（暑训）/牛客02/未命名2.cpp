#include<bits/stdc++.h>
using namespace std;
const int MAX=30;
typedef long long ll;
ll pic[MAX][MAX];
ll ans=-1,ans2=-1;
int n,cnt;
void dfs(int k,int dp,int r,ll tem)
{
	
	if(k==0)
	{cnt++; 
//		ll tmp=0;
//		for(int i=1;i<=2*n;i++)
//			for(int j=1;j<i;j++)
//			{
//				if(((dp>>(i-1))&1)!=((dp>>(j-1))&1))
//					tmp+=pic[i][j];
//			}
		//cout<<"zhengque  "<<dp<<' '<<tmp<<endl;
		ans=max(ans,tem);
		//ans2=max(ans2,tmp);
		return ;
	}
	for(int i=r;i<=2*n-1;++i)
		if(k-1<=(2*n-(i+1)))
		{
			ll jkl=tem;
			int ddp=dp;
//			for(int j=0;j<=i;j++)
//			{
//				if((ddp&1)==0)
//					jkl+=pic[i+1][j+1];
//				ddp>>=1;
//			}	
		//	cout<<jkl<<"    "<<(dp|(1<<i))<<endl;
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
	cout<<ans2<<endl;
	cout<<cnt;
	fclose(stdin);
}
