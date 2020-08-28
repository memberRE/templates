#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=2e5+200;
struct ppp{
	int x,y;
}fish[MAX];
struct pppp{
	int x,id,aans;
	bool operator <(const pppp &  a) const
	{
		return x<a.x;
	}
}fman[MAX];
bool cam(pppp a,pppp b)
{
	return a.id<b.id;
}
int n,m,l;
int sum[MAX];
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&fish[i].x,&fish[i].y);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&fman[i].x);
		fman[i].id=i;
	}
	sort(fman+1,fman+1+m);
	for(int i=1;i<=n;i++)
	{
		int tem=l-fish[i].y;
		if(tem<0)	continue;
		pppp tmp;
		tmp.x=fish[i].x-tem;
		int l=lower_bound(fman+1,fman+m+1,tmp)-fman;
		tmp.x=fish[i].x+tem;
		int r=upper_bound(fman+1,fman+m+1,tmp)-fman;
		sum[l]++;
		sum[r]--;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		ans+=sum[i];
		fman[i].aans=ans;
	}
	sort(fman+1,fman+1+m,cam);
	for(int i=1;i<=m;i++)
		printf("%d\n",fman[i].aans);
	return 0;
}
