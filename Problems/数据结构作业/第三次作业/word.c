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
void add(char * w) w Ϊ�ַ����飬�����˵�ǰҪ����ĵ��� 
{
	node* noww=root;root��main�������Ѿ��½��ã�Ϊһ���սڵ� 
	int i;
	for(i=0;w[i];i++) 
	{
		if(noww->son[w[i]-'a']==NULL) �����һ���ַ���trie������ 
		{
			node* p=(node*)malloc(sizeof(node));�½��ڵ� 
			memset(p,0,sizeof(node));
			noww->son[w[i]-'a']=p;
		}
		ǰ������Ӧ�ڵ㣬ǰ��Ĵ����Ѿ���֤����һ���ڵ���trie�бض����� 
		noww=noww->son[w[i]-'a'];
		if(w[i+1]=='\0')�����ǰ�ַ��Ѿ��ǵ��ʵĽ�β��������ִ���cnt++�� 
			noww->cnt++;
	}
}
void dfs(node* u)uΪ��ǰ�ڵ� 
{
	int i;
	if(u->cnt!=0)�����ǰ�ڵ��������ַ������ֹ� 
	{
		for(i=0;i<tot;i++)�����word�����˴Ӹ��ڵ㵽u���ַ� 
			putchar(word[i]);
		printf(" %d\n",u->cnt);
	}	
	for(i=0;i<TYPE;i++)
		if(u->son[i]!=NULL)
		{
			word[tot++]=i+'a';������һ���ڵ㣬����·���ϵ��ַ� 
			dfs(u->son[i]);
			tot--;	ɾ����ǰ·���ַ� 
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
