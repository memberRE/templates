#include<iostream>
#include<cstdio>
using namespace std;
long long a[100001];
long long mmax=0,n,m;
inline bool f(long long x)
{
	if(x<mmax) return false;
	long long ct=1,cn=0,i;
	for(i=1;i<=n;++i)
		if((cn+=a[i])>x)
		{
			cn=a[i];
			++ct;
		}
	return ct<=m;
}
int main()
{
	long long l,r=1e14,mid;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]>=mmax) mmax=a[i];
	}
	while(l<=r)
	{
		if(f(mid=l+r>>1)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}

