#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,d,e;
float l,r,ans;
float f(float x)
{
	return a*sin(x)+b*sin(2*x)+c*sin(3*x)+(x-d)*(x-d)-e;
}
bool cha(float a,float b)
{
		int L=a*1000;
		a=L/1000.0;
		int R=b*1000;
		b=R/1000.0;
		ans=a;
		return a==b;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d%d%d%f%f",&a,&b,&c,&d,&e,&l,&r);
		float ll=l,rr=r;
/*		int L=ll*100;
		ll=L/100.0;
		int R=rr*100;
		rr=R/100.0;*/
		while(!cha(ll,rr))
		{
			float mid=(ll+rr)/2;
			int kk=mid*10000;
			mid=kk/10000.0;
			if(f(mid)==0.0)
			{
			//	ll=rr=mid;
				ans=mid;
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
		int k=ans*1000;
		if(k%10>=5)
		k+=10;
		ans=k/1000.0;
		printf("%.2f\n",ans);
	}
	return 0;
}
