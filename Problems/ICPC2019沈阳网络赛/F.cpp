#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+200;
int pic[MAX]; 
int n,k;
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&pic[i]);
		pic[0]=pic[n+1]=-1;
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		sort(pic+1,pic+1+n);
		int maxx=n,mmin=1;
		while(pic[maxx]==pic[maxx-1])
			maxx--;
		while(pic[mmin]==pic[mmin+1])
			mmin++;
		int minus=(pic[maxx]-pic[maxx-1])*(n-maxx+1);
		int plus=( pic[mmin+1]-pic[mmin])*(mmin);
		while(k>0)
		{
			
			while(pic[maxx]==pic[maxx-1])
				maxx--;
			while(pic[mmin]==pic[mmin+1])
				mmin++;
			if(mmin+1==maxx)
			{
				if(plus==0 and minus==0)
					minus=(pic[maxx]-pic[maxx-1])*(n-maxx+1);
				if(plus!=0 and minus!=0)
					plus=0;
				if(minus==0)
				{
					if(plus<=mmin)
					{
						pic[maxx]=pic[mmin]+1;
						k=0;
						break;
					}
					else
					{
						int h=plus/mmin;
						minus=h*mmin;
						k-=plus-h*mmin;
						plus=0;
						if(k<0)
						{
							pic[mmin]=pic[maxx]-h-1;
							break;
						}
					}
				}
				if(plus==0)
				{
					int h=minus/n;
					if(h*mmin>k)
					{
						int tem=k/mmin;
						pic[mmin]+=tem;
						minus-=tem*mmin;
						int tem2=minus/(n-maxx+1);
						if(tem2*(n-maxx+1)!=minus)
							pic[maxx]++;
						pic[maxx]+=tem2;
						k=0;
						break;
					}
					else if(h*mmin<=k)
					{
						if(h*n==minus)
						{
							k=1;
							break;
						}
						else
						{
							pic[maxx]=pic[mmin]+1;
							k=0;
							break;
						}
					}
				}
					
			}
			if(plus==0)
				plus=( pic[mmin+1]-pic[mmin])*(mmin);
			if(minus==0)
				minus=(pic[maxx]-pic[maxx-1])*(n-maxx+1);
			if(mmin>=maxx)
				break;
			
			if(minus>plus)
			{
				minus-=plus;
				plus=0;
				k-=plus;
				if(k<0)
					break;
				if(k==0)
				{
					mmin++;
					break;
				}
				pic[mmin]=pic[mmin+1];
				mmin++;
			}
			else if(minus<plus)
			{
				plus-=minus;
				minus=0;
				k-=minus;
				if(k<0)
					break;
				if(k==0)
				{
					maxx++;
					break;
				}
				pic[maxx]=pic[maxx-1];
				maxx--;
			}
			else
			{
				minus-=plus;
				plus=0;
				k-=plus;
				if(k<0)
					break;
				if(k==0)
				{
					mmin++;
					maxx--;
					break;
				}
				pic[mmin]=pic[mmin+1];
				pic[maxx]=pic[maxx-1];
				mmin++;
				maxx--;
			}
		}
		if(k)
		{
			printf("0\n");
			continue;
		}
		else
			printf("%d\n",pic[maxx]-pic[mmin]);
	}
	return 0;
}
