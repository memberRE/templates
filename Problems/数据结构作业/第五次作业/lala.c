#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(a,b) (a^=b,b^=a,a^=b)
typedef struct ppp{
	int cnt;
	int asc;
}tree;
int pic[512];
tree node[2048];
int ls[2048],rs[2048],forest[2048];
int top,tmpp[300];
int map[300][300];
int len[300];
int cam(const void *a,const void *b)
{
	int * id1=(int*)a,*id2=(int*)b;
	if(node[*id1].cnt==node[*id2].cnt)
		return node[*id1].asc-node[*id2].asc;
	else
		return node[*id1].cnt-node[*id2].cnt;
}
void dfs(int noww,int dp)
{
	if(node[noww].asc>=0)
	{
		//memcpy(map[node[noww].asc],tmpp,dp);
		int i;
		for( i=0;i<dp;i++)
		{
			map[node[noww].asc][i]=tmpp[i];
		}
	//	putchar('\n');
	//	system("pause");
		len[node[noww].asc]=dp;
		return;
	}
	tmpp[dp]=0;
	dfs(ls[noww],dp+1);
	tmpp[dp]=1;
	dfs(rs[noww],dp+1);
}
int main()
{
	FILE *in;
	in=fopen("input.txt","r");
	pic[0]=1;
	while(1)
	{
		int tem=fgetc(in);
		if(tem=='\n')	continue;
		if(tem==EOF)	break;
		pic[tem]++;
	}
	int i;
	for(i=0;i<=300;i++)
	{
		if(pic[i])
		{
			top++;
			node[top].cnt=pic[i];
			node[top].asc=i;
			forest[top]=top;
		}
	}
	qsort(forest+1,top,sizeof(int),cam);
	int pre=1,endd=top;
	for(;pre!=endd;)
	{
		int id1=forest[pre++];
		int id2=forest[pre++];
		node[++top].cnt=node[id1].cnt+node[id2].cnt;
		node[top].asc=-1;
		ls[top]=id1;rs[top]=id2;
		int i=endd;
		endd++;
		forest[endd]=top;
		for(;i>=pre;i--)
		{
			if(node[forest[i]].cnt>node[forest[i+1]].cnt)
				swap(forest[i],forest[i+1]);
			else
				break;
		}
	}
	dfs(forest[pre],0);
	fclose(in);
	in=fopen("input.txt","r");
	FILE * out=fopen("output.txt","w");
	int sign=0,cntt=0;
	while(1)
	{
		int tem=fgetc(in),flag=0;
		if(tem=='\n')	continue;
		if(tem==EOF)	
		{
			tem=0;
			flag=1;
		}
		int i;
		for(i=0;i<len[tem];i++)
		{
			sign<<=1;
			cntt++;
			sign|=map[tem][i];
			if(cntt==8)
			{
				fputc(sign,out);
				printf("%x",sign);
				sign=cntt=0;
			}
		}
		if(flag)	break;
	}
	if(cntt!=0)
	{
		for(;cntt<=8;)
		{
			cntt++;
			sign<<=1;
			if(cntt==8)
			{
				fputc(sign,out);
				printf("%x",sign);
			}
		}
	}
	putchar('\n');
	fclose(in);
	fclose(out);
	return 0;
}
