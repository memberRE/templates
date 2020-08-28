#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TYPE 26
#define MAXN 50005
#define MAXW 1302
typedef struct ppp{
	int data;
	struct ppp* nex;
} list;
typedef struct trie{
	struct trie * son[TYPE];
	int cnt; 
	list *rot;
} node;
typedef struct pppp{
	int v,id;
}wod;
node * root[2]={NULL,NULL};//root0=dir; root1=err;
char word[MAXW];
char ans[MAXN][MAXW];//对应字符串
list* anspos[MAXN];//出现位置 
wod ansort[MAXN];//按照频率排序的数组
int tot=0,idcnt=0;
FILE *in,*out;
node* add(char * w,int f)
{
	node * noww=root[f];
	int i;
	for(i=0;w[i]!='\n' && w[i]!='\0' && w[i]!='\r';++i)
	{
		if(w[i]<'a' || w[i]>'z')	continue;
		if(noww->son[w[i]-'a']==NULL)
		{
			node* p=(node*)malloc(sizeof(node));
			memset(p,0,sizeof(node));
			noww->son[w[i]-'a']=p;
		}
		noww=noww->son[w[i]-'a'];
		if(w[i+1]=='\0' || w[i+1]=='\n' || w[i+1]=='\r')
		{
			noww->cnt++;
			return noww;
		}
	}
	return NULL;
}
int findd(char * w)
{
	node * noww=root[0];
	int i;
	for(i=0;w[i];++i)
		if(noww->son[w[i]-'a']==NULL)
			return 0;
		else if(w[i+1]=='\0' && noww->son[w[i]-'a']->cnt==0)
			return 0;
		else
			noww=noww->son[w[i]-'a'];
	return 1;
}
void dfs(node * u)
{
	int i;
	if(u->cnt!=0)
	{
		word[tot]='\0';
	//	puts(word);
		ansort[idcnt].id=idcnt;
		ansort[idcnt].v=u->cnt;
		anspos[idcnt]=u->rot;
		strcpy(ans[idcnt],word);
		idcnt++;
	}
	for(i=0;i<TYPE;++i)
		if(u->son[i]!=NULL)
		{
			word[tot++]=i+'a';
			dfs(u->son[i]);
			tot--;
		}
}
int cam(const void * a,const void * b)
{
	if(((wod*)a)->v!=((wod*)b)->v)
		return -(((wod*)a)->v - ((wod*)b)->v);
	else
		return strcmp(ans[((wod*)a)->id],ans[((wod*)b)->id]);
}
void print(list * u)
{
	if(u->nex!=NULL)
		print(u->nex);
	fprintf(out," %d",u->data);
}
int main()
{
	root[0]=(node*)malloc(sizeof(node));
	memset(root[0],0,sizeof(node));
	root[1]=(node*)malloc(sizeof(node));
	memset(root[1],0,sizeof(node));
	in=fopen("dictionary.txt","r");
	out=fopen("misspelling.txt","w");
	
	while(fgets(word,1024,in)!=NULL)
		add(word,0);
	fclose(in);
	
	in=fopen("article.txt","r");
	int tem,cnt=0,flag=0,summ=0;
	while(1)
	{
		if(flag) break;
		tem=fgetc(in);
		if(tem==EOF)
		{
			tem=' ';
			flag=1;
		}
		if(tem!='\r')
			summ++;
		else
			continue;
		if(tem>='A' && tem<='Z')
			tem+=32;
		if(tem>='a' && tem<='z')
			word[cnt++]=tem;
		else
		{
			word[cnt]='\0';
			if(cnt==0)	continue;
			node* noww;
			if(!findd(word))
			{
				noww=add(word,1);
				if(noww!=NULL)
				{
					list* p=(list *)malloc(sizeof(list));
					p->data=summ-cnt-1;
					p->nex=noww->rot;
					noww->rot=p;
				}
			//	puts(word);
			//	system("pause");
			}
			cnt=0;
		}
	}
	dfs(root[1]);
	qsort(ansort,idcnt,sizeof(wod),cam);
	int jkl;
	for(jkl=0;jkl<idcnt;++jkl)
	{
		int k=ansort[jkl].id;
		fprintf(out,"%s %d",ans[k],ansort[jkl].v);
		print(anspos[k]);
		if(jkl+1!=idcnt)
		fputc('\r',out);
		fputc('\n',out);
	}
	fclose(in);
	fclose(out);
	return 0;
}
