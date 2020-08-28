#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+20;
struct ppp{
	int fz,fm;
}pic[MAX],ans[MAX];
int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}
int n,m;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&pic[i].fz);
			pic[i].fm=m;
			ans[i]=pic[i];
		}
		int mmin=99999999;
		for(int i=1;i<=n;i++)
			mmin=min(mmin,ans[i].fz);
		if(mmin<0)
			for(int i=1;i<=n;i++)
				ans[i].fz+=mmin;
		while(1)
		{
			int sum=0,cnt=0;
			mmin=0x7fffffff;
			for(int i=1;i<=n;i++)
				if(ans[i].fz!=0)
				{
					mmin=min(mmin,ans[i].fz);
					sum+=ans[i].fz;
					cnt++;
				}
			if(sum==m)
				break;
			if(sum<m)
			{
				int k=m-sum;
				for(int i=1;i<=n;i++)
					ans[i].fz=ans[i].fz*n+k,ans[i].fm*=n;
				break; 
			}
			if(sum>m and cnt==1)
			{
				for(int i=1;i<=n;i++)
					if(ans[i].fz!=0)
						ans[i].fz=ans[i].fm;
				break;
			}
			int temcnt=0,maxx=-1,temsum=0;
			for(int i=1;i<=n;i++)
				if(ans[i].fz-mmin>0)
					temcnt++,maxx=max(maxx,ans[i].fz-mmin),temsum+=ans[i].fz-mmin;
			if(temcnt>1)
			{
				if(temsum>=m)
				{
					for(int i=1;i<=n;i++)
						if(ans[i].fz-mmin>=0)
							ans[i].fz-=mmin;
				}
				else 
				{
					int jkl=m-temsum;
					for(int i=1;i<=n;i++)
						if(ans[i].fz!=0)
						{
							ans[i].fz=(ans[i].fz-mmin)*cnt+jkl;
							ans[i].fm=m*cnt;
						}
					break;
				}
				continue;
			}
			if(temcnt==1)
			{
				if(maxx>=m)
				{
					for(int i=1;i<=n;i++)
						if(ans[i].fz-mmin>=0)
							ans[i].fz-=mmin;
					continue;
				}
				else
				{
					int jklfz=m-maxx;
					for(int i=1;i<=n;i++)
						if(ans[i].fz>0)
						{
							if(ans[i].fz==mmin)
								ans[i].fz=jklfz,ans[i].fm=m*cnt;
							else
								ans[i].fz=(ans[i].fz-mmin)*cnt+jklfz,ans[i].fm=m*cnt;
						}
					break;
				}
			}
			if(temcnt==0)
			{
				for(int i=1;i<=n;i++)
					if(ans[i].fz!=0)
						ans[i].fz=1,ans[i].fm=cnt;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
		//	if(pic[i].fz==0)	continue;
			if(ans[i].fm==m)
				ans[i].fz-=pic[i].fz;
			else
			{
				ans[i].fz=ans[i].fz*m-pic[i].fz*ans[i].fm;
				ans[i].fm*=m;
				if(ans[i].fz!=0)
				{
					int jjk=gcd(ans[i].fz,ans[i].fm);
					ans[i].fz/=jjk;
					ans[i].fm/=jjk;
				}
			}
			ans[i].fz*=ans[i].fz;
			ans[i].fm*=ans[i].fm;
			if(ans[i].fz!=0)
			{
				int jjk=gcd(ans[i].fz,ans[i].fm);
				ans[i].fz/=jjk;
				ans[i].fm/=jjk;
			}
		}
		int fz=ans[1].fz,fm=ans[1].fm;
		for(int i=2;i<=n;i++)
		{
		//	if(ans[i].fz==0)	continue;
			if(fm!=ans[i].fm)
			{
				fz=fz*ans[i].fm+ans[i].fz*fm;
				fm*=ans[i].fm;
				if(fz==0)	continue;
				int jkl=gcd(fm,fz);
				fm/=jkl;
				fz/=jkl;
			}
			else
				fz+=ans[i].fz;
		}
		if(fz!=0)
		{
			int jkl=gcd(fm,fz);
			fm/=jkl;
			fz/=jkl;
		}
		if(fm==1 or fz==0)
			printf("%d\n",fz);
		else
			printf("%d/%d\n",fz,fm);
	}
	return 0;
}
/*
5 7
2 3 4 1 0
*/
