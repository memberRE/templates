#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int TYPE=26;
typedef struct ppp{
	struct ppp* son[TYPE];
	int cnt;
} node;
node * root=(node *)malloc(sizeof(node));
char a[2005],word[2005];
int tot=0;
void add(char * w)
{
	node* noww=root;
	int i;
	for(i=0;w[i];i++)
	{
		if(noww->son[w[i]-'a']==NULL)
		{
			node* p=(node*)malloc(sizeof(node));
			memset(p,0,sizeof(node));
			noww->son[w[i]-'a']=p;
		}
		noww=noww->son[w[i]-'a'];
		if(w[i+1]=='\0')
			noww->cnt++;
	}
}
void dfs(node* u)
{
	int i;
	if(u->cnt!=0)
	{
		for(i=0;i<tot;i++)
			putchar(word[i]);
		printf(" %d\n",u->cnt);
	}	
	for(i=0;i<TYPE;i++)
		if(u->son[i]!=NULL)
		{
			word[tot++]=i+'a';
			dfs(u->son[i]);
			tot--;
		}
			
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	memset(root,0,sizeof(node));
	while(fgets(a,2003,in)!=NULL)
	{
		int cnt=0,i;
		for(i=0;a[i];i++)
		{
			if(a[i]>='A' && a[i]<='Z')
				a[i]+=32;
			if(a[i]>='a' and a[i]<='z')
				word[cnt++]=a[i];
			else 
			{
				word[cnt]='\0';
				add(word);
				cnt=0;
			}
		}
	}
	dfs(root);
	return 0;
}
