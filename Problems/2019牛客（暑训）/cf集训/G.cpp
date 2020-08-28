#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long double qpower(long double a,int b)
{
	long double ans=1.0;
	while(b)
	{
		if(b&1)
			ans*=a;
		b=b>>1;
		a*=a;
	}
	return ans;
}
double PI=acos(-1);
double xit;
int main()
{
//	freopen("glorious.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,r,k;
		scanf("%lld%lld%lld",&n,&r,&k);
		xit=PI/(double)k;
		double tem=(1.0*k)*tan(xit)-PI;
		//cout<<qpower(1.0/cos(xit),2*n-2)<<endl;
		//long double jkl=(qpower(1.0/cos(xit),2*n-2)-cos(xit)*cos(xit))/(sin(xit)*sin(xit));
		long double jkl=(1-qpower(cos(xit),2*n))/(sin(xit)*sin(xit)*qpower(cos(xit),2*n-2));
		jkl*=(long double)tem;
		cout<<setprecision(5)<<(long double)r*r*jkl<<endl;
	}
//	fclose(stdin);
	return 0;
}
//8832609009784292414.9039930501728
//100000 100 3
