#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=2147487;
ll pic[40],expic[40],s,exs;
vector<ll> dp[MOD+3];
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>pic[i];
		expic[i]=pic[i]%MOD;
	}
	exs=s%MOD;
	dp[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<MOD;j++)
		{
			ll tem=1;
			tem<<=(i-1);
			ll tmp=(j-expic[i]+MOD)%MOD;
			int U=dp[tmp].size();
			if(U>1000)
				cout<<i<<' '<<j<<' '<<U<<endl;
			for(int k=0;k<U;k++)
			{
				if((dp[tmp][k]>>(i-1))&1)
					continue;
				else
				dp[j].push_back(dp[tmp][k]|tem);
			}
		}
	}
	for(int i=0;i<dp[exs].size();i++)
	{
		ll tem=0;
		int j=1;
		ll jkl=dp[exs][i];
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
				cout<<(dp[exs][i]&1);
				dp[exs][i]>>=1;
			}
			break;
		}
	}
	return 0;
}
