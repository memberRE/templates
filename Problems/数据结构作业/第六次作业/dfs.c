#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ppp{
	int u,v,w;
}PIC;
PIC pic[2048];
int edge[2048],head[2048],nex[2048],to[2048];
int word[2048],vztd[2048];
int n,m,tot,top;
int cam(const void *a,const void *b)
{
	return (*((PIC*)b)).w-(*((PIC*)a)).w;
}
void add(int u,int v,int w)
{
	edge[++tot]=w;
	nex[tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int u)
{
	vztd[u]=1;
	int i;
	if(u==n-1)
	{
		for(i=0;i<top;i++)
			printf("%d ",word[i]);
		putchar('\n');
		return ;
	}
	for(i=head[u];i!=-1;i=nex[i])
	{
		int v=to[i];
		if(!vztd[v])
		{
			word[top++]=edge[i];
			dfs(v);
			top--;
			vztd[v]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&pic[i].w,&pic[i].u,&pic[i].v);
	qsort(pic+1,m,sizeof(PIC),cam);
	memset(head,-1,sizeof(head));
	for(i=1;i<=m;i++)
	{
		add(pic[i].u,pic[i].v,pic[i].w);
		add(pic[i].v,pic[i].u,pic[i].w);
	}
	dfs(0);
	return 0;
}
