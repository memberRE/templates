#include<stdio.h>
#include<string.h>
#define MAX 4096
char map[MAX][25];
int loca[MAX];
int tot,top;
int node[MAX],ls[MAX],rs[MAX],fa[MAX],deep[MAX];
char pic[25];
int main()
{
	FILE *in;
	in=fopen("in.txt","r");
	int n;
	fscanf(in,"%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		fscanf(in,"%s",pic);
		int j,id=-1;
		for(j=top-1;j>=0;j--)
			if(strcmp(map[j],pic)==0)
				id=j;
		if(id==-1)
		{
			strcpy(map[top++],pic);
			id=top-1;
			tot++;
			node[tot]=id;
			loca[id]=tot;
			deep[tot]=1;
			fa[tot]=0;
		}
		fscanf(in,"%s",pic);
		strcpy(map[top++],pic);
		node[++tot]=top-1;
		loca[top-1]=tot;
		ls[loca[id]]=tot;
		deep[tot]=deep[loca[id]]+1;
		fa[tot]=loca[id];
		fscanf(in,"%s",pic);
		if(strcmp(pic,"NULL")!=0)
		{
			strcpy(map[top++],pic);
			node[++tot]=top-1;
			loca[top-1]=tot;
			rs[loca[id]]=tot;
			deep[tot]=deep[loca[id]]+1;
			fa[tot]=loca[id];
		}
	}
	char name[2][25];
	int id0,id1;
	scanf("%s%s",name[0],name[1]);
	int j;
	for(j=top-1;j>=0;j--)
		if(strcmp(name[0],map[j])==0)
			id0=j;
		else if(strcmp(name[1],map[j])==0)
			id1=j;
	if(deep[loca[id0]]==deep[loca[id1]])
	{
		int noww=fa[loca[id0]];
		int anc[128],anctop=0,cntt=0;
		while(noww)
		{
			anc[++anctop]=node[noww];// start from 1
			noww=fa[noww];
		}
		noww=fa[loca[id1]];
		cntt=1;
		while(noww)
		{
			int i;
			for(i=1;i<=anctop;i++)
				if(anc[i]==node[noww])
				{
					printf("%s %s %d\n",map[node[noww]],name[0],i);
					printf("%s %s %d\n",map[node[noww]],name[1],cntt);
					return 0;
				}
			noww=fa[noww];
			cntt++;
		}
	}
	else
	{
		int cha=deep[loca[id0]]-deep[loca[id1]];
		if(cha>0)
			printf("%s %s %d",name[0],name[1],cha);
		else
			printf("%s %s %d",name[1],name[0],-cha);
	}
	return 0;
}
