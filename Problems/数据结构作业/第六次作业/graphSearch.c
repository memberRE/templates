#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pic[128][128],n,m;
int vztd[128],queue[2048],l,r,del=99999999;
void dfs(int u)
{
	int i;
	if(vztd[127])	putchar(' ');
	printf("%d",u);
	vztd[127]=1;
	vztd[u]=1;
	for(i=0;i<n;i++)
		if(pic[u][i] && !vztd[i] && i!=del)
			dfs(i);
}
void bfs()
{
	memset(vztd,0,sizeof(vztd));
	queue[r++]=0;
	vztd[0]=1;
	while(l!=r)
	{
		int u=queue[l++],i;
		if(vztd[127])	putchar(' ');
		printf("%d",u);
		vztd[127]=1;
		for(i=0;i<n;i++)
			if(!vztd[i] && pic[u][i] && i!=del)
			{
				vztd[i]=1;
				queue[r++]=i;
			}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		pic[u][v]=1;
		pic[v][u]=1;
	}
	dfs(0);
	putchar('\n');
	bfs();
	putchar('\n');
	memset(vztd,0,sizeof(vztd));
	scanf("%d",&del);
	dfs(0);
	putchar('\n');
	bfs();
	return 0;
}
