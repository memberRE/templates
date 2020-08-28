#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long v[100002],pic[100002],lazy=0;
long long fro=1,lat=0;
void charu(long long k)
{
	long long h=lower_bound(pic+fro,pic+lat,k)-pic;
	if(h==lat)
	{
		pic[lat+1]=k;
		if(pic[lat]>pic[lat+1])
			swap(pic[lat],pic[lat+1]);
		return ;
	}
	for(int i=lat;i>=h;i--)
		pic[i+1]=pic[i];
	pic[h]=k;
	return ;
}
int main()
{
	int n;//  ±ÕÇø¼ä 
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++)
	{
		long long t=0,ans=0;
		bool flag=0;
		scanf("%lld",&t);
		if(v[i]-t<0)
		{
			ans+=v[i];
			flag=1;
		}
		long long k=lower_bound(pic+fro,pic+lat,t+lazy)-pic;
		for(int j=fro;j<k;j++)
			ans+=(pic[j]-lazy);
		fro=k;
		if(pic[k]-lazy>=t and lat>=fro)
			ans+=t*(lat-k+1);
		else	if(lat>=fro)
			ans+=(pic[k]-lazy),fro++;
		lazy+=t;
		if(!flag)
		{
			ans+=t;
			charu(v[i]+lazy-t);
			lat++;
		}
		printf("%lld ",ans);
	}
	return 0;
}
