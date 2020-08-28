#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
struct ppp{
	int v,to,next;
}pic[500007];
int head[100005],num=0,m,n;
long long d[100005];
bool vztd[100005];
void add(int x,int y,int z)
{
	num++;
	pic[num].v=z;
	pic[num].to=y;
	pic[num].next=head[x];
	head[x]=num;
}
void djstla(int s)
{
	for(int i=1;i<=n;i++)
		d[i]=2147483647;
	memset(vztd,0,sizeof(vztd));
	d[s]=0;
	for(int i=1;i<=n;i++)
	{
		int start=-1;
		for(int j=1;j<=n;j++)
			if(vztd[j]==0  and (d[start]>d[j] or start==-1))
				start=j;
		vztd[start]=1;
		for(int j=head[start];j;j=pic[j].next)
			d[pic[j].to]=min(d[pic[j].to],d[start]+pic[j].v);
	}
}
int main()
{
	int s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	djstla(s);
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
	return 0;
}
