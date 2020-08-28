#include<bits/stdc++.h>
using namespace std;
struct ppp{
	int x,y,fx,fy;
}pic1[15],pic2[15];
int pri1,pir0;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&pic1[i].x,&pic1[i].y);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&pic2[i].x,&pic2[i].y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(pic1[i].x==pic2[j].x or pic1[i].x==pic2[j].y)
				if(pic1[i].y!=pic2[j].x and pic1[i].y!=pic2[j].y)
				{
					pic1[i].fx=1;
					if(pic2[j].x==pic1[i].x)
						pic2[j].fx=1;
					else
						pic2[j].fy=1;
				}
					
		}
		for(int j=1;j<=m;j++)
		{
			if(pic1[i].y==pic2[j].x or pic1[i].y==pic2[j].y)
				if(pic1[i].x!=pic2[j].x and pic1[i].x!=pic2[j].y)
				{
					pic1[i].fy=1;
					if(pic2[j].x==pic1[i].y)
						pic2[j].fx=1;
					else
						pic2[j].fy=1;
				}
					
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(pic1[i].fx==1 and pic1[i].fy==1)
		{
			cout<<-1;
			return 0;
		}
		if(pic1[i].fx==1)
		{
			if(ans==0 or ans==pic1[i].x)
				ans=pic1[i].x;
			else
				ans=-1;
		}
		if(pic1[i].fy==1)
		{
			if(ans==0 or ans==pic1[i].y)
				ans=pic1[i].y;
			else
				ans=-1;
		}
	}
	if(ans>0)
	{
		cout<<ans;
		return 0;
	}
	
	ans=0;
	for(int i=1;i<=m;i++)
	{
		if(pic2[i].fx==1 and pic2[i].fy==1)
		{
			cout<<-1;
			return 0;
		}
		if(pic2[i].fx==1)
		{
			if(ans==0 or ans==pic2[i].x)
				ans=pic2[i].x;
			else
				ans=-1;
		}
		if(pic2[i].fy==1)
		{
			if(ans==0 or ans==pic2[i].y)
				ans=pic2[i].y;
			else
				ans=-1;
		}
	}
	if(ans>0)
	{
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
