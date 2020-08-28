#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2048
int head[MAX],to[MAX<<1],nex[MAX<<1],tot,n;
int line[2048],totline;
char map[2048][64],word[64],S[64],T[64];
int s,t,l,r;
int vztd[2048],que[8096],path[2048],d[2048];
int ans[2048],ansline[2048],anstop;
void add(int u,int v)
{
	if(u==-1 || v==-1)
		return;
	tot++;
	to[tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
void spfa()
{
	memset(d,0x3f,sizeof(d));
	memset(path,-1,sizeof(path));
	memset(vztd,0,sizeof(vztd));
	vztd[s]=1;
	que[r++]=s;
	d[s]=0;
	while (l<r)
	{
		int x=que[l],i;
		l++;
		vztd[x]=0;
		for(i=head[x];i!=-1;i=nex[i])
			if(d[x]+1<d[to[i]])
			{
				d[to[i]]=d[x]+1;
				path[to[i]]=x;
				if(!vztd[to[i]])
				{
					vztd[to[i]]=1;
					que[r++]=to[i];
				}
			}
	}
}
void dfs(int u)
{
	ans[anstop]=u;
	anstop++;
	if(path[u]!=-1)
		dfs(path[u]);
}
int findline(int u,int v)
{
	int a1[10],atop=0,lineu=line[u],linev=line[v];
	while(lineu)
	{
		a1[atop++]=lineu%100;
		lineu/=100;
	}
	while(linev)
	{
		int i;
		for(i=0;i<atop;i++)
		{
			if(a1[i]==linev%100)
				return a1[i];
		}
		linev/=100;
	}
	return -1;
}
int main()
{
	FILE *in=fopen("bgstations.txt","r");
	memset(head,-1,sizeof(head));
	fscanf(in,"%d",&totline);
	int i;
	for(i=1;i<=totline;i++)
	{
		int nowline,totstk;
		fscanf(in,"%d%d",&nowline,&totstk);
		int j,last=-1;
		for(j=1;j<=totstk;j++)
		{
			int flag,id;
			fscanf(in,"%s%d",word,&flag);
//			else if(flag==1)
//			{
				int k=1;
				for(k=1;k<=n;k++)
				{
					if(strcmp(map[k],word)==0)
						break;
				}
				id=k;
				if(k==n+1)
				{
					strcpy(map[++n],word);
					line[n]=nowline;
				}
//			}
			add(id,last);
			add(last,id);
			line[id]*=100;
			line[id]+=nowline;
			last=id;
		}
	}
	scanf("\n%s\n%s",S,T);
	for(i=1;i<=n;i++)
	{
		if(strcmp(map[i],S)==0)
			break;
	}
	s=i;
	for(i=1;i<=n;i++)
	{
		if(strcmp(map[i],T)==0)
			break;
	}
	t=i;
	spfa();
	dfs(t);
	int noww=0,nowline=0;
//	printf("%d\n",d[t]);
	for(i=anstop-1;i>=0;i--)
	{
		if(i==anstop-1)
		{
			printf("%s",map[ans[i]]);
		//	noww++;
			nowline=findline(ans[i],ans[i-1]);//has the possibility of re
		}
		else
		{
			int k=findline(ans[i],ans[i+1]);
			if(k!=nowline)
			{
				printf("-%d(%d)-%s",nowline,noww,map[ans[i+1]]);
				noww=0;
				nowline=k;
			}
			noww++;
		}
	}
	if(nowline==findline(ans[0],ans[1]))
		printf("-%d(%d)-%s",nowline,noww,map[ans[0]]);
	return 0;
}
