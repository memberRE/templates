#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,d,e;
double l,r;
double f(double x)
{
	return a*sin(x)+b*sin(2*x)+c*sin(3*x)+(x-d)*(x-d)-e;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d%d%d%llf%llf",&a,&b,&c,&d,&e,&l,&r);
		double ll=l,rr=r;
		int L=ll*100;
		ll=L/100.0;
		int R=rr*100;
		rr=R/100.0;
		double LL=ll,RR=rr;
		while(-ll*100+rr*100!=1)
		{
/*			if(rr*100-ll*100==1)
			{
				double mid=(ll+rr)/2.0;
				if(f(mid)*f(ll)<=0)
				{
					rr=ll;
					break;
				}
				else
					break;
			}*/
			double mid=(ll+rr)/2;
			int kk=mid*100;
			mid=kk/100.0;
			if(f(mid)==0.0)
			{
				ll=rr=mid;
				break;
			}
			if(f(mid)*f(rr)<=0)
			{
				ll=mid;
				continue;
			}
			else
			{
				rr=mid;
				continue;
			}
		}
		printf("%.2llf\n",rr);
	}
	return 0;
}
