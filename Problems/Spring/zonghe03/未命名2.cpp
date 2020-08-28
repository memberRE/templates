#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAX=3e5+20;
ll pic[MAX],ans;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&pic[i]);
		pic[i]+=pic[i-1];
	}
	ans=pic[n]*k;
	sort(pic+1,pic+n);
	for(int i=1;i<=k-1;i++)
		ans-=pic[i];
	cout<<ans;
	return 0;
}
