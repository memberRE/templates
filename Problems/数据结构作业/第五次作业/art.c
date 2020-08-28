#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 64
char word[MAX];
char node[2048][MAX];
int ls[2048],rs[2048],cnt[2048],tot,top,root;
void insert(int noww,char *w)
{
	if(noww==0)
	{
		tot++;
		strcpy(node[tot],w);
		cnt[tot]=1;
		return ;
	}
	int jkl=strcmp(node[noww],w);
	if(jkl==0)
	{
		cnt[noww]++;
		return ;
	}
	if(jkl>0)
	{
		if(ls[noww]==0)
		{
			tot++;
			ls[noww]=tot;
			strcpy(node[tot],w);
			cnt[tot]=1;
			return ;
		}
		insert(ls[noww],w);
	}
	else
	{
		if(rs[noww]==0)
		{
			tot++;
			rs[noww]=tot;
			strcpy(node[tot],w);
			cnt[tot]=1;
			return ;
		}
		insert(rs[noww],w);
	}
}
void dfs(int noww)
{
	if(noww==0)	return ;
	dfs(ls[noww]);
	printf("%s %d\n",node[noww],cnt[noww]);
	dfs(rs[noww]);
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while(1)
	{
		int c;
		c=fgetc(in);
		if(c==EOF)
			break;
		else
			if(c>='a' && c<='z')
				word[top++]=c;
			else 
			if(c>='A' && c<='Z')
				word[top++]=c+('a'-'A');
			else
			if(top)
			{
				word[top]='\0';
				top=0;
				insert(root,word);
				root=1;
			}
	}
	if(root!=0)
		printf("%s",node[root]);
	if(rs[root]!=0)
		printf(" %s",node[rs[root]]);
	if(rs[rs[root]]!=0)
		printf(" %s",node[rs[rs[root]]]);
	putchar('\n');
	dfs(root);
	return 0;
}
