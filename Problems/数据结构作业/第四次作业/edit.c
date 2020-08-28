#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ppp{
	char date;
	struct ppp * nex;
}node;
char stk[320][514];
int top;
int stkpos[320];
char s[550];
node* root=NULL;
node* endd=NULL;
node* temroot=NULL;
node* temendd=NULL;
void creat(char t[])
{
	int i;
	temroot=NULL;
	temendd=NULL;
	for(i=0;t[i];i++)
	{
		node * p=(node*)malloc(sizeof(node));
		p->date=t[i];
		p->nex=NULL;
		if(temroot==NULL)
			temroot=temendd=p;
		else
		{
			temendd->nex=p;
			temendd=temendd->nex;
		}
	}
}
void _insert(int pos)
{
	if(pos==0)
	{
		temendd->nex=root;//考虑当整个串为空的时候 
		root=temroot;
		if(endd==NULL)
			endd=temendd;
		return ;
	}
	int i=0;
	node* noww=root;
	for(i=1;i<pos;i++)
		noww=noww->nex;
	if(noww==NULL)	return ;
	temendd->nex=noww->nex;
	noww->nex=temroot;
}
void _erase(int pos,int num,int flag)
{
	node* noww=root;
	if(num==0)	return ;//暂时不把删除0个字符视为一个操作 
	if(pos==0)
	{
		int i=0;
		if(flag)	stk[top][i]=noww->date;
		for(i=1;i<num;i++)
		{
			noww=noww->nex;
			if(noww==NULL)
				break;
			if(flag)	stk[top][i]=noww->date;
		}
		if(flag)	stk[top][i]='\0';
		if(flag)	top++;
		if(noww==NULL)//懒得free了
			root=NULL;
		else
			root=noww->nex;
		if(root==NULL)
			endd=NULL; 
		return ;
	}
	else
	{
		int i=0;
		for(i=1;i<pos;i++)
			noww=noww->nex;
		node* temdive=noww;
		for(i=0;i<num;i++)
		{
			node* las=noww->nex;
			if(las==NULL)	break;
			if(i>0)
				free(noww);
			noww=las;
			if(flag)	stk[top][i]=noww->date;
		}
		if(flag)	stk[top][i]='\0';
		if(flag)	top++;
		if(noww->nex==NULL)
			endd=temdive;
		temdive->nex=noww->nex;
	}
}
void print()
{
	node* noww=root;
	while(noww!=NULL)
	{
		putchar(noww->date);
		noww=noww->nex;
	}
	putchar('\n');
}
void ddfs(node* u)
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
	gets(s);
	creat(s);
	root=temroot;endd=temendd;
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int op,pos;
		scanf("%d%d%s",&op,&pos,stk[top]);
		stkpos[top]=pos;
		if(op==1)	stkpos[top]+=1000000;
		top++;
	}
	getchar();
	while(1)
	{
		int op,pos;
		scanf("%d",&op);
		if(op==-1)
			break;
		if(op==1)
		{
			scanf("%d%s",&pos,stk[top++]);
			stkpos[top-1]=pos+1000000;
			creat(stk[top-1]);
			_insert(pos);
		}
		else if(op==2)
		{
			int pos,num;
			scanf("%d%d",&pos,&num);
			if(num!=0)	stkpos[top]=pos;
			_erase(pos,num,1);
		}
		else if(op==3)
		{
			if(top)
			{
				top--;
				if(stkpos[top]>=1000000)
					_erase(stkpos[top]-1000000,strlen(stk[top]),0);
				else
				{
					creat(stk[top]);
					_insert(stkpos[top]);
				}
			}
		}
	}
	print();
	return 0;
}
