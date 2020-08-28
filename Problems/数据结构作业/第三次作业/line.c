#include<stdio.h>
#include<string.h>
struct ppp{
	int x1,y1,x2,y2;
	int vztd,cnt; 
} seg[102];
int n;
int dfs(int u)
{
	seg[u].vztd=1;
	int cnt=1,i;
	for(i=1;i<=n;++i)
	{
		if(i==u)	continue;
		if(seg[i].x1==seg[u].x2 && seg[i].y1==seg[u].y2)
		{
			if(seg[i].vztd==1)
			{
				cnt+=seg[i].cnt;
				break;
			}
			cnt+=dfs(i);
			break;
		}
	}
	seg[u].cnt=cnt;
	return cnt;
}
int main()
{
	scanf("%d",&n);
	int i,ans=0,ansid=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2);
		seg[i].vztd=seg[i].cnt=0;
	}
	for(i=1;i<=n;i++)
	{
		if(seg[i].vztd)	continue;
		int k=dfs(i);
		if(k>ans)
			ans=k,ansid=i;
	}
	printf("%d %d %d",ans,seg[ansid].x1,seg[ansid].y1);
	return 0;
}
