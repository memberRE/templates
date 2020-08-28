#include<stdio.h>
#include<string.h> 
#define MAX 2048
int ls[MAX],rs[MAX],node[MAX];
int n,tot=1,root;
void insert(int noww,int k)
{
	if(node[noww]>k)
	{
		if(ls[noww]==0)
		{
			tot++;
			ls[noww]=tot;
			node[tot]=k;
			return ;
		}
		insert(ls[noww],k);
	}
	else
	{
		if(rs[noww]==0)
		{
			tot++;
			rs[noww]=tot;
			node[tot]=k;
			return ;
		}
		insert(rs[noww],k);
	}
}
void dfs(int u,int dp)
{
	if(ls[u]==0 && rs[u]==0)
		printf("%d %d\n",node[u],dp);
	else
	{
		if(ls[u])
			dfs(ls[u],dp+1);
		if(rs[u])
			dfs(rs[u],dp+1);
	}
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(root==0)
		{
			node[1]=k;
			root=1;
		}
		else
			insert(root,k);
	}
	dfs(root,1);
	return 0;
}
