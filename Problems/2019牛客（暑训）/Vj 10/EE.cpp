#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+20;
struct ppp{
	int x,y;
}pic[MAX];
double A[MAX],r1,ans,RR[MAX];
int X[MAX];
double DIS(int i,int j)
{
	return sqrt((pic[i].x-pic[j].x)*(pic[i].x-pic[j].x)+(pic[i].y-pic[j].y)*(pic[i].y-pic[j].y));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		r1=ans=0.0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&pic[i].x,&pic[i].y);
		for(int i=1;i<n;i++)
			X[i]=DIS(i,i+1);
		X[n]=DIS(1,n);
		A[0]=0.0;
		for(int i=1;i<=n;i++)
		{
			if(i&1)
				A[i]=A[i-1]+X[i]*(-1.0);
			else
				A[i]=A[i-1]+X[i];
		}
		//----------------l,r  r1·¶Î§
		double l=0.0,r=min(X[1],X[n]);
		for(int i=2;i<=n;i++)
		{
			double teml=0,temr=min(X[i],X[i-1]);
//			if((i&1)==0)
//				teml=A[i-1],temr=A[i-1]+min(X[i],X[i-1]);
//			else
//				teml=-A[i-1],temr=-A[i-1]+min(X[i],X[i-1]);
//			if((i&1)==0)
//			{
//				teml*=-1;
//				temr*=-1;
//				swap(teml,temr);
//			}
			if((i&1)==0)
			{
				teml*=-1;
				temr*=-1;
				swap(teml,temr);
			}
			teml-=A[i-1];temr-=A[i-1];
			l=max(l,teml);
			r=min(r,temr);
		}
		if(l>r)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(n&1)
		{
			r1=(X[n]-A[n-1])/2.0;
			if(r1>r or r1<l)
			{
				printf("IMPOSSIBLE\n");
				continue;
			}
			for(int i=1;i<=n;i++)
			{
//				double jkl=A[i-1]*(-1.0);
//				if(i&1)
//				{
//					jkl*=-1.0;
//					jkl+=r1;
//				}
//				else
//					jkl+=r1*(-1.0);
				double jkl=A[i-1]+r1;
				if(jkl<0)
					jkl*=-1.0;
				if(fabs(jkl)<1e-6)
					jkl=0.0;
				RR[i]=jkl;
				ans+=RR[i]*RR[i]*acos(-1);
			}
			printf("%.2lf\n",ans);
			for(int i=1;i<=n;i++)
				printf("%.2lf\n",RR[i]);
			continue;
		}
		else if(fabs(A[n-1]+X[n])>1e-5)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		//------------------- 
		double B=0.0,C=0.0;
		for(int i=1;i<n;i++)
		{
			B+=A[i];
			C+=A[i]*A[i];
		}
		double jkl=B/((double)n*(-1.0));
		if(jkl-l>=1e-6 and jkl-r<=1e-6)
			r1=jkl;
		else
		{
			if(jkl<l)
				r1=l;
			else
				r1=r;
		}
		for(int i=1;i<=n;i++)
		{
//			double jkl=A[i-1]*(-1.0);
//			if(i&1)
//			{
//				jkl*=-1.0;
//				jkl+=r1;
//			}
//			else
//				jkl+=r1*(-1.0);
			double jkl=A[i-1]+r1;
			if(jkl<0)
				jkl*=-1.0;
			if(fabs(jkl)<1e-6)
				jkl=0.0;
			RR[i]=jkl;
			ans+=RR[i]*RR[i]*acos(-1);
		}
		printf("%.2lf\n",ans);
		for(int i=1;i<=n;i++)
			printf("%.2lf\n",RR[i]);
	}
	return 0;
}
