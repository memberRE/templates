#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TYPE 26
typedef struct trie{
	struct trie * son[TYPE];
	int cnt;
} node;
node * root=NULL;
char a[2005],word[2005];
int tot=0;
void add(char * w) w 为字符数组，保存了当前要插入的单词 
{
	node* noww=root;root在main函数里已经新建好，为一个空节点 
	int i;
	for(i=0;w[i];i++) 
	{
		if(noww->son[w[i]-'a']==NULL) 如果下一个字符在trie不存在 
		{
			node* p=(node*)malloc(sizeof(node));新建节点 
			memset(p,0,sizeof(node));
			noww->son[w[i]-'a']=p;
		}
		前进到相应节点，前面的创建已经保证了下一个节点在trie中必定存在 
		noww=noww->son[w[i]-'a'];
		if(w[i+1]=='\0')如果当前字符已经是单词的结尾，令其出现次数cnt++； 
			noww->cnt++;
	}
}
void dfs(node* u)u为当前节点 
{
	int i;
	if(u->cnt!=0)如果当前节点所代表字符串出现过 
	{
		for(i=0;i<tot;i++)输出，word保存了从根节点到u的字符 
			putchar(word[i]);
		printf(" %d\n",u->cnt);
	}	
	for(i=0;i<TYPE;i++)
		if(u->son[i]!=NULL)
		{
			word[tot++]=i+'a';访问下一个节点，更新路径上的字符 
			dfs(u->son[i]);
			tot--;	删除当前路径字符 
		}
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	root=(node *)malloc(sizeof(node));
	memset(root,0,sizeof(node));
	while(fgets(a,2003,in)!=NULL)
	{
		int cnt=0,i;
		for(i=0;a[i];i++)
		{
			if(a[i]>='A' && a[i]<='Z')
				a[i]+=32;
			if(a[i]>='a' && a[i]<='z')
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
