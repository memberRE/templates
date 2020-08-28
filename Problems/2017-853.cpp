#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long m,h,q,n,g=10;
		scanf("%lld%lld%lld%lld",&m,&h,&q,&n);
		long long x=(m*g*h)/(n*q);
		if(x*n*q<m*g*h)
			x++;
		if(x%9==0)
			x++;
		printf("%lld\n",x);
	}
	return 0;
}
