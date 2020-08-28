#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ppp
{
	int x,y,w,id;
}PIC;
PIC pic[100006];
int p[100005],n,m;
long long ans=0;
int path[100005],top;
int cam(const void *a,const void *b)
{
	return (*((PIC*)a)).w-(*((PIC*)b)).w;
}
int cam2(const void *a,const void *b)
{
	return (*((int*)a))-(*((int*)b));
}
int find(int x)
{
	if(p[x]==x) return x;
	else
	{
		p[x]=find(p[x]);
		return find(p[x]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<m;i++)
		scanf("%d%d%d%d",&pic[i].id,&pic[i].x,&pic[i].y,&pic[i].w);
	for(i=0;i<=n;++i)
		p[i]=i;
	qsort(pic,m,sizeof(PIC),cam);
	for(i=0; i<m; i++)
	{
		int aa=find(pic[i].x),bb=find(pic[i].y);
		if(aa!=bb)
		{
			ans+=pic[i].w;
			path[top++]=pic[i].id;
			p[aa]=bb;
		}
	}
	printf("%lld\n",ans);
	qsort(path,top,sizeof(int),cam2);
	for(i=0;i<top;++i)
		printf("%d ",path[i]);
	return 0;
}
