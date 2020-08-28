#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000007;
ll pic[40],expic[40],s,exs;
vector<ll> dp[37][MOD+3];
int main()
{
	int n;
	cin>>n;cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>pic[i];
		expic[i]=pic[i]%MOD;
	}
	exs=s%MOD;
	dp[0][0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<MOD;j++)
		{
			ll tem=1;
			tem<<=(i-1);
			int Y=dp[i-1][j].size();
//			for(int k=0;k<Y;k++)
//				dp[i][j].push_back(dp[i-1][j][k]);
			ll tmp=(j-expic[i]+MOD)%MOD;
			int U=dp[i-1][tmp].size();
			for(int k=0;k<U;k++)
				dp[i][j].push_back(dp[i-1][tmp][k]|tem);
//			if(Y*U>10000)
//				cout<<Y<<' '<<U<<endl;
		}
	}
	for(int i=0;i<dp[n][exs].size();i++)
	{
		ll tem=0;
		int j=1;
		ll jkl=dp[n][exs][i];
		while(jkl)
		{
			tem+=pic[j]*(jkl&1);
			j++;
			jkl>>=1;
		}
		if(tem==s)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<(dp[n][exs][i]&1);
				dp[n][exs][i]>>=1;
			}
			break;
		}
	}
	return 0;
}
