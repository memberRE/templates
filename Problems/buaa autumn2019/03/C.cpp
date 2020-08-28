#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
using namespace std;
long long n,m,x,d,ans;
int main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&d);
		if(d>=0)
			ans+=n*x+d*(n-1)*n/2;
		else
			ans+=n*x+d*(n-(n+1)/2)*((n+1)>>1ll);
	}
	printf("%lf\n",(double)1.0*ans/n);
	return 0;
}
