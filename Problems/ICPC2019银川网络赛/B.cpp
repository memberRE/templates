#include<bits/stdc++.h>
using namespace std;
int n;
struct ppp{
	int x,y;
}pic[128],Q;
double getdis(ppp a,ppp b )
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
double getcos(ppp a,ppp b)
{
	return (double)(a.x*b.x+a.y*b.y)/(double)(sqrt((double)(a.x*a.x+a.y*a.y))*sqrt((double)(b.x*b.x+b.y*b.y)));
}
int main()
{
	int t,T=0;
	scanf("%d",&t);
	while(1)
	{
		T++;
		double ans=0.0;
		if(T>t)
			break;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&pic[i].x,&pic[i].y);
		pic[n]=pic[0];
		pic[n+1]=pic[1];
		pic[n+2]=pic[2];
		scanf("%d%d",&Q.x,&Q.y);
		for(int i=1;i<=n;i++)
		{
			ppp a,b;
			a.x=pic[i].x-pic[i-1].x;
			a.y=pic[i].y-pic[i-1].y;
			b.x=pic[i+1].x-pic[i].x;
			b.y=pic[i+1].y-pic[i].y;
			double tem=getdis(pic[i],Q);
			double jd=acos(getcos(a,b));
			while(jd<0)
				jd+=acos(-1);
			while(jd>acos(-1))
				jd-=acos(-1);
			ans+=jd*tem;
		}
		printf("Case #%d: %.3lf\n",T,ans);
	}
	return 0;
}
