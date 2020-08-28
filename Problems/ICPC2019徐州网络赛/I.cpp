#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int MAX=1e5+20;
const int MAXM=3e6+20;
struct ppp{
	int x,y,flag,qur;
}pic[MAXM];
int loca[MAX],A[MAX],ans[MAX];
int tree[MAX];
int tot,n,m;
bool cam(ppp a,ppp b)
{
	if(a.y==b.y)
	{
		if(a.x!=b.x)
			return a.x<b.x;
		else
			return a.flag==0;
	}
	return a.y<b.y;
}
void add(int x,int k)
{
	while(x<=tot)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ANS=0;
	while(x!=0)
	{
		ANS+=tree[x];
		x-=lowbit(x);
	}
	return ANS;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
		loca[A[i]]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i*2;j<=n;j+=i)
		{
			tot++;
			pic[tot].x=loca[i];
			pic[tot].y=loca[j];
			pic[tot].flag=0;
		}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r); 
		pic[++tot]=(ppp){r,r,1,i};
		pic[++tot]=(ppp){l-1,l-1,1,i};
		pic[++tot]=(ppp){l-1,r,-1,i};
		pic[++tot]=(ppp){r,l-1,-1,i};
	}
	sort(pic+1,pic+1+tot,cam);
	for(int i=1;i<=tot;++i)
	{
		if(pic[i].flag==0)
			add(pic[i].x,1);
		else
			ans[pic[i].qur]+=pic[i].flag*query(pic[i].x);
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}
