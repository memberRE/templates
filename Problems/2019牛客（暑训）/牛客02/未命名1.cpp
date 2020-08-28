#include<bits/stdc++.h>
using namespace std;
const int MAX=30;
typedef long long ll;
ll pic[MAX][MAX];
int xunz0[50],tot0;
int xunz1[50],tot1; 
ll ans=-1;
int n,cnt;
void dfs(int k,int dp,int r,ll tem)
{
	if(k==0)
	{
		ans=max(ans,tem);
		return ;
	}
	ll zhixuan0=tem;
	for(int i=r;i<=2*n-1;++i)
		if(k-1<=(2*n-(i+1)))
		{
			ll jkl=zhixuan0;
			if(i!=r)
				xunz0[tot0++]=i-1;
			int noww=tot0;
			for(int j=0;j<tot0;++j)
				jkl+=pic[i+1][xunz0[j]+1];
			for(int j=0;j<tot0;++j)
				jkl+=pic[i+1][xunz0[j]+1];
			dfs(k-1,dp|(1<<i),i+1,jkl);
			tot0=noww;
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
//	fclose(stdin);
}
