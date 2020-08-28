#include<bits/stdc++.h>
#define FJ (1<<(k-1))
using namespace std;
typedef long long ll;
const int MAX=1e6+20;
struct ppp{
	int x,y;
	int z;
}pic[MAX];
vector<ppp> node[4];
//0 3
//1 2
ppp change(ppp a,int flag,int k)
{
	if(k==1)	return a;
	if(flag==1 or flag==2)
		a.x-=FJ;
	if(flag==2 or flag==3)
		a.y-=FJ;
	if(flag==1 or flag==2)
		return a;
	if(flag==0)
		swap(a.x,a.y);
	else
	{
		int tem=a.y;
		a.y=FJ-a.x+1;
		a.x=FJ-tem+1;
	}
	return a;
}
void dfs(int l,int r,int flag,int k)//[l,r);
{
	if(l>=r)	return ;	
	if(k==0)
		for(int i=l;i<r;++i)
		{
			int tem=node[flag][i].z;
			printf("%d %d\n",pic[tem].x,pic[tem].y);
		}
	else
	{
		int num[4];
		for(int i=0;i<4;++i)
			num[i]=node[i].size();
		for(int i=l;i<r;++i)
		{
			ppp a=node[flag][i];
			if(a.x<=FJ)
			{
				if(a.y<=FJ)
					node[0].push_back(change(a,0,k));
				else
					node[3].push_back(change(a,3,k));
			}
			else if(a.y<=FJ)
				node[1].push_back(change(a,1,k));
			else
				node[2].push_back(change(a,2,k));
		}
		int nnn[4];
		for(int i=0;i<4;i++)
			nnn[i]=node[i].size();
		for(int i=0;i<4;++i)
			dfs(num[i],nnn[i],i,k-1);	
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int num[4]={0,0,0,0};
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&pic[i].x,&pic[i].y);
		pic[i].z=i;
		if(pic[i].x<=FJ)
		{
			if(pic[i].y<=FJ)
			{
				node[0].push_back(change(pic[i],0,k));
				num[0]++;
			}
			else
			{
				node[3].push_back(change(pic[i],3,k));
				num[3]++;
			}
		}
		else if(pic[i].y<=FJ)
		{
			node[1].push_back(change(pic[i],1,k));
			num[1]++;
		}
		else
		{
			node[2].push_back(change(pic[i],2,k));
			num[2]++;
		}
	}
	for(int i=0;i<4;i++)
		dfs(0,num[i],i,k-1);
	return 0;
}

